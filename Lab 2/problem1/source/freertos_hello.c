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


void hello_task(void *pvParameters)
{
	while(1)
	{
		PRINTF("Hello World\r\n");
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	}
}

void hello_task2(void *pvParameters)
{
	while(1)
	{
		PRINTF("Hello %s.\r\n", (char*) pvParameters);
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	}
}


char input[32];
TaskHandle_t xGetStringTask = NULL;

void get_string_task(void *pvParameters)
{
	while(1)
	{
		scanf("%32s", &input);
		vTaskDelay(1000 / portTICK_PERIOD_MS);
		vTaskDelete(xGetStringTask);
	}
}

void print_string_task(void *pvParameters)
{
	while(1)
	{
		if (input[0] == '\0')
		{
			vTaskDelay(1000 / portTICK_PERIOD_MS);
		}
		else
		{
			printf("Input was: %s\n", &input);
			vTaskDelay(1000 / portTICK_PERIOD_MS);
		}
	}
}

char* str = "4DS";

int main(void)
{
	BaseType_t status;

	/* Init board hardware. */
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitDebugConsole();

	status = xTaskCreate(get_string_task, "Get String Task", 200, NULL, 2, &xGetStringTask);
	if (status != pdPASS)
	{
		PRINTF("Task creation failed!.\r\n");
		while (1);
	}


	status = xTaskCreate(print_string_task, "Print String Task", 200, (void*)input, 3, NULL);
	if (status != pdPASS)
	{
		PRINTF("Task creation failed!.\r\n");
		while (1);
	}

	vTaskStartScheduler();
	while(1)
	{}
}
