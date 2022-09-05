# Arduino 开发例程
CH55x Arduino来自作者DeqingSun [ch55xduino](https://github.com/DeqingSun/ch55xduino)

> 附加开发板管理器网址
```
DeqingSun: https://raw.githubusercontent.com/DeqingSun/ch55xduino/ch55xduino/package_ch55xduino_mcs51_index.json
WeActStudio: https://raw.githubusercontent.com/WeActTC/ch55xduino/ch55xduino/package_ch55xduino_mcs51_index.json
```

## 开发环境搭建
1. 打开Arduino IDE，点击`文件`-> `首选项`，在`附加开发板管理器网址`填入上面的网址，选择其中一个即可
2. 点击`工具`->`开发板:xxx`->`开发板管理器`
3. 搜索`ch552`
4. 找到`CH55xDuino MCS51 plain C core (non-C++)`，点击安装
> 如果下载缓慢，或者打不开`开发板管理器`，可将步骤1中的网址改为
`http://duino.weact-tc.cn/ch55xduino/package_ch55xduino_mcs51_index.json`

## 烧录驱动程序安装方法&&注意事项
> Arduino 支持免按键烧录，驱动程序可以使用libusb，也可以使用WCH官方驱动，推荐用WCH官方驱动。
1. P36,P37管脚为烧录专用管脚，不可用于I/O
2. 下面是两种驱动的安装方法
* 使用`WCH官方驱动`进行烧录，打开Tools/WCH_Bootloader_Driver/目录，选择`SETUP.EXE`，右键`以管理员身份运行`，点击`安装`即可，安装完后，按住P36，在连接电脑后松开按键，设备管理器出现`USB Module`设备（位于`外部接口`或者`Interface`目录下）即说明驱动安装成功，驱动仅在Win10/Win11平台做了测试
* 使用`libusb驱动`进行烧录，打开Tools/bootloaderWebtool目录，双击`zadig.exe`，点击`Install WCID Driver`,等待驱动安装完成即可，如果设备管理存在`USB Module`设备，需在设备管理器中卸载（同时勾选删除驱动程序）`USB Module`设备，然后重新安装驱动
3. 如果设备无法自动进入烧录模式，可以先任意选择一个可以打开的串口，按住P36键，重新拔插USB，点击下载按钮下载，之后选择核心板串口即可实现自动下载。
4. 如果需要还原官方驱动程序，只需卸载libusb驱动，按步骤2操作即可
5. Arduino的串口是USB虚拟出来的，非真实的串口，当CH552没有用户程序时，串口也不复存在。
6. 该Arduino是通过USB生成一个虚拟串口，IDE打开该串口并发送转跳ISP模式指令，芯片进入ISP模式，IDE使用USB对其进行编程，而非使用串口进行编程，故需要确保第2点的驱动安装成功，并且设备管理器有相应设备，方可正常烧录。
7. 目录下有一个测试hex `01-Blink.ino.ch552.hex`，可以用wchisptool进行烧录，烧录完后可以用Arduino IDE进行烧录

## 例程说明
1. 01-Blink 为P30 LED闪烁
2. 02-PWMFading 为P30 LED呼吸
