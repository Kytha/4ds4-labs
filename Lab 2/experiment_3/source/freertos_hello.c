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

#include "queue.h"
#include "semphr.h"
#include "event_groups.h"

#define BIT(x) (1 << x)
#define LEFT_BIT BIT(0)
#define RIGHT_BIT BIT(1)
#define UP_BIT BIT(2)
#define DOWN_BIT (1 << 3)

void producer_event(void* pvParameters)
{
	EventGroupHandle_t event_group = (EventGroupHandle_t)pvParameters;
	BaseType_t status;
	char c;
	while(1)
	{
		scanf("%c", &c);
		switch(c)
		{
			case 'a':
				xEventGroupSetBits(event_group, LEFT_BIT);
				break;
			case 's':
				xEventGroupSetBits(event_group, DOWN_BIT);
				break;
			case 'd':
				xEventGroupSetBits(event_group, RIGHT_BIT);
				break;
			case 'w':
				xEventGroupSetBits(event_group, UP_BIT);
				break;
		}
	}
}

void consumer_event(void* pvParameters)
{
	EventGroupHandle_t event_group = (EventGroupHandle_t)pvParameters;
	EventBits_t bits;
	while(1)
	{
		bits = xEventGroupWaitBits(event_group,
				LEFT_BIT | RIGHT_BIT | UP_BIT | DOWN_BIT,
				pdTRUE,
				pdFALSE,
				portMAX_DELAY);
		if((bits & LEFT_BIT) == LEFT_BIT)
		{
			PRINTF("Left\r\n");
		}
		if((bits & RIGHT_BIT) == RIGHT_BIT)
		{
			PRINTF("Right\r\n");
		}
		if((bits & UP_BIT) == UP_BIT)
		{
			PRINTF("Up\r\n");
		}
		if((bits & DOWN_BIT) == DOWN_BIT)
		{
			PRINTF("Down\r\n");
		}
	}
}

TaskHandle_t xProducerSem = NULL;


int main(void)
{
	BaseType_t status;
	/* Init board hardware. */
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitDebugConsole();
	EventGroupHandle_t event_group = xEventGroupCreate();
	status = xTaskCreate(producer_event, "producer", 200, (void*)event_group, 2, NULL);
	if (status != pdPASS)
	{
		PRINTF("Task creation failed!.\r\n");
		while (1);
	}
	status = xTaskCreate(consumer_event, "consumer", 200, (void*)event_group, 3, NULL);
	if (status != pdPASS)
	{
		PRINTF("Task creation failed!.\r\n");
		while (1);
	}
	vTaskStartScheduler();
	while (1)
	{}
}
