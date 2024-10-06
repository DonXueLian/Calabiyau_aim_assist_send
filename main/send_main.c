#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "spi_send.h"
#include "my_hid_host.h"

void app_main(void){
    xTaskCreatePinnedToCore(hid_host_task, "hid_host", 2048*5, NULL, 4, NULL, 1);
    while(NULL == mouse_data_queue);    // 等待mouse_data_queue创建成功
    xTaskCreatePinnedToCore(spi_send_task, "spi_send", 2048*5, NULL, 5, NULL, 0);
}
