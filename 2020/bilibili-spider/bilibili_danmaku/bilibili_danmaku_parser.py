import os
from lxml import etree

path = "origin"  # 文件夹目录
files = os.listdir(path)  # 得到文件夹下的所有文件名称
files = filter(lambda x: x.endswith('.xml'), files)
for file in files:  # 遍历文件夹
    tree = etree.parse(path + '/' + file)
    for element in tree.xpath('//i//d'):
        info = element.xpath('./@p')[0].split(',')
        text = element.xpath('./text()')[0]
        print(info, text)
