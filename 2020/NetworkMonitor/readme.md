# 网络流量分析软件

一款网络流量统计软件，使用 scapy 作为抓包库、Qt 为 GUI 库。

理论上支持 Linux、Windows、Mac OS，但由于 scapy 对 Windows 支持较差，未在 Mac OS 上测试过，推荐在 Linux 上运行。

![运行截图](https://lyh543.coding.net/p/pic-bed/d/pic-bed/git/raw/master/349ddd1a81f359e4a49f1ceb6764ce9dad442a6de477e536407b2a65762d9555.png)  


## 使用

### Windows

1. Windows 下需要先安装 Npcap。
   - 如安装了 WinPcap，需先卸载 WinPcap，并删除残留文件 `C:/Windows/SysWOW64/wpcap.dll` 和 `C:/Windows/SysWOW64/Packet.dll`，详见 https://scapy.readthedocs.io/en/latest/installation.html#winpcap-npcap-conflicts

2. 安装 Python3，安装时勾选 Python-tk。

![安装时勾选 Python-tk](https://lyh543.coding.net/p/pic-bed/d/pic-bed/git/raw/master/34395ffb47c5c9caa55babe0a3619c6ea2688383d68f78f5949e2a652763933a.png)  

3. 安装所需 Python 包：

```sh
python -m pip install scapy pymysql matplotlib PyQt5 pyqtchart  DBUtils psutil pyqtchart
```

4. 安装并配置 MySQL，此处略，在本地、Docker、云服务器安装均可

5. 修改 `db.py` 前几行的 MySQL 服务器信息

6. 运行程序：

```sh
python network_monitor.py
```

### Linux

1. 安装 Python3

2. 安装 `python3-dev` 和 `psutil`

```sh
sudo apt-get install python3-dev psutil 
```

3. 安装所需 Python 包：

```sh
sudo python3 -m pip install scapy pymysql matplotlib PyQt5 pyqtchart  DBUtils
```

4. 安装并配置 MySQL，在本地、Docker、云服务器安装均可。

5. 修改 `db.py` 前几行的 MySQL 服务器信息

6. 运行程序：

```sh
# Linux 下使用 scapy 抓包需要 su 权限
sudo python3 network_monitor.py
```

## 测试环境

* Deepin 20 Beta 下测试成功。

## 已知问题

* scapy 可能不能在 Windows 上监听 Wifi 流量，这是因为 Windows 内核不支持某些无线适配器。详见：https://www.winpcap.org/misc/faq.htm#Q-16
* 本程序也可能不能在其他设备上监听 Wifi 流量，仅支持 Ethernet，因为作者没有设备用于测试。
* 即使所有都正确配置了，scapy 可能仍无法在 Windows 上正确运行。对此，官方推荐改用 Linux Live CD 进行测试。详见：https://scapy.readthedocs.io/en/latest/installation.html#windows

> If really nothing seems to work, consider skipping the Windows version and using Scapy from a Linux Live CD – either in a virtual machine on your Windows host or by booting from CDROM.

* scapy 在流量负载较大时会出现漏包的现象，详见：https://linux.die.net/man/1/scapy

