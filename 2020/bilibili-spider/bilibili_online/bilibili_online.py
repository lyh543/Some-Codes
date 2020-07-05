#!/usr/bin/python3

import requests
import time

def print(s):
    f = open('./bilibili_online.txt', 'a')
    f.write(s)
    f.close()

interval_sec = 55
# 区编号从左到右依次为 1,11,119,129,13,138,155,160,165,167,17,177,181,188,202,23,3,36,4,5,75,76
while True:
    r = requests.get('https://api.bilibili.com/x/web-interface/online')
    count_dict = r.json()['data']['region_count']
    print (time.strftime("%m.%d,%H:%M,", time.localtime()))
    for v in count_dict.values():
        print('%d,'% v)
    print('\n')
    time.sleep(interval_sec)
