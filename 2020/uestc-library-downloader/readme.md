# 电子科技大学图书馆馆藏数字化服务平台 图书下载

可用于下载电子科技大学图书馆馆藏数字化服务平台（`222.197.165.70:8181`）上的教材等图书。  
注意，该网站只能在校内网（或通过校内 VPN）访问。

![电子科技大学图书馆馆藏数字化服务平台](pic/uestc_library.png)

## 使用方法

首先打开需要下载的图书的预览页（下用《软件工程——共同演进的方法和实践》作示范）。可在[电子科技大学在线课程资源](http://zxkc.uestc.edu.cn/stuad/index.jsp)找到对应课程的课本。如下为《软件工程——共同演进的方法和实践》的网址链接：

```
http://222.197.165.70:8181/Jpath_sky/DsrPath.do?code=1A2C5AAEA2078E2AE31ECA852EBC5D73&ssnumber=14209619&netuser=1&jpgreadmulu=1&displaystyle=0&channel=0&ipside=0
```

右键获取上图中图书的任意一页的图片地址，样例如下：

```
http://222.197.165.70:8282/png/png.dll?did=a174&pid=A3895A711CD8AC6D85D3BB3A5C775569BB62D344ADD6DE2AB37FB5249B8AC4E0BD29A34952480DB0F122F2B28816EB695CB991CC11FBE6CACF96007CD4020888E8A64306E247CB3A67803377C96908535E18CD028AD2461D4285CFECE9E5003B23A887C64077B337146DF263E02B0A49D4C2&jid=/cov001.jpg&uf=ssr&zoom=0
```

修改 `./config.json`：

```json
{
  "book_name": "软件工程",
  "url_origin": "http://222.197.165.70:8282/png/png.dll?did=a174&pid=A3895A711CD8AC6D85D3BB3A5C775569BB62D344ADD6DE2AB37FB5249B8AC4E0BD29A34952480DB0F122F2B28816EB695CB991CC11FBE6CACF96007CD4020888E8A64306E247CB3A67803377C96908535E18CD028AD2461D4285CFECE9E5003B23A887C64077B337146DF263E02B0A49D4C2&jid=/cov001.jpg&uf=ssr&zoom=0",
  "page_length": [0, 0, 0, 0, 0, 0],

  "HTTP_PROXY": ""
}
```

每一项说明如下：

字段|说明
-|-
`book_name`|书籍名称。将作为保存的文件名
`url_origin`|上述获取的图片链接
`page_length`|每个数字依次代表获取的`封面页、书名页、版权页、前言、目录、正文`的最大页码。当设置为 0 时，程序根据下载内容自行判定最大页码
`HTTP_PROXY`|HTTP 代理

## 注意事项

* 请在校园网环境下使用。如果实在不能保证校园网环境，请自行搭建返校代理，并使用 HTTP 代理。本程序不支持 `vpn1.uestc.edu.cn` 提供的反向代理。
