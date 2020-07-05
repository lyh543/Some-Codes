#!/usr/bin/python3

import requests
import threading
from lxml import etree
import sys
import time

interval = 59


def get_watching_number():
    date_time_str = time.strftime("%m.%d,%H:%M", time.localtime())
    r = requests.get('https://www.bilibili.com/online.html')
    if not r.ok:
        error_log(date_time_str, r.status_code)
        return
    html = etree.HTML(r.content)
    sum = 0
    for i in range(0,20):
        num = html.xpath('//*[@id="app"]/div/div[2]/div')[i].xpath('./p/b/text()')[0]
        sum += int(num)
    with open('bilibili_watching.txt', 'a') as file:
        file.write(f'{date_time_str},{sum}\n')
        #print(f'{date_time_str},{sum}')


def error_log(i, status_code):
    print(f'{i} {status_code}')
    with open('error_time.txt','a') as error_file:
        error_file.write(f'{i} {status_code}\n')


class SpiderThread (threading.Thread):
    def run(self):
        get_watching_number()


if __name__ == '__main__':

    spider_thread = SpiderThread()
    while True:
        spider_thread.start()
        time.sleep(interval)
        spider_thread = SpiderThread()

