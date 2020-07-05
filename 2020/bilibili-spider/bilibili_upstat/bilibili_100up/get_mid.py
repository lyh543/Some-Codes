#!/usr/bin/python3

import requests
import time
from lxml import etree

def get_mid(link):
    # link 格式为 //space.bilibili.com/43536?from=search
    # 直接切片就行
    return link[21:-12]


namelist = open('100up_namelist.txt', 'r', encoding='UTF-8')
for username in namelist:
    try:
        username = username.strip()
        r = requests.get(f'https://search.bilibili.com/upuser?keyword={username}&page=1&order=fans&order_sort=0')
        r.encoding = "utf-8"
        html = etree.HTML(r.text)
        result_user = html.xpath('//*[@id="user-list"]/div[1]/ul/li[1]/div[2]/div[1]/a[1]')[0]
        result_link = result_user.xpath('./@href')[0]
        result_mid = get_mid(result_link)
        result_username = str(result_user.xpath('./@title')[0])
        print(result_username, username, result_mid, sep=',')
    except IndexError:
        print(username, 'not fount')
