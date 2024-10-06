#ifndef __SPI_SEND_H__
#define __SPI_SEND_H__

#define GPIO_HANDSHAKE      2
#define GPIO_MOSI           12
#define GPIO_MISO           13
#define GPIO_SCLK           15
#define GPIO_CS             14

#define SENDER_HOST SPI2_HOST

void spi_send_task(void * param);


#endif
