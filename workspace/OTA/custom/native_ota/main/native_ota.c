#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_ota_ops.h"
#include "esp_app_format.h"
#include "esp_http_client.h"
#include "esp_flash_partitions.h"
#include "esp_partition.h"
#include "nvs.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
//#include "protocol_examples_common.h"
#include "esp_wifi.h"
#include "errno.h"


void app_main(void)
{

	ESP_LOG_INFO("OTA example app_main start");
	for(uint8_t i=0;i<10;i++)
	vTaskDelay(1000/portTICK_PERIOD_MS);
	esp_restart();

}
