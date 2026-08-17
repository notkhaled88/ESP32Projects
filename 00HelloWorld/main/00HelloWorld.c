#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


void app_main(void)
{
    while(true)
    {
        printf("hello World!\n");
        fflush(stdout);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

}
