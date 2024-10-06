#ifndef __MY_HID_HOST_H__
#define __MY_HID_HOST_H__

#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

extern QueueHandle_t mouse_data_queue;

typedef struct
{
    int16_t x_pos;
    int16_t y_pos;
    uint8_t button_val;
    int8_t whirl_displacement;
}mouse_data_t;

void hid_host_task(void * param);

#endif
