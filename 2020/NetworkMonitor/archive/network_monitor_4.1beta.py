# -*- coding: utf-8 -*-

from PyQt5.QtWidgets import *  # PyQt5
from PyQt5.QtCore import QThread, pyqtSignal, Qt  # 多线程，以及多线程之间传递信号
from PyQt5.QtChart import QChartView, QChart, QBarSet, QHorizontalBarSeries, QBarCategoryAxis
from network_monitor_no_gui import *
from ui_Main_Window import *  # ui 文件导出的窗体界面
import multiprocessing

SNIFF_INTERVAL = 0.5  # 一次抓包的时间
PLOT_NUMBER = 5  # 一张图上绘制的组数


# 将数据调整为合适的单位
def speed2str(speed):
    unit = ['', 'K', 'M', 'G', 'T']
    _i = 0
    while speed >= 1000:
        speed /= 1024
        _i = _i + 1
    base = pow(1024, _i)
    return unit[_i], base


# 数据统计图 类
class FlowChart(QChart):
    def __init__(self, main_ui):
        super(QChart, self).__init__()
        self.main_ui = main_ui
        # 设置标题
        # self.setTitle('Simple horizontal barchart example')
        # 开启动画效果
        # self.setAnimationOptions(QChart.SeriesAnimations)
        width = self.main_ui.graphics_view.width()
        height = self.main_ui.graphics_view.height()
        self.resize(width, height)


    def draw(self):
        # 通过 UI 单选框的状态判断选项
        if self.main_ui.radio_ip.isChecked():
            plotCategory = 'IP'
        else:
            plotCategory = 'protocol'
        if self.main_ui.radio_packet.isChecked():
            plotUnit = 'packet'
        else:
            plotUnit = 'length'
        # 根据选项调整 sql 查询语法
        sql = '''
        SELECT {0}, upload_{1} AS upload, download_{1} AS download
          FROM network_monitor.{0}_upload_download
         ORDER BY all_{1} DESC
        LIMIT {2};'''
        sql = sql.format(plotCategory, plotUnit, PLOT_NUMBER)
        sql_values = run_sql_with_result(sql)  # 查询结果是 list 里面套 dict
        try:
            sql_values.reverse()  # 如果 except 说明 sql_values 为空
        except:
            self.removeAllSeries()  # 删除掉已经绘制的图像
            return
        if plotUnit == 'length': # 如果按包大小绘图，为了美观，需要调整单位和用于绘图的数据
            max_value = 0
            for i in sql_values:
                for j in ['download', 'upload']:
                    max_value = max(max_value, i[j])
            (unit, base) = speed2str(max_value)
            for i in sql_values:
                for j in ['download', 'upload']:
                    i[j] /= base
            unit_str = '，单位：' + unit + 'B'
        else:
            unit_str = '，单位：包'

        # 每组创建两个柱状条
        set0 = QBarSet('下载' + unit_str)
        set1 = QBarSet('上传' + unit_str)
        for i in range(len(sql_values)): # PyQt 的传入数据的语法，估计是跟 C++ 的 Qt 学的
            set0 << sql_values[i]['download']
            set1 << sql_values[i]['upload']
        # 创建横向柱状条
        series = QHorizontalBarSeries()
        series.append(set0)
        series.append(set1)
        # 添加Series
        self.removeAllSeries()
        self.addSeries(series)
        # 分类
        categories = [x[plotCategory] for x in sql_values]
        # 分类 x 轴，注意 x 轴在横向柱状图中是竖着的轴
        axis = QBarCategoryAxis()
        axis.append(categories)
        # 创建默认轴线
        self.createDefaultAxes()
        # 替换默认y轴
        self.setAxisY(axis, series)
        # 显示图例
        # 显示图例
        self.legend().setVisible(True)
        self.legend().setAlignment(Qt.AlignBottom)

    def update(self):
        # 修改 Chart 大小为外层 graphics_view 大小
        width = self.main_ui.graphics_view.width() - 10
        height = self.main_ui.graphics_view.height() - 10
        # self.main_ui.graphics_view.setSceneRect(self.main_ui.graphics_scene.sceneRect())
        # self.main_ui.graphics_scene.setSceneRect(self.main_ui.graphics_view.sceneRect())
        self.resize(width, height)
        self.draw()


def sniffProcess(q, iface):
    packets = sniff(iface=iface, timeout=SNIFF_INTERVAL)
    packet_length = data_process(packets)
    q.put(packet_length) # 多进程中数据用 multiprocessing.Queue 交互



# 业务核心线程，控制了抓包线程和数据处理线程
class CoreThread(QThread):
    trigger = pyqtSignal(int)

    # 初始化函数
    def __init__(self, main_ui):
        super(CoreThread, self).__init__()
        self.main_ui = main_ui
        self.iface = ''
        self.userIP = ''
        self.sniff_thread = None
        self.data_process_thread = None
        self.plot_thread = None
        self.trigger.connect(self.main_ui.update_plot)

    # 重写线程执行的run函数
    def run(self):
        # 初始化数据库
        # init_database(self.userIP)
        # plt.ion()

        while True:
            # 检测监测网卡是否有变化，如果变化则（重新）初始化数据库
            network_info_str = self.main_ui.combo_interface.currentText()
            network_info = network_info_str.strip('][').replace('\'', '').split(', ')
            if network_info[0] != self.iface:
                self.iface = network_info[0]
                self.userIP = network_info[1]
                init_database(self.userIP)
                queue = multiprocessing.Queue()

            process = multiprocessing.Process(target=sniffProcess, args=(queue, self.iface))
            process.start()
            if ~queue.empty():
                self.trigger.emit(queue.get())
            time.sleep(SNIFF_INTERVAL)

# Qt 的 main_ui
class NetworkMonitorMainUI(QMainWindow, Ui_MainWindow):
    def __init__(self, parent=None):
        super(NetworkMonitorMainUI, self).__init__(parent)
        self.setupUi(self)
        self.chart = FlowChart(self)
        print("hello")
        # 四个单选框的信号与槽，将单击单选框行为和对应函数关联起来
        self.radio_ip.clicked.connect(self.radio_button_ip_click)
        self.radio_protocol.clicked.connect(self.radio_button_protocol_click)
        self.radio_packet.clicked.connect(self.radio_button_packet_click)
        self.radio_length.clicked.connect(self.radio_button_length_click)
        # 设置选择网卡的下拉菜单栏
        for i in get_network_info():
            self.combo_interface.addItem(str(i))

        # 创建核心线程并启动
        self.core_thread = CoreThread(self)
        self.core_thread.start()

        # Qt 的逻辑是 graphics_view 是一个控件
        # graphics_view 套一个 graphics_scene
        # graphics_scene 套一个 widget，如 QChart
        self.graphics_scene = QGraphicsScene()
        # self.graphics_scene.setMinimumRenderSize(3)
        # scene.setSceneRect(self.graphics_view.sceneRect())
        self.graphics_scene.addItem(self.chart)
        self.graphics_view.setScene(self.graphics_scene)


    # 单击对应单选框后触发的四个函数
    def radio_button_ip_click(self):
        self.radio_protocol.setChecked(False)  # 将另外一个按钮置零

    def radio_button_protocol_click(self):
        self.radio_ip.setChecked(False)

    def radio_button_packet_click(self):
        self.radio_length.setChecked(False)

    def radio_button_length_click(self):
        self.radio_packet.setChecked(False)

    def update_plot(self, packet_length):
        # 显示速度

        current_net_speed = packet_length / SNIFF_INTERVAL
        (unit_str, base) = speed2str(current_net_speed)
        current_net_speed /= base
        current_net_speed_str = '当前速度：' + '%.2f' % current_net_speed + unit_str + 'B/s'
        self.netspeed_label.setText(current_net_speed_str)
        # 更新图表

        self.chart.update()


if __name__ == '__main__':
    app = QApplication(sys.argv)
    main_ui = NetworkMonitorMainUI()
    main_ui.show()
    sys.exit(app.exec_())
