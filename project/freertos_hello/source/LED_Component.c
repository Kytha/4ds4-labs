#include "LED_Component.h"


#define BOARD_LED_GPIO_BLUE     GPIOC
#define BOARD_LED_PIN_BLUE 		8

#define BOARD_LED_GPIO_GREEN    GPIOC
#define BOARD_LED_PIN_GREEN 	9

#define BOARD_LED_GPIO_RED    	GPIOD
#define BOARD_LED_PIN_RED 		1

QueueHandle_t led_queue;

void setupLEDComponent()
{
	setupLEDPins();

	setupLEDs();

    /*************** LED Task ***************/
	//Create LED Queue
	//Create LED Task
	led_queue = xQueueCreate(8, sizeof(void*));
	BaseType_t rcStatus = xTaskCreate(ledTask, "ledTask", 200, NULL, 3, NULL);
	if (rcStatus != pdPASS)
	{
		PRINTF("LED task creation failed!.\r\n");
		while (1);
	}
}

void setupLEDPins()
{
	//Configure LED pins
	CLOCK_EnableClock(kCLOCK_PortD);
	CLOCK_EnableClock(kCLOCK_PortC);

	/* PORTD13 is configured as PTD13 */
	PORT_SetPinMux(PORTD, 1U, kPORT_MuxAlt4);
	PORT_SetPinMux(PORTC, 9U, kPORT_MuxAlt3);
	PORT_SetPinMux(PORTC, 8U, kPORT_MuxAlt3);
}

void setupLEDs()
{
	//Initialize GREEN LED
	ftm_config_t ftmInfo;
	ftm_chnl_pwm_signal_param_t ftmParam;
	ftmParam.chnlNumber = FTM_GREEN_CHANNEL;
	ftmParam.level = kFTM_HighTrue;
	ftmParam.dutyCyclePercent = 0;
	ftmParam.firstEdgeDelayPercent = 0U;
	ftmParam.enableComplementary = false;
	ftmParam.enableDeadtime = false;
	FTM_GetDefaultConfig(&ftmInfo);
	FTM_Init(FTM3, &ftmInfo);
	FTM_SetupPwm(FTM3, &ftmParam, 1U, kFTM_EdgeAlignedPwm, 5000U, CLOCK_GetFreq(
	kCLOCK_BusClk));
	FTM_StartTimer(FTM3, kFTM_SystemClock);

	//Initialize RED LED

	ftmParam.chnlNumber = FTM_RED_CHANNEL;
	ftmParam.level = kFTM_HighTrue;
	ftmParam.dutyCyclePercent = 0;
	ftmParam.firstEdgeDelayPercent = 0U;
	ftmParam.enableComplementary = false;
	ftmParam.enableDeadtime = false;
	FTM_GetDefaultConfig(&ftmInfo);
	FTM_Init(FTM3, &ftmInfo);
	FTM_SetupPwm(FTM3, &ftmParam, 1U, kFTM_EdgeAlignedPwm, 5000U, CLOCK_GetFreq(
	kCLOCK_BusClk));
	FTM_StartTimer(FTM3, kFTM_SystemClock);

	//Initialize BLUE LED

	ftmParam.chnlNumber = FTM_BLUE_CHANNEL;
	ftmParam.level = kFTM_HighTrue;
	ftmParam.dutyCyclePercent = 0;
	ftmParam.firstEdgeDelayPercent = 0U;
	ftmParam.enableComplementary = false;
	ftmParam.enableDeadtime = false;
	FTM_GetDefaultConfig(&ftmInfo);
	FTM_Init(FTM3, &ftmInfo);
	FTM_SetupPwm(FTM3, &ftmParam, 1U, kFTM_EdgeAlignedPwm, 5000U, CLOCK_GetFreq(
	kCLOCK_BusClk));
	FTM_StartTimer(FTM3, kFTM_SystemClock);
}

void ledTask(void* pvParameters)
{
	//LED task implementation

	while(1)
	{
		uint16_t mode;
		BaseType_t status;
		status = xQueueReceive(led_queue, (void *) &mode, portMAX_DELAY);
		FTM_UpdatePwmDutycycle(FTM3, kFTM_Chnl_1, kFTM_EdgeAlignedPwm, 0);
		FTM_UpdatePwmDutycycle(FTM3, kFTM_Chnl_4, kFTM_EdgeAlignedPwm, 0);
		FTM_UpdatePwmDutycycle(FTM3, kFTM_Chnl_5, kFTM_EdgeAlignedPwm, 0);
		if (status != pdPASS)
			continue;
		switch(mode)
		{
		case STOP:
			FTM_UpdatePwmDutycycle(FTM3, FTM_RED_CHANNEL, kFTM_EdgeAlignedPwm, 250);
			break;
		case REVERSE:
			FTM_UpdatePwmDutycycle(FTM3, FTM_BLUE_CHANNEL, kFTM_EdgeAlignedPwm, 250);
			break;
		case FORWARD:
			FTM_UpdatePwmDutycycle(FTM3, FTM_GREEN_CHANNEL, kFTM_EdgeAlignedPwm, 250);
			break;
		}
		FTM_SetSoftwareTrigger(FTM3, true);
	}
}
