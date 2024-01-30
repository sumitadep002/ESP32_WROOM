#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"

#include "lwip/err.h"
#include "lwip/sys.h"

#define SSID "Samsung"
#define PASS "66778899"



void app_main(void)
{
    //Initialize NVS
   // nvs_flash_init();
    esp_netif_init();
   
    
    while(1)
    {
    printf("Infinite loop...\n");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    
    
}
