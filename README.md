<!--
 * @Description: None
 * @version: V1.0.0
 * @Author: LILYGO_L
 * @Date: 2023-09-11 16:13:14
 * @LastEditors: LILYGO_L
 * @LastEditTime: 2024-02-03 16:09:09
 * @License: GPL 3.0
-->
<h1 align = "center">T-Encoder-Pro</h1>

<p> 
  <a href="https://code.visualstudio.com/"> <img src="badges/VisualStudioCode_badge.png" height="25px" alt="VisualStudioCode_badge" /> </a>
  <a href="https://platformio.org/"> <img src="badges/PlatformIO_badge.png" height="25px" alt="PlatformIO_badge" /> </a>
  <a href="https://hangzhang.org/"> <img src="badges/Arduino_badge.png" height="25px" alt="Arduino_badge"></a>
</p> 

## **English | [中文](./README_CN.md)**

## Version iteration:
| Version                              | Update date                       |
| :-------------------------------: | :-------------------------------: |
| T-Encoder-Pro_V1.0            | 2024-02-02                         |

## PurchaseLink
| Product                     | SOC           |  FLASH  |  PSRAM   | Link                   |
| :------------------------: | :-----------: |:-------: | :---------: | :------------------: |
| T-Encoder-Pro_V1.0   | ESP32S3R8 |   16M   |8M (Octal SPI)|  [Not yet sold]()  |

## Directory
- [Describe](#describe)
- [Preview](#preview)
- [Module](#module)
- [QuickStart](#quickstart)
- [PinOverview](#pinoverview)
- [FAQ](#faq)
- [Project](#project)
- [Information](#information)
- [DependentLibraries](#dependentlibraries)

## Describe

 T-Encoder-Pro is a smart control knob equipped with a AMOLED screen, developed based on the ESP32S3R8 chip, which is controlled by a dial.

## Preview

### PCB board

<details><summary><b>T-Encoder-Pro</b></summary>

##### T-Encoder-Pro Front

##### T-Encoder-Pro Back

</details>

### Rendering

## Module

### 1. MCU

* Chip: ESP32-S3-R8
* PSRAM: 8M (Octal SPI) 
* FLASH: 16M
* For more details, please visit[Espressif ESP32-S3 Datashee](https://www.espressif.com.cn/sites/default/files/documentation/esp32-s3_datasheet_en.pdf)

### 2. Screen

* Size: 2.04-inch round screen
* Screen Type: AMOLED
* Driver Chip: SH8601A-W14-T06
* Compatibility Library: Arduino_GFX
* Bus Communication Protocol: QSPI

### 3. Touch

* Chip: CHSC5816
* Bus Communication Protocol: IIC

### 4. Rotary Encoder

* Characteristic: Supports left and right rotation

### 5. Buzzer

## QuickStart

### Examples Support

<p align="center" width="100%">
    <img src="image/T-Encoder-Pro_Example_Support.png" alt="example">
</p>

### PlatformIO
1. Install[VisualStudioCode](https://code.visualstudio.com/Download),Choose installation based on your system type.

2. Open the "Extension" section of the Visual Studio Code software sidebar(Alternatively, use "<kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>X</kbd>" to open the extension),Search for the "PlatformIO IDE" extension and download it.

3. During the installation of the extension, you can go to GitHub to download the program. You can download the main branch by clicking on the "<> Code" with green text, or you can download the program versions from the "Releases" section in the sidebar.

4. After the installation of the extension is completed, open the Explorer in the sidebar(Alternatively, use "<kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>E</kbd>" go open it),Click on "Open Folder," locate the project code you just downloaded (the entire folder), and click "Add." At this point, the project files will be added to your workspace.

5. Open the "platformio.ini" file in the project folder (PlatformIO will automatically open the "platformio.ini" file corresponding to the added folder). Under the "[platformio]" section, uncomment and select the example program you want to burn (it should start with "default_envs = xxx") Then click "<kbd>[√](image/4.png)</kbd>" in the bottom left corner to compile,If the compilation is correct, connect the microcontroller to the computer and click "<kbd>[→](image/5.png)</kbd>" in the bottom left corner to download the program.

### Arduino
1. Install[Arduino](https://www.arduino.cc/en/software),Choose installation based on your system type.

2. Open the "example" directory within the project folder, select the example project folder, and open the file ending with ".ino" to open the Arduino IDE project workspace.

3. Open the "Tools" menu at the top right -> Select "Board" -> "Board Manager." Find or search for "esp32" and download the board files from the author named "Espressif Systems." Then, go back to the "Board" menu and select the development board type under "ESP32 Arduino." The selected development board type should match the one specified in the "platformio.ini" file under the [env] section with the header "board = xxx." If there is no corresponding development board, you may need to manually add the development board from the "board" directory within your project folder.

4. Open menu bar "[File](image/6.png)" -> "[Preferences](image/6.png)" ,Find "[Sketchbook location](image/7.png)"  here,copy and paste all library files and folders from the "libraries" folder in the project directory into the "libraries" folder in this directory.

5. Select the correct settings in the Tools menu, as shown in the table below.

| Setting                               | Value                                 |
| :-------------------------------: | :-------------------------------: |
| Board                                | Adafruit Feather ESP32-S3 No PSRAM|
| Upload Speed                     | 921600                               |
| USB Mode                           | Hardware CDC and JTAG     |
| USB CDC On Boot                | Enabled                             |
| USB Firmware MSC On Boot | Disabled                             |
| USB DFU On Boot                | Disabled                             |
| CPU Frequency                   | 240MHz (WiFi)                    |
| Flash Mode                         | QIO 80MHz                         |
| Flash Size                           | 16MB (128Mb)                     |
| Core Debug Level                | None                                 |
| PSRAM                                | OPI PSRAM                         |
| Arduino Runs On                  | Core 1                               |
| Events Run On                     | Core 1                               |

6. Select the correct port.

7. Click "<kbd>[√](image/8.png)</kbd>" in the upper right corner to compile,If the compilation is correct, connect the microcontroller to the computer,Click "<kbd>[→](image/9.png)</kbd>" in the upper right corner to download.

### firmware download
1. Open the project file "tools" and locate the ESP32 burning tool. Open it.

2. Select the correct burning chip and burning method, then click "OK." As shown in the picture, follow steps 1->2->3->4->5 to burn the program. If the burning is not successful, press and hold the "BOOT-0" button and then download and burn again.

3. Burn the file in the root directory of the project file "[firmware](./firmware/)" file,There is a description of the firmware file version inside, just choose the appropriate version to download.

<p align="center" width="100%">
    <img src="image/10.png" alt="example">
    <img src="image/11.png" alt="example">
</p>

## PinOverview

| Screen PIN       | ESP32S3 PIN      |
| :------------------: | :------------------:|
| SDIO0                     | IO11                  |
| SDIO1                     | IO13                  |
| SDIO2                     | IO7                  |
| SDIO3                     | IO14                  |
| SCLK                  | IO12                  |
| RST                    | IO4                  |
| VCI EN               |  IO3                  |
| CS                    | IO10                  |

| Touch PIN          | ESP32S3 PIN      |
| :------------------: | :------------------:|
| RST                  | IO8                  |
| INT                  | IO9                    |
| SDA                  | IO5                  |
| SCL                  | IO6                  |

| Rotary Encoder PIN          | ESP32S3 PIN      |
| :------------------: | :------------------:|
| KNOB DATA A      | IO1                  |
| KNOB DATA B      | IO2                  |
| KNOB KEY      | IO0                  |

| Buzzer PIN          | ESP32S3 PIN      |
| :------------------: | :------------------:|
| BUZZER DATA      | IO17                  |

## FAQ

* Q. After reading the above tutorials, I still don't know how to build a programming environment. What should I do?
* A. If you still don't understand how to build an environment after reading the above tutorials, you can refer to the [LilyGo-Document](https://github.com/Xinyuan-LilyGO/LilyGo-Document) document instructions to build it.

<br />

* Q. Why does Arduino IDE prompt me to update library files when I open it? Should I update them or not?
* A. Choose not to update library files. Different versions of library files may not be mutually compatible, so it is not recommended to update library files.

<br />

* Q. Why is there no serial data output on the "Uart" interface on my board? Is it defective and unusable?
* A. The default project configuration uses the USB interface as Uart0 serial output for debugging purposes. The "Uart" interface is connected to Uart0, so it won't output any data without configuration.<br />For PlatformIO users, please open the project file "platformio.ini" and modify the option under "build_flags = xxx" from "-D ARDUINO_USB_CDC_ON_BOOT=true" to "-D ARDUINO_USB_CDC_ON_BOOT=false" to enable external "Uart" interface.<br />For Arduino users, open the "Tools" menu and select "USB CDC On Boot: Disabled" to enable the external "Uart" interface.

<br />

* Q. Why is my board continuously failing to download the program?
* A. Please hold down the "BOOT-0" button and try downloading the program again.

## Project
* [SCH_T-Encoder-Pro_V1.0](./project/[SCH][T-Encoder-Pro_V1.0].pdf)
* [SCH_T-Encoder-Pro_V1.0_TFT_FPC](./project/[SCH][T-Encoder-Pro_V1.0][TFT_FPC].pdf)

## Information
* [Espressif](https://www.espressif.com/en/support/documents/technical-documents)
* [DXQ120MYB2416A](./information/DXQ120MYB2416A.pdf)
* [DS_CHSC5816_V1.1.5](./information/DS_CHSC5816_V1.1.5.pdf)
* [CHSC5816-ApplicationDoc_US_V04](./information/CHSC5816-ApplicationDoc_US_V04.pdf)

## DependentLibraries
* [Arduino_GFX-1.3.7](https://github.com/moononournation/Arduino_GFX)
* [lvgl-8.3.5](https://github.com/lvgl/lvgl)
* [SensorLib-0.1.4](https://github.com/lewisxhe/SensorsLib)