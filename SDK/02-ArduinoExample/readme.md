# Arduino development of routine

## Installation environment
1. Open Arduino IDE,click `File`-> `Preferences`,`Additional Boards Manager URLs` enter `https://github.com/WeActTC/ch55xduino/releases/download/0.0.9-WeActStudio/package_ch55xduino_mcs51_index.json`
2. Click Tools->Board:...->Boards Manager
3. Search `ch552`
4. Find `CH55xDuino MCS51 plain C core (non-C++)`,click on Install

## Burn driver installation method
> Arduino supports button-free burning. Drivers need to use LibusB instead of official WCH drivers
1. P36 and P37 pins are dedicated for firing and cannot be used for I/O
2. If the `USB Module` device exists in device management, uninstall the `USB Module` device in device Manager (select delete driver)
3. Open the Tools/bootloaderWebtool directory, double-click `zadig.exe`, and click `Install WCID Driver`. Wait until the Driver is installed
4. If the device cannot enter the burning mode automatically, hold down the P36 key and reinsert the USB Cable
5. To restore the official driver, uninstall the libusb driver, run WCHISPDRV in the WCHISPTool directory, and reinstall the driver
