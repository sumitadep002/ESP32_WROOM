#include <stdio.h>
#include <driver/adc.h>
#include <freertos/FreeRTOS.h>

void delay(uint16_t amount)
{

vTaskDelay(amount/portTICK_PERIOD_MS);

}

void app_main(void)
{
int val = adc1_get_raw(ADC1_CHANNEL_0);
	
	while(1)
	{
		printf("Raw ADC: %d\n",val);
		val = adc1_get_raw(ADC1_CHANNEL_0);
		delay(500);
	}
}

void ADC_Init()
{
	adc1_config_width(ADC_WIDTH_BIT_12);
	adc1_config_channel_atten(ADC1_CHANNEL_0,ADC_ATTEN_DB_12);

}
