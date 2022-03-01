/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "timers.h"
#include "semphr.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Task priorities. */
/*******************************************************************************
 * Prototypes
 ******************************************************************************/


/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Application entry point.
 */

SemaphoreHandle_t* sem_g;
void timerCallbackFunction2(TimerHandle_t timer_handle)
{
	xSemaphoreGive(*sem_g);
	//if(counter >= 10) xTimerStop(timer_handle, 0);
}

void hello_task(void *pvParameters)
{

    for (;;)
    {
    	xSemaphoreTake(*sem_g, portMAX_DELAY);

        PRINTF("Hello world.\r\n");
        //vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

int main(void)
{
        BaseType_t status;
        /* Init board hardware. */
        BOARD_InitBootPins();
        BOARD_InitBootClocks();
        BOARD_InitDebugConsole();

        sem_g = malloc(sizeof(SemaphoreHandle_t));
        *sem_g = xSemaphoreCreateBinary();

        status = xTaskCreate(hello_task, "Hello_task", 200, NULL, 3, NULL);
        if (status != pdPASS)
        {
                PRINTF("Task creation failed!.\r\n");
                while (1);
        }

        TimerHandle_t timer_handle2 = xTimerCreate("Periodic timer",
                1000 / portTICK_PERIOD_MS,
                pdTRUE,
                NULL,
                timerCallbackFunction2);
        status = xTimerStart(timer_handle2, 0);
        if(status != pdPASS)
        {
                PRINTF("Couldn’t start the timer!.\r\n");
                while (1);
        }

        vTaskStartScheduler();
        while (1)
        {}
}


/*!
 * @brief Task responsible for printing of "Hello world." message.
 */
