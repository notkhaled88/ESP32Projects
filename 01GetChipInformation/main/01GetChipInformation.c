#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"
#include "driver/uart.h"

void app_main(void)
{
    uart_driver_install(UART_NUM_0, 256, 0, 0, NULL, 0);
    while(true)
    {
        if(uart_is_driver_installed(UART_NUM_0))
        {
            esp_chip_info_t chipInfo;
            esp_chip_info(&chipInfo);
            printf("hello world from esp32 with %d core\n",chipInfo.cores);
            printf("the chip %s\n", chipInfo.features & CHIP_FEATURE_WIFI_BGN ? "support wifi!" : "doesn't support wifi!");
            fflush(stdout);
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
