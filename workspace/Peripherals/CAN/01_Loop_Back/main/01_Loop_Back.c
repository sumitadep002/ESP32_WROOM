#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_err.h"
#include "esp_log.h"
#include "driver/twai.h"



#define MSG_ID                  0x555   //11 bit standard format ID
#define TX_GPIO_NUM             GPIO_NUM_21
#define RX_GPIO_NUM             GPIO_NUM_22


static const twai_timing_config_t t_config = TWAI_TIMING_CONFIG_25KBITS();
static const twai_filter_config_t f_config = {.acceptance_code = (MSG_ID << 21),				//It will set teh first 11 MSBs equivalent to MSG_ID
                                              .acceptance_mask = ~(TWAI_STD_ID_MASK << 21),		//It will be 
                                              .single_filter = true
                                             };
                                             
static const twai_general_config_t g_config = TWAI_GENERAL_CONFIG_DEFAULT(TX_GPIO_NUM, RX_GPIO_NUM, TWAI_MODE_NO_ACK);                                             

void app_main(void)
{

}
