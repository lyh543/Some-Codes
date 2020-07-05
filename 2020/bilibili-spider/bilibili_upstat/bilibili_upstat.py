#!/usr/bin/python3

# 调用参数 bilibili_upstat.py start step

import requests
import base64
import threading
from lxml import etree
import sys

start = 200744
end = 300000
step = 1
thread_n = 1


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

# 使用方法：run(1,max_user)
def run(start, end, step=1):
    filename = f'data/bilibili_upstat_{start}.txt'
    cnt = 0
    loop = 1
    f = open(filename, 'a')
    for i in range(start, end, step):
        cur_user = get_user(i)
        if cur_user is None:
            continue
        f.write(cur_user.str(encode=True)+'\n')
        cnt += 1
        if cnt >= loop: # 间隔一定时间写入一次数据
            f.flush()
            cnt = 0


class SpiderThread (threading.Thread):
    def __init__(self, i, end, step=1):
        threading.Thread.__init__(self)
        self.i = i
        self.end = end
        self.step = step

    def run(self):
        run(self.i, self.end, self.step)

if __name__ == '__main__':
    # if len(sys.argv) >= 3:
    #     start = int(sys.argv[1])
    #     step = int(sys.argv[2])

    # run(start, end, step)
    thread_list = []
    for i in range(1, thread_n + 1):
        spider_thread = SpiderThread(start, end, thread_n)
        spider_thread.start()
        thread_list.append(spider_thread)
    for spider_thread in thread_list:
        spider_thread.join()

