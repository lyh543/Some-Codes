# -*- coding: utf-8 -*-

import time                      # 获取时间
import psutil                    # 获取系统 IP
import pymysql                   # 数据库
from scapy.all import *          # 抓包软件
import warnings                  # 关闭数据库的警告
import matplotlib.pyplot as plt  # 绘图
from matplotlib.figure import Figure
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
import pandas as pd              # 绘图
from ui_Main_Window import *     # ui 文件导出的窗体界面
from PyQt5.QtWidgets import *    # PyQt5
from PyQt5.QtCore import QThread # 多线程
from network_monitor_no_gui import *

# class Figure_Canvas(FigureCanvas):   # 通过继承FigureCanvas类，使得该类既是一个PyQt5的Qwidget，又是一个matplotlib的FigureCanvas，这是连接pyqt5与matplot                                          lib的关键
#
#     def __init__(self, parent=None, width=110, height=50, dpi=100):
#         fig = Figure(figsize=(width, height), dpi=100)  # 创建一个Figure，注意：该Figure为matplotlib下的figure，不是matplotlib.pyplot下面的figure
#
#         FigureCanvas.__init__(self, fig) # 初始化父类
#         self.setParent(parent)
#
#         self.axes = fig.add_subplot(111) # 调用figure下面的add_subplot方法，类似于matplotlib.pyplot下面的subplot方法
#
#     def test(self):
#         x = [1,2,3,4,5,6,7,8,9]
#         y = [23,21,32,13,3,132,13,3,1]
#         self.axes.plot(x, y)
# 核心线程

SNIFF_INTERVAL = 5


class SniffThread(QThread):

    # 初始化函数
    def __init__(self, main_ui, iface, userIP):
        super(SniffThread, self).__init__()
        self.iface = iface
        self.userIP = userIP
        self.main_ui = main_ui

    # 重写线程执行的run函数
    def run(self):
        currentLength = sniff_packet(self.iface, SNIFF_INTERVAL)
        currentNetSpeed = currentLength / SNIFF_INTERVAL

        # 将速度换算为 K、M、G 的形式
        def speed2str(speed):
            unit = ['', 'K', 'M', 'G', 'T']
            i = 0
            while speed >= 1000:
                speed /= 1024
                i = i + 1
            return '当前网速：' + '%.2f'% speed + unit[i] + 'B/s'
        main_ui.NetspeedLabel.setText(speed2str(currentNetSpeed))


class CoreThread(QThread):

    # 初始化函数
    def __init__(self, main_ui):
        super(CoreThread, self).__init__()
        self.main_ui = main_ui

    # 重写线程执行的run函数
    def run(self):
        plt.ion()
        iface = ''
        userIP = ''
        while True:
            # 检测监测网卡是否有变化
            network_info_str = self.main_ui.PopupInterface.currentText()
            network_info = network_info_str.strip('][').replace('\'','').split(', ')
            if network_info[0] != iface:
                init_database(userIP)
                iface = network_info[0]
                userIP = network_info[1]

            self.sniffThread = SniffThread(self.main_ui, iface, userIP)
            self.sniffThread.start()
            time.sleep(SNIFF_INTERVAL)
            # plot_flow_graph('IP', 'length', 5)
            QApplication.processEvents()  # 刷新界面


class NetworkMonitorMainUI(QMainWindow, Ui_MainWindow):
    def __init__(self, parent=None):
        super(NetworkMonitorMainUI, self).__init__(parent)
        self.setupUi(self)
        # 四个单选框的信号与槽，将单击单选框行为和函数关联起来
        self.RadioButtonIP.clicked.connect(self.radio_button_ip_click)
        self.RadioButtonProtocol.clicked.connect(self.radio_button_protocol_click)
        self.RadioButtonPacket.clicked.connect(self.radio_button_packet_click)
        self.RadioButtonLength.clicked.connect(self.radio_button_length_click)
        # 设置选择网卡的下拉菜单栏
        for i in get_network_info():
            self.PopupInterface.addItem(str(i))
        self.core = CoreThread(self)
        self.core.start()
        self.show()
        # scene = QGraphicsScene(self)
        # figure = Figure()
        # axes = figure.gca()
        # axes.set_title("title")
        # # axes.plot(plt.plot([1,2], [1,2]))
        # canvas = FigureCanvas(figure)
        #
        # sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Fixed)
        # sizePolicy.setHorizontalStretch(0)
        # sizePolicy.setVerticalStretch(0)
        # sizePolicy.setHeightForWidth(self.RadioButtonPacket.sizePolicy().hasHeightForWidth())
        # canvas.setSizePolicy(sizePolicy)
        #
        # scene.addWidget(canvas)
        # self.graphicsView.setScene(scene)

    # 单击对应单选框后触发的四个函数
    def radio_button_ip_click(self):
        self.RadioButtonProtocol.setChecked(False)  # 将另外一个按钮置零

    def radio_button_protocol_click(self):
        self.RadioButtonIP.setChecked(False)

    def radio_button_packet_click(self):
        self.RadioButtonLength.setChecked(False)

    def radio_button_length_click(self):
        self.RadioButtonPacket.setChecked(False)


if __name__ == '__main__':
    app = QApplication(sys.argv)
    main_ui = NetworkMonitorMainUI()
    main_ui.show()
    sys.exit(app.exec_())
