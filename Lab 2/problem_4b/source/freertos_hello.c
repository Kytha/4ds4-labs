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

TaskHandle_t xProducerSem0 = NULL;
TaskHandle_t xProducerSem1 = NULL;
TaskHandle_t xProducerSem2 = NULL;
TaskHandle_t xProducerSem3 = NULL;
TaskHandle_t xProducerCon = NULL;

void producer_sem(void* pvParameters)
{
	SemaphoreHandle_t* semaphores = (SemaphoreHandle_t*)pvParameters;
	SemaphoreHandle_t semaphore0 = semaphores[0];
	SemaphoreHandle_t semaphore1 = semaphores[1];
	SemaphoreHandle_t semaphore2 = semaphores[2];
	SemaphoreHandle_t semaphore3 = semaphores[3];

	while(1)
	{
		char c;
		scanf("%c", &c);
		if(c == 'w')
			xSemaphoreGive(semaphore0);
		if(c == 'a')
			xSemaphoreGive(semaphore1);
		if(c == 's')
			xSemaphoreGive(semaphore2);
		if(c == 'd')
			xSemaphoreGive(semaphore3);
		vTaskDelay(400 / portTICK_PERIOD_MS);
	}
}



void consumer_sem(void* pvParameters)
{
	SemaphoreHandle_t* semaphores = (SemaphoreHandle_t*)pvParameters;
	SemaphoreHandle_t semaphore0 = semaphores[0];
	SemaphoreHandle_t semaphore1 = semaphores[1];
	SemaphoreHandle_t semaphore2 = semaphores[2];
	SemaphoreHandle_t semaphore3 = semaphores[3];
	BaseType_t status0;
	BaseType_t status1;
	BaseType_t status2;
	BaseType_t status3;

	while(1)
	{
		status0 = xSemaphoreTake(semaphore0, 0x00000002UL);
		status1 = xSemaphoreTake(semaphore1, 0x00000002UL);
		status2 = xSemaphoreTake(semaphore2, 0x00000002UL);
		status3 = xSemaphoreTake(semaphore3, 0x00000002UL);
		if(status0 == pdPASS)
			PRINTF("W Pressed");
		if(status1 == pdPASS)
			PRINTF("A Pressed");
		if(status2 == pdPASS)
			PRINTF("S Pressed");
		if(status3 == pdPASS)
			PRINTF("D Pressed");
		vTaskDelay(400 / portTICK_PERIOD_MS);
	}

}

int main(void)
{
	BaseType_t status;
	/* Init board hardware. */
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitDebugConsole();
	SemaphoreHandle_t* semaphores = (SemaphoreHandle_t*) malloc(4* sizeof(SemaphoreHandle_t));

	semaphores[0] = xSemaphoreCreateBinary(); //producer_sem
	semaphores[1] = xSemaphoreCreateBinary();
	semaphores[2] = xSemaphoreCreateBinary();
	semaphores[3] = xSemaphoreCreateBinary();

	status = xTaskCreate(producer_sem, "producer1", 200, (void*)semaphores, 2, xProducerSem1);
	if (status != pdPASS)
	{
		PRINTF("Task creation failed!.\r\n");
		while (1);
	}

	status = xTaskCreate(consumer_sem, "consumer", 200, (void*)semaphores, 3, NULL);
	if (status != pdPASS)
	{
		PRINTF("Task creation failed!.\r\n");
		while (1);
	}

	vTaskStartScheduler();
	while (1)
	{}
}
