#include "RC_Receiver_Component.h"

SemaphoreHandle_t rc_hold_semaphore;
TaskHandle_t rc_task_handle;

extern QueueHandle_t angle_queue;
extern QueueHandle_t motor_queue;
extern QueueHandle_t led_queue;

int speedMode;

void setupRCReceiverComponent()
{
	setupRCPins();

	setupUART_RC();

    /*************** RC Task ***************/
	//Create RC Semaphore
	//Create RC Task

	BaseType_t rcStatus = xTaskCreate(rcTask, "rcTask", 200, NULL, 2, NULL);
	if (rcStatus != pdPASS)
	{
		PRINTF("Motor task creation failed!.\r\n");
		while (1);
	}
}

void setupRCPins()
{
    CLOCK_EnableClock(kCLOCK_PortC);
    PORT_SetPinMux(PORTC, 3U, kPORT_MuxAlt3);
}

void setupUART_RC()
{
	//setup UART for RC receiver
	uart_config_t config;
	UART_GetDefaultConfig(&config);
	config.baudRate_Bps = 115200;
	config.enableTx = false;
	config.enableRx = true;
	UART_Init(UART1, &config, CLOCK_GetFreq(kCLOCK_CoreSysClk));
}

void rcTask(void* pvParameters)
{
	RC_Values rc_values;
	uint8_t* ptr = (uint8_t*) &rc_values;
	//RC task implementation
	while (1)
	{
		UART_ReadBlocking(UART1, ptr, 1);
		if(*ptr != 0x20)
			continue;
		UART_ReadBlocking(UART1, &ptr[1], sizeof(rc_values) - 1);
		if(rc_values.header == 0x4020)
		{
			BaseType_t status;
			int chanel6 = rc_values.ch6;
			status = xQueueSendToBack(angle_queue, (void*) &rc_values.ch1, portMAX_DELAY);
			status = xQueueSendToBack(motor_queue, (void*) &rc_values.ch2, portMAX_DELAY);
			if (status != pdPASS)
			{
				PRINTF("Queue Send failed!.\r\n");
				while (1);
			}
			speedMode = chanel6 == 2000 ? 2 : chanel6 == 1500 ? 1 : 0;
			status = xQueueSendToBack(led_queue, (void*) &speedMode, portMAX_DELAY);
			vTaskDelay(10 / portTICK_PERIOD_MS);


			printf("Channel 1 = %d\t", rc_values.ch1);
			printf("Channel 2 = %d\t", rc_values.ch2);
			printf("Channel 3 = %d\t", rc_values.ch3);
			printf("Channel 4 = %d\t", rc_values.ch4);
			printf("Channel 5 = %d\t", rc_values.ch5);
			printf("Channel 6 = %d\t", rc_values.ch6);
			printf("Channel 7 = %d\t", rc_values.ch7);
			printf("Channel 8 = %d\r\n", rc_values.ch8);
		}
	}
}


