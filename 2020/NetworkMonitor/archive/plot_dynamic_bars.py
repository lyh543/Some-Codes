#!/usr/bin/env python
# -*- coding: utf-8 -*-

from PyQt5.QtChart import QChartView, QChart, QBarSet, QHorizontalBarSeries, QBarCategoryAxis
from PyQt5.QtCore import Qt, QTimer
from PyQt5.QtWidgets import *
from PyQt5.QtGui import QPainter
from test import *
from random import random


class Window(QChartView):

    def __init__(self, *args, **kwargs):
        super(Window, self).__init__(*args, **kwargs)
        self.resize(400, 300)
        # 抗锯齿
        self.setRenderHint(QPainter.Antialiasing)

        # 图表
        chart = QChart()
        self.setChart(chart)
        # 设置标题
        chart.setTitle('Simple horizontal barchart example')
        # 开启动画效果
        chart.setAnimationOptions(QChart.SeriesAnimations)
        # 添加Series
        series = self.getSeries()
        chart.addSeries(series)
        # 分类
        categories = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun']
        # 分类x轴
        axis = QBarCategoryAxis()
        axis.append(categories)
        # 创建默认轴线
        chart.createDefaultAxes()
        # 替换默认y轴
        chart.setAxisY(axis, series)
        # 显示图例
        chart.legend().setVisible(True)
        chart.legend().setAlignment(Qt.AlignBottom)

        # self.timer = QTimer(self)
        # self.timer.setInterval(1000)
        # self.timer.timeout.connect(self.update)
        # self.timer.start()

    def getSeries(self):
        # 创建5个柱子
        set0 = QBarSet('Jane')
        set1 = QBarSet('John')
        set2 = QBarSet('Axel')
        set3 = QBarSet('Mary')
        set4 = QBarSet('Samantha')

        # 添加数据
        set0 << 1 << 2 << 3 << 4 << 5 << 6
        set1 << 5 << 0 << 0 << 4 << 0 << 7
        set2 << 3 << 5 << 8 << 13 << 8 << 5
        set3 << 5 << 6 << 7 << 3 << 4 << 5
        set4 << 9 << 7 << 5 << 3 << 1 << 2

        # 创建柱状条
        series = QHorizontalBarSeries()
        series.append(set0)
        series.append(set1)
        series.append(set2)
        series.append(set3)
        series.append(set4)
        return series

    def update(self):
        pass


class MyChart(QChart):
    def __init__(self, main_ui):
        super(QChart, self).__init__()
        self.main_ui = main_ui
        # 设置标题
        # self.setTitle('Simple horizontal barchart example')
        # 开启动画效果
        # self.setAnimationOptions(QChart.SeriesAnimations)

        # width = self.main_ui.graphicsView.width()
        # height = self.main_ui.graphicsView.height()
        #
        # self.resize(width, height)
        self.draw()

        self.timer = QTimer(self)
        self.timer.setInterval(1000)
        self.timer.timeout.connect(self.draw)
        self.timer.start()

    def draw(self):
        # 修改 Chart 大小为外外层 graphicsView 大小
        width = self.main_ui.graphicsView.width() - 5
        height = self.main_ui.graphicsView.height() -5
        self.resize(width, height)

        # 创建5个柱子
        set0 = QBarSet('下载')
        set1 = QBarSet('上传')
        for s in [set0, set1]:
            for i in range(6):
                s << random() * 10
        # 创建柱状条
        series = QHorizontalBarSeries()
        series.append(set0)
        series.append(set1)
        # 添加Series
        self.removeAllSeries()
        self.addSeries(series)
        # 分类
        categories = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun']
        # 分类x轴
        axis = QBarCategoryAxis()
        axis.append(categories)
        # 创建默认轴线
        self.createDefaultAxes()
        # 替换默认y轴
        self.setAxisY(axis, series)
        # 显示图例
        self.legend().setVisible(True)
        self.legend().setAlignment(Qt.AlignBottom)


class main_ui(QMainWindow, Ui_MainWindow):
    def __init__(self, parent=None):
        super(main_ui, self).__init__()
        self.setupUi(self)

        chart = MyChart(self)
        scene = QGraphicsScene()
        scene.setMinimumRenderSize(3)
        # scene.setSceneRect(self.graphicsView.sceneRect())
        scene.addItem(chart)
        self.graphicsView.setScene(scene)


if __name__ == '__main__':
    import sys
    from PyQt5.QtWidgets import QApplication

    app = QApplication(sys.argv)
    w = main_ui()
    w.show()
    sys.exit(app.exec_())
