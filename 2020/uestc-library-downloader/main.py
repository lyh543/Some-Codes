import json
import sys
import requests
import os
import img2pdf

CONFIG_FILE = './config.json'
OUTPUT_ROOT_DIRECTORY = './output_textbooks'
PAGE_TYPE = [ # 不同种图片的链接不同
    ['封面页', 'cov', 0],
    ['书名页', 'bok', 0],
    ['版权页', 'leg', 0],
    ['前言', 'fow', 0],
    ['目录', '!', 0],
    ['正文', '', 0]
]

# 读取 config.json
with open(CONFIG_FILE, encoding='utf-8') as f:
    config = json.load(f)

# 获取页码数，也可以自动获取
for i in range(len(PAGE_TYPE)):
    if config['page_length'][i] == 0:
        PAGE_TYPE[i][2] = sys.maxsize
    else:
        PAGE_TYPE[i][2] = config['page_length'][i]

# 配置文件路径、下载链接、代理
OUTPUT_DIR = OUTPUT_ROOT_DIRECTORY + '/' + config['book_name']
PDF_PATH = OUTPUT_DIR + '/' + config['book_name'] + '.pdf'
PIC_DIR = OUTPUT_DIR + '/pic'
os.makedirs(OUTPUT_DIR, exist_ok=True)
os.makedirs(PIC_DIR, exist_ok=True)
slice_n = config['url_origin'].find('&jid=/')
url_list = [config['url_origin'][0:slice_n + 5], config['url_origin'][slice_n + 12:]] # 去掉页码 cov001 的部分
PIC_FORMAT = url_list[1].split('&')[0][1:] # jpg 或 png 等
proxies = {
    'http': config['HTTP_PROXY'],
    'https': config['HTTP_PROXY']
}

# 下载 jpg
pic_path_list = []
for type_i in range(len(PAGE_TYPE)):
    (type_name, type_str, type_length) = PAGE_TYPE[type_i]
    print('开始下载' + type_name + '……')
    for i in range(1, type_length):
        pic_name = type_str + str(i).zfill(6 - len(type_str)) # 组成 cov001
        pic_full_path = PIC_DIR + '/' + pic_name + '.' + PIC_FORMAT
        pic_path_list.append(pic_full_path)
        url = url_list[0] + pic_name + url_list[1]
        if os.path.exists(pic_full_path):
            print(pic_name + ' 文件已存在')
            continue
        else:
            response = requests.get(url, proxies=proxies)
            if not response.ok:
                print(pic_name + ' ' + response.status_code)
                os.system('pause')
            elif len(response.content) < 1024: # 图书馆如果页码不存在，也会响应 HTTP 200，并返回一个 142 Bytes 的 content
                print(pic_name + ' 超出页码范围')
                pic_path_list.remove(pic_full_path)
                PAGE_TYPE[type_i][2] = i - 1 # 设置页码数，合并 pdf 时用
                break
            else:
                with open(pic_full_path, 'wb') as f:
                    f.write(response.content) # 写入图片
                print(pic_name +  ' 下载成功')

# 将图片合成为 pdf
print('开始生成 PDF……')
with open(PDF_PATH, "wb+") as f: # w+ 直接覆盖
    layout_fun = img2pdf.get_fixed_dpi_layout_fun((300, 300)) # 固定 DPI，避免封面、正文 DPI 不同导致尺寸不同
    f.write(img2pdf.convert(pic_path_list, layout_fun=layout_fun))

# 为 PDF 添加简单的书签
# from PyPDF2 import PdfFileReader, PdfFileWriter
# def _get_parent_bookmark(current_indent, history_indent, bookmarks):
#     '''The parent of A is the nearest bookmark whose indent is smaller than A's
#     '''
#     assert len(history_indent) == len(bookmarks)
#     if current_indent == 0:
#         return None
#     for i in range(len(history_indent) - 1, -1, -1):
#         # len(history_indent) - 1   ===>   0
#         if history_indent[i] < current_indent:
#             return bookmarks[i]
#     return None
#
# def addBookmark(pdf_path, bookmark_txt_path, page_offset):
#     if not exists(pdf_path):
#         return "Error: No such file: {}".format(pdf_path)
#     if not exists(bookmark_txt_path):
#         return "Error: No such file: {}".format(bookmark_txt_path)
#
#     with open(bookmark_txt_path, 'r',encoding='utf-8') as f:
#         bookmark_lines = f.readlines()
#     reader = PdfFileReader(pdf_path)
#     writer = PdfFileWriter()
#     writer.cloneDocumentFromReader(reader)
#
#     maxPages = reader.getNumPages()
#     bookmarks, history_indent = [], []
#     # decide the level of each bookmark according to the relative indent size in each line
#     #   no indent:          level 1
#     #     small indent:     level 2
#     #       larger indent:  level 3
#     #   ...
#     #排除特殊符号
#     #保留字母、数字、中文、中文括号，其他自定义需要保留的可以自行添加到此处
#     rule = re.compile(r"[^a-zA-Z0-9（）【】\u4e00-\u9fa5]")
#     for line in bookmark_lines:
#         line2 = rule.sub(' ',line)
#         line2 = re.split(r'\s+', unicode(line2.strip(), 'utf-8')) if is_python2 else re.split(r'\s+', line2.strip())
#         if len(line2) == 1:
#             continue
#
#         indent_size = len(line) - len(line.lstrip())
#         parent = _get_parent_bookmark(indent_size, history_indent, bookmarks)
#         history_indent.append(indent_size)
#
#         title, page = ' '.join(line2[:-1]), int(line2[-1]) - 1
#         if page + page_offset >= maxPages:
#             return "Error: page index out of range: %d >= %d" % (page + page_offset, maxPages)
#         new_bookmark = writer.addBookmark(title, page + page_offset, parent=parent)
#         bookmarks.append(new_bookmark)
#
#     out_path = splitext(pdf_path)[0] + '-new.pdf'
#     with open(out_path,'wb') as f:
#         writer.write(f)
#
#     return "The bookmarks have been added to %s" % pdf_path
#
# if __name__ == "__main__":
#     import sys
#     args = sys.argv
#     if len(args) != 4:
#         print("Usage: %s [pdf] [bookmark_txt] [page_offset]" % args[0])
#     print(addBookmark(pdfPath,contentStructPath, offset))
# ''''
