#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"

#define GPIO_INPUT_IO_4     GPIO_NUM_4
#define GPIO_INPUT_PIN_SEL  (1ULL<<GPIO_INPUT_IO_4)



uint8_t inr_flag = 0;


void gpio_isr_handler_4(void *arg)
{inr_flag=1;}


void delay(uint16_t delay)
{vTaskDelay(delay / portTICK_PERIOD_MS);}

void app_main(void)
{
	
	gpio_config_t io_conf = {};
	io_conf.intr_type = GPIO_INTR_LOW_LEVEL;
	io_conf.mode = GPIO_MODE_INPUT;
	io_conf.pin_bit_mask = GPIO_INPUT_PIN_SEL;
	io_conf.pull_down_en = 0;
    io_conf.pull_up_en = 1;
    printf("Configuring GPIO Pin 4\n");
    gpio_config(&io_conf);
    gpio_install_isr_service(ESP_INTR_FLAG_LEVEL1);
    gpio_isr_handler_add(GPIO_INPUT_IO_4,gpio_isr_handler_4,NULL);
    
    

    while (1) { 
        if(inr_flag)
        {
        printf("Interrupt occurred\n");
        inr_flag=0;
        }
        else
        printf("Waiting for interrupt\n");
        delay(500);
        }
    
}
