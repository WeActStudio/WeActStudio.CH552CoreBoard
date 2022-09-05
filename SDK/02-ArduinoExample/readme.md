# Arduino development of routine
CH55x Arduino from the author DeqingSun [ch55xduino](https://github.com/DeqingSun/ch55xduino)

> Additional Boards Manager URLs
```
DeqingSun: https://raw.githubusercontent.com/DeqingSun/ch55xduino/ch55xduino/package_ch55xduino_mcs51_index.json
WeActStudio: https://raw.githubusercontent.com/WeActTC/ch55xduino/ch55xduino/package_ch55xduino_mcs51_index.json
```
## Installation environment
1. Open Arduino IDE,click `File`-> `Preferences`,`Additional Boards Manager URLs` fill in the url above and choose one of them
2. Click Tools->Board:...->Boards Manager
3. Search `ch552`
4. Find `CH55xDuino MCS51 plain C core (non-C++)`,click on Install

## Burn driver installation method
> Arduino supports keyless burning, the driver can use LibusB, can also use the WCH official driver, WCH official driver is recommended.

1. P36,P37 pin is dedicated to burning and cannot be used for I/O
2. The following two methods are used to install the driver
* Use the `WCH official driver` to burn, open the Tools/WCH_Bootloader_Driver/ directory, select `Setup. EXE`, right-click `Run as administrator`, click `Install`, after installing, hold down P36, after connecting to the computer release the key, Device manager appears`USB Module `device (located in the`external Interface `or`Interface`directory) that the driver installation is successful, the driver is only tested in Win10/Win11 platform. If the driver installation fails, you can try to install the link's driver:`http://www.wch-ic.com/downloads/CH372DRV_EXE.html`
* Use the `libusb Driver` to burn, open the Tools/bootloaderWebtool directory, double-click `zadig.exe`, click `Install WCID Driver`, wait for the Driver installation can be completed, if the device management exists a `USB Module` device, You need to uninstall the `USB Module` device in Device Manager (and select Delete driver), and then reinstall the driver
3. If the device cannot automatically enter the burning mode, you can select a serial port that can be opened, hold down the P36 key, remove and reinsert the USB, and click the download button to download, and then select the serial port of the core board to realize automatic downloading.
4. To restore the official driver, uninstall the Libusb driver and go to Step 2
5. The serial port of Arduino is a virtual serial port created by USB, not a real one. When CH552 has no user program, the serial port no longer exists.
6. The Arduino generates a virtual serial port through USB, and the IDE opens the serial port and sends the ISP mode instruction. The chip enters ISP mode, and the IDE uses USB to program it instead of using serial port to program it.
7. Directory has a test hex `01-Blink.ino.ch552.hex`, you can use wchispTool for burning, burning after you can use Arduino IDE for burning

## Routine description
1. 01-blink: P30 LED flashing
2. 02-PWmFADING breathing for P30 LEDS