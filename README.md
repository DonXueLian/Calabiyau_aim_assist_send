## 硬件准备

两个esp32s3（一个作为发送端，烧入send下程序，一个作为接收端，烧入receive下的程序）

一个usb母口

## 电路连接

### spi通信连线

将两个esp32s3的GPIO2 12 13 14 15 分别相连，无需上拉电阻

发送 esp32      接收 esp32  
2------------------------2  
12----------------------12  
13----------------------13  
15----------------------15  
14----------------------14

以下是spi的引脚定义（位于`components/spi_send/include/spi_send.h`），可以修改到其他引脚（发送端和r接收端需要同步修改，保持一致）

```
#define GPIO_HANDSHAKE      2
#define GPIO_MOSI           12
#define GPIO_MISO           13
#define GPIO_SCLK           15
#define GPIO_CS             14
```

### USB接口连线

将USB母口的*D+*连接到作为*发送端*的esp32s3的*GPIO 20*，*D-*连接到*GPIO 19*

### 电源

usb母口需要5V电源供电

## 编译上传

项目使用espidf编译

请先使用`idf.py menuconfig`修改ram和flash到对应的大小，测试使用的是8MB RAM  16MB flash (esp32s3N16R8)

将作为发送端的esp32通过串口连接到电脑，在linux中，进到本目录下`.../send`，然后运行`idf.py build flash`，即可编译并烧入

*需要发送端的esp32和接收端的esp32正确连接并分别烧入了对应的程序才可正常运行*

## 使用

使用两根usb数据线分别将接收端esp32的串口和usb连接到电脑

将鼠标插入到发送端esp32的usb接口上（鼠标推荐使用500hz回报率，最高支持1000Hz回报率）

电脑上运行kalabiqiu.py `python kalabiqiu.py`
