#!/usr/bin/python3

# 调用参数 bilibili_upstat.py start step

import requests
import base64
import threading
from lxml import etree
import sys
import time


class User:
    mid = 0
    name = ''
    up_video = 0
    up_article = 0
    follower = 0

    def str(self, encode=False):
        _name = self.name
        if encode:
            _bname = base64.b64encode(self.name.encode())
            _name = str(_bname)[2:-1]
        return f'{self.mid},{_name},{self.follower},{self.up_video},{self.up_article}'


# 使用方法
# print(get_user(37663924).str())
# print(get_user(37663924).str(encode=True))
def get_user(i):
    cur_user = User()
    cur_user.mid = i

    r1 = requests.get(f"https://api.bilibili.com/x/relation/stat?vmid={i}")
    if not r1.ok:
        error_log(i, r1.status_code)
        return
    cur_data1 = r1.json()['data']
    cur_user.follower = cur_data1['follower']

    r2 = requests.get(f"https://api.bilibili.com/x/space/navnum?mid={i}")
    if not r2.ok:
        error_log(i, r2.status_code)
        return
    cur_data2 = r2.json()['data']
    cur_user.up_video = cur_data2['video']
    cur_user.up_article = cur_data2['article']

    r3 = requests.get(f"https://space.bilibili.com/{i}/video")
    if not r3.ok:
        error_log(i, r3.status_code)
        return
    html3 = etree.HTML(r3.content)
    cur_user.name = html3.xpath("/html/head/title/text()")[0][0:-35]

    return cur_user


def error_log(i, status_code):
    print(f'{i} {status_code}')
    with open('error_uid.txt','a') as error_file:
        error_file.write(f'{i} {status_code}\n')


def run():
    filename = f'data/bilibili_upstat_100up.txt'
    f = open(filename, 'a', encoding='utf-8')
    namelist = open('./bilibili-100up/100up_info.txt', encoding='utf-8')
    for lines in namelist:
        info = lines.strip().split(',')
        if len(info) < 3: # XX not found
            continue
        cur_user = get_user(int(info[2]))
        time.sleep(0.5)
        if cur_user is None:
            continue
        f.write(cur_user.str(encode=True)+'\n')
        f.flush()

run()