# Arduino 开发例程
CH55x Arduino来自作者DeqingSun [ch55xduino](https://github.com/DeqingSun/ch55xduino)

> 附加开发板管理器网址
```
DeqingSun: https://raw.githubusercontent.com/DeqingSun/ch55xduino/ch55xduino/package_ch55xduino_mcs51_index.json
WeActStudio: https://raw.githubusercontent.com/WeActTC/ch55xduino/ch55xduino/package_ch55xduino_mcs51_index.json
```

## 安装环境
1. 打开Arduino IDE，点击`文件`-> `首选项`，在`附加开发板管理器网址`填入上面的网址，选择其中一个即可
2. 点击`工具`->`开发板:xxx`->`开发板管理器`
3. 搜索`ch552`
4. 找到`CH55xDuino MCS51 plain C core (non-C++)`，点击安装
> 如果下载缓慢，或者打不开`开发板管理器`，可将步骤1中的网址改为
`http://duino.weact-tc.cn/ch55xduino/package_ch55xduino_mcs51_index.json`

## 烧录驱动程序安装方法
> Arduino 支持免按键烧录，驱动程序需要使用libusb，不能使用WCH官方驱动
1. P36,P37管脚为烧录专用管脚，不可用于I/O
2. 如果设备管理存在`USB Module`设备，需在设备管理器中卸载（同时勾选删除驱动程序）`USB Module`设备
3. 打开Tools/bootloaderWebtool目录，双击`zadig.exe`，点击`Install WCID Driver`,等待驱动安装完成，即可
4. 如果设备无法自动进入烧录模式，可以按住P36键，重新拔插USB即可
5. 如果需要还原官方驱动程序，只需卸载libusb驱动，运行WCHISPTool目录的WCHISPDRV，重新安装驱动程序即可

## 例程说明
1. 01-Blink 为P30 LED闪烁
2. 02-PWMFading 为P30 LED呼吸
