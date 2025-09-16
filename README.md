<!--
 * @Description: None
 * @Author: LILYGO_L
 * @Date: 2023-09-11 16:13:14
 * @LastEditTime: 2025-09-16 11:58:12
 * @License: GPL 3.0
-->
<h1 align = "center">T-Encoder-Pro</h1>

<p align="center" width="100%">
    <img src="image/13.jpg" alt="">
</p>

## **English | [中文](./README_CN.md)**

## Version iteration:
| Version                              | Update date                       |
| :-------------------------------: | :-------------------------------: |
| T-Encoder-Pro_V1.0            | 2024-02-02                         |

## PurchaseLink
| Product                     | SOC           |  FLASH  |  PSRAM   | Link                   |
| :------------------------: | :-----------: |:-------: | :---------: | :------------------: |
| T-Encoder-Pro_V1.0   | ESP32S3R8 |   16M   |8M (Octal SPI)| [LILYGO Mall](https://www.lilygo.cc/products/t-encoder-plus) <br /> [Banggood Mall](https://m.banggood.in/LILYGO-T-Encoder-Pro-ESP32-S3-Rotary-Encoder-CHSC5816-ESP32-S3FN4R2-Circuit-Board-1_2-inch-AMOLED-Touch-Display-Wireless-Module-p-2018774.html) |

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

 T-Encoder-Pro is a smart control knob equipped with a AMOLED touch screen, based on the ESP32S3R8 chip. The knob rotates, clicks (pushes in), and contains a beeper and vibration motor.

## Preview

### Actual Product Image

<p align="center" width="100%">
    <img src="image/14.jpg" alt="">
</p>

---

<p align="center" width="100%">
    <img src="image/13.jpg" alt="">
</p>

---

<p align="center" width="100%">
    <img src="image/15.jpg" alt="">
</p>

## Module

### 1. MCU

* Chip: ESP32-S3-R8
* PSRAM: 8M (Octal SPI) 
* FLASH: 16M
* For more details, please visit [Espressif ESP32-S3 Datashee](https://www.espressif.com.cn/sites/default/files/documentation/esp32-s3_datasheet_en.pdf)

### 2. Screen

* Size: 1.2-inch round screen
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

| example | `[vscode][esp-idf-v5.4.0]` | description | picture |
| ------  | ------  | ------ | ------ | 
| [iic_scan](./main/examples/iic_scan) | <p align="center">![alt text][supported] |  |  |
| [screen_touch_lvgl_9](./main/examples/screen_touch_lvgl_9) |<p align="center">![alt text][supported] | |  |
| [touch](./main/examples/touch) | <p align="center">![alt text][supported] |  |  |
| [buzzer](./main/examples/buzzer) |<p align="center">![alt text][supported] | |  |
| [rotary_encoder](./main/examples/rotary_encoder) | <p align="center">![alt text][supported] |  |  |

[supported]: https://img.shields.io/badge/-supported-green "example"

### ESP-IDF Visual Studio Code  
1. Install [Visual Studio Code](https://code.visualstudio.com/Download) by selecting the appropriate version for your operating system.  

2. Open the "Extensions" sidebar in Visual Studio Code (or use <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>X</kbd> to open extensions), search for the "ESP-IDF" extension, and install it.  

3. While the extension is installing, use the git command to clone the repository:  

        git clone -b espidf-v5.4 --recursive https://github.com/Xinyuan-LilyGO/T-Encoder-Pro.git

    Ensure you include the `--recursive` flag during cloning. If you forget to include it, you will need to initialize the submodules later by running:  

        git submodule update --init --recursive  

4. Download and install [ESP-IDF v5.4.1](https://dl.espressif.cn/dl/esp-idf/?idf=4.4). Take note of the installation path. Open the previously installed "ESP-IDF" extension and select "Configure ESP-IDF Extension." Choose the "USE EXISTING SETUP" menu, then select "Search ESP-IDF in system." Correctly configure the installation path you noted earlier:  
   - **Enter ESP-IDF directory (IDF_PATH):** `Your installation path xxx\Espressif\frameworks\esp-idf-v5.4`  
   - **Enter ESP-IDF Tools directory (IDF_TOOLS_PATH):** `Your installation path xxx\Espressif`  
    Click the "Install" button at the bottom right to proceed with the framework installation.  

5. Click the "SDK Configuration Editor" in the ESP-IDF extension menu at the bottom of Visual Studio Code. In the search bar, look for the field "Select the example to build" and choose the project you want to compile. Then, search for "Select the camera type" and select the camera model integrated on your board. Save the settings.  

6. Click "Set Espressif Device Target" in the bottom menu bar of Visual Studio Code and select **ESP32S3**. Next, click "Build Project" in the bottom menu bar and wait for the build to complete. Then, click "Select Port to Use," followed by "Flash Project" to upload the program.  

<p align="center" width="100%">
    <img src="image/1.jpg" alt="example">
</p>

### Firmware download
1. Open the project file "tools" and locate the ESP32 burning tool. Open it.

2. Select the correct burning chip and burning method, then click "OK." As shown in the picture, follow steps 1->2->3->4->5 to burn the program. If the burning is not successful, press and hold the "BOOT-0" button and then download and burn again.

3. Burn the file in the root directory of the project file "[firmware](./firmware/)" file, there is a description of the firmware file version inside, just choose the appropriate version to download.

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
* A. Please hold down the "BOOT" button and try downloading the program again.The following is the illustration of the BOOT button.

<p align="center" width="100%">
    <img src="image/12.jpg" alt="BOOT">
</p>

<br />

## Project
* [SCH_T-Encoder-Pro_V1.0](project/[SCH][T-Encoder-Pro_V1.0].pdf)
* [SCH_T-Encoder-Pro_V1.0_TFT_FPC](project/[SCH][T-Encoder-Pro_V1.0][TFT_FPC].pdf)

## Information
* [Espressif](https://www.espressif.com/en/support/documents/technical-documents)
* [DXQ120MYB2416A](information/DXQ120MYB2416A.pdf)
* [DS_CHSC5816_V1.1.5](information/DS_CHSC5816_V1.1.5.pdf)
* [CHSC5816-ApplicationDoc_US_V04](information/CHSC5816-ApplicationDoc_US_V04.pdf)

## DependentLibraries
* [Arduino_GFX-1.5.0](https://github.com/moononournation/Arduino_GFX)
* [lvgl-8.3.5](https://github.com/lvgl/lvgl)
* [SensorLib-0.1.4](https://github.com/lewisxhe/SensorsLib)
