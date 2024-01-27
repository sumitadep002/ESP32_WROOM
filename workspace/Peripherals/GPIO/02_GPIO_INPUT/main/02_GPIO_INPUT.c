#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define GPIO_INPUT_IO_4     GPIO_NUM_4
#define GPIO_INPUT_PIN_SEL  (1ULL<<GPIO_INPUT_IO_4)

void delay(uint16_t delay)
{
vTaskDelay(delay / portTICK_PERIOD_MS);
}

void app_main(void)
{
	
	gpio_config_t io_conf = {};
	io_conf.intr_type = GPIO_INTR_DISABLE;
	io_conf.mode = GPIO_MODE_INPUT;
	io_conf.pin_bit_mask = GPIO_INPUT_PIN_SEL;
	io_conf.pull_down_en = 1;
    io_conf.pull_up_en = 0;
    printf("Configuring GPIO Pin 4\n");
    gpio_config(&io_conf);
    

    while (1) { 
        if(gpio_get_level(GPIO_INPUT_IO_4))
        printf("GPIO Status: High\n");
        else
        printf("GPIO Status: LOW\n");
        delay(1000);
    }
    
}
