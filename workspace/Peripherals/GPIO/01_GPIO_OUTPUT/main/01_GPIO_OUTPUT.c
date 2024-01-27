#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"

#define GPIO_OUTPUT_IO_4     GPIO_NUM_4
#define GPIO_OUTPUT_PIN_SEL  (1ULL<<GPIO_OUTPUT_IO_4)

void delay(uint16_t delay)
{
vTaskDelay(delay / portTICK_PERIOD_MS);
}

void app_main(void)
{
	
	gpio_config_t io_conf = {};
	io_conf.intr_type = GPIO_INTR_DISABLE;
	io_conf.mode = GPIO_MODE_OUTPUT;
	io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
	io_conf.pull_down_en = 0;
    io_conf.pull_up_en = 0;
    printf("Configuring GPIO Pin 4\n");
    gpio_config(&io_conf);
    

    while (1) { 
        gpio_set_level(GPIO_OUTPUT_IO_4,1);
        printf("GPIO Status: High\n");
        delay(1000);
        gpio_set_level(GPIO_OUTPUT_IO_4,0);
        printf("GPIO Status: LOW\n");
        delay(1000);
    }
    
}

