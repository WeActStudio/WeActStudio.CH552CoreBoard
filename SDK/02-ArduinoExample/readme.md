# Arduino development of routine
CH55x Arduino from the author DeqingSun [ch55xduino](https://github.com/DeqingSun/ch55xduino)

> Additional Boards Manager URLs
```
DeqingSun: https://raw.githubusercontent.com/DeqingSun/ch55xduino/ch55xduino/package_ch55xduino_mcs51_index.json
WeActStudio: https://github.com/WeActTC/ch55xduino/releases/download/0.0.9-WeActStudio/package_ch55xduino_mcs51_index.json
```
## Installation environment
1. Open Arduino IDE,click `File`-> `Preferences`,`Additional Boards Manager URLs` fill in the url above and choose one of them
2. Click Tools->Board:...->Boards Manager
3. Search `ch552`
4. Find `CH55xDuino MCS51 plain C core (non-C++)`,click on Install

## Burn driver installation method
1. P36 and P37 pins are dedicated for firing and cannot be used for I/O
2. The following describes how to install the two drivers
* Use `WCH official driver` to burn, open Tools/WCH_Bootloader_Driver/ directory, double click `setup. EXE`, click `Install`, after installation, device manager appears` USB Module `device (located under` external interface `), The driver has only been tested for Windows 10/ 11
* Use `libusb Driver` to burn, open Tools/bootloaderWebtool directory, double-click `zadig. Exe`, click `Install WCID Driver`, wait for the Driver installation is complete, ok,
If the `USB Module` device exists in device management, uninstall the `USB Module` device in device Manager (check delete driver), and then reinstall the driver
3. If the device cannot enter the burning mode automatically, hold down the P36 / C36 key and reinsert the USB flash drive
4. To restore the official driver, uninstall the libusb driver and perform Step 2

## Routine description
1. 01-blink: P30 LED flashing
2. 02-PWmFADING breathing for P30 LEDS