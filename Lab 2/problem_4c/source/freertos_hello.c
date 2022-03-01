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

TaskHandle_t xProducerSem = NULL;

char input[32];
#define BIT(x) (1 << x)
#define UPPER BIT(0)
#define LOWER BIT(1)

void producer_task(void* pvParameters)
{
	EventGroupHandle_t event_group = (EventGroupHandle_t)pvParameters;
	BaseType_t status;

	while(1)
	{
		scanf("%32s",&input);
		xEventGroupSetBits(event_group, LOWER);
		xEventGroupSetBits(event_group, UPPER);
	}
}

void consumer_task1(void* pvParameters)
{
	EventGroupHandle_t event_group = (EventGroupHandle_t)pvParameters;
	EventBits_t bits;

	while(1)
	{
		bits = xEventGroupWaitBits(event_group,
				LOWER,
				pdTRUE,
				pdFALSE,
				portMAX_DELAY);
		if((bits & LOWER) == LOWER)
		{
			PRINTF("Received Value 1 = %s\n", &input);
		}
	}
}

void consumer_task2(void* pvParameters)
{
	EventGroupHandle_t event_group = (EventGroupHandle_t)pvParameters;
	EventBits_t bits;

	while(1)
	{
		bits = xEventGroupWaitBits(event_group,
				UPPER,
				pdTRUE,
				pdFALSE,
				portMAX_DELAY);
		if((bits & UPPER) == UPPER)
		{
			char inputUpper[32];
			for(int i =0; i < 32; i ++)
			{
				if((input[i]>96) && (input[i]< 123))
					inputUpper[i] = input[i] ^0x20;
				else
					inputUpper[i] = input[i];
			}
			PRINTF("Received Value 2 = %s\n", &inputUpper);
		}
	}
}

void producer_sem(void* pvParameters)
{
	SemaphoreHandle_t* semaphores = (SemaphoreHandle_t*)pvParameters;
	SemaphoreHandle_t producerSemaphore = semaphores[0];
	SemaphoreHandle_t consumerSemaphore = semaphores[1];
	BaseType_t status1, status2;

	while(1)
	{
		status1 = xSemaphoreTake(consumerSemaphore, portMAX_DELAY);
		status2 = xSemaphoreTake(consumerSemaphore, portMAX_DELAY);

		if (status1 != pdPASS || status2 != pdPASS)
		{
			PRINTF("Failed to acquire consumer_semaphore\r\n");
			while (1);
		}

		scanf("%32s",&input);

		xSemaphoreGive(producerSemaphore);
		xSemaphoreGive(producerSemaphore);

		vTaskDelete(xProducerSem);
	}
}

void consumer1_sem(void* pvParameters)
{
	SemaphoreHandle_t* semaphores = (SemaphoreHandle_t*)pvParameters;
	SemaphoreHandle_t producerSemaphore = semaphores[0];
	SemaphoreHandle_t consumerSemaphore = semaphores[1];
	BaseType_t status;

	xSemaphoreGive(consumerSemaphore);
	status = xSemaphoreTake(producerSemaphore, portMAX_DELAY);

	while(1)
	{
		if (status != pdPASS)
		{
			PRINTF("Failed to acquire producer1_semaphore\r\n");
			while (1);
		}
		PRINTF("Received Value 1 = %s\n", &input);
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	}
}

void consumer2_sem(void* pvParameters)
{
	SemaphoreHandle_t* semaphores = (SemaphoreHandle_t*)pvParameters;
	SemaphoreHandle_t producerSemaphore = semaphores[0];
	SemaphoreHandle_t consumerSemaphore = semaphores[1];
	BaseType_t status;

	xSemaphoreGive(consumerSemaphore);
	status = xSemaphoreTake(producerSemaphore, portMAX_DELAY);
	char inputUpper[32];
	for(int i =0; i < 32; i ++)
	{
		if((input[i]>96) && (input[i]< 123))
			inputUpper[i] = input[i] ^0x20;
		else
			inputUpper[i] = input[i];
	}
	while(1)
	{
		if (status != pdPASS)
		{
			PRINTF("Failed to acquire producer1_semaphore\r\n");
			while (1);
		}
		PRINTF("Received Value 2 = %s\n", &inputUpper);
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	}
}


int main(void)
{
	BaseType_t status;

	/* Init board hardware. */
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitDebugConsole();

	EventGroupHandle_t event_group = xEventGroupCreate();
	status = xTaskCreate(producer_task, "producer", 200, (void*)event_group, 2, NULL);

	if (status != pdPASS)
	{
		PRINTF("Task creation failed!.\r\n");
		while (1);
	}

	status = xTaskCreate(consumer_task1, "consumer", 200, (void*)event_group, 3, NULL);
	if (status != pdPASS)
	{
		PRINTF("Task creation failed!.\r\n");
		while (1);
	}

	status = xTaskCreate(consumer_task2, "consumer", 200, (void*)event_group, 3, NULL);
	if (status != pdPASS)
	{
		PRINTF("Task creation failed!.\r\n");
		while (1);
	}

	vTaskStartScheduler();

	while (1)
	{}
}
