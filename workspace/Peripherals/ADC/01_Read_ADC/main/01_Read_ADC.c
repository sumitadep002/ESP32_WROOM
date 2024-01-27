#include <stdio.h>
#include <driver/adc.h>
#include <freertos/FreeRTOS.h>


void delay(uint16_t amount)
{

vTaskDelay(amount/portTICK_PERIOD_MS);

}

void app_main(void)
{
	adc1_config_width(ADC_WIDTH_BIT_12);
	adc1_config_channel_atten(ADC1_CHANNEL_8,ADC_ATTEN_DB_0);
	//int val = adc1_get_raw(ADC2_CHANNEL_0);
	
	while(1)
	{
		printf("Raw ADC: %d\n",adc1_get_raw(ADC1_CHANNEL_8));
		delay(500);
	}
}
