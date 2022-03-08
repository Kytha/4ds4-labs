#include "Motor_Control_Component.h"

QueueHandle_t motor_queue;
QueueHandle_t angle_queue;


void setupMotorComponent()
{
	setupMotorPins();
	setupPWM();
	setupDCMotor();
	setupServo();

    /*************** Motor Task ***************/
	//Create Motor Queue
	//Create Motor Task

	motor_queue = xQueueCreate(32, sizeof(int));
	if (motor_queue == NULL)
	{
		PRINTF("Motor queue creation failed!.\r\n");
		while (1);
	}

	BaseType_t motorStatus = xTaskCreate(motorTask, "motorTask", 200, (void*)motor_queue, 2, NULL);
	if (motorStatus != pdPASS)
	{
		PRINTF("Motor task creation failed!.\r\n");
		while (1);
	}

    /*************** Position Task ***************/
	//Create Angle Queue
	//Create Position Task

	angle_queue = xQueueCreate(32, sizeof(int));
	if (angle_queue == NULL)
	{
		PRINTF("Angle queue creation failed!.\r\n");
		while (1);
	}

/*	BaseType_t positionStatus = xTaskCreate(positionTask, "positionTask", 200, (void*)angle_queue, 2, NULL);
	if (positionStatus != pdPASS)
	{
		PRINTF("Position task creation failed!.\r\n");
		while (1);
	}*/
}

void setupMotorPins()
{
    //Configure PWM pins for DC and Servo motors
    CLOCK_EnableClock(kCLOCK_PortA);
    /* Port A Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortC);
    // FTM
    PORT_SetPinMux(PORTC, 1U, kPORT_MuxAlt4);
    PORT_SetPinMux(PORTA, 6U, kPORT_MuxAlt3);
}

void setupDCMotor()
{
	//Initialize PWM for DC motor
	updatePWM_dutyCycle(FTM_CHANNEL_DC_MOTOR, 0.05);
	FTM_SetSoftwareTrigger(FTM_MOTORS, true);
}

void setupPWM()
{
	ftm_config_t ftmInfo;
	ftm_chnl_pwm_signal_param_t ftmParam0;
	ftm_chnl_pwm_signal_param_t ftmParam1;
	ftm_pwm_level_select_t pwmLevel = kFTM_HighTrue;

	ftmParam0.chnlNumber = FTM_CHANNEL_DC_MOTOR;
	ftmParam0.level = pwmLevel;
	ftmParam0.dutyCyclePercent = 7;
	ftmParam0.firstEdgeDelayPercent = 0U;
	ftmParam0.enableComplementary = false;
	ftmParam0.enableDeadtime = false;

	ftmParam1.chnlNumber = FTM_CHANNEL_SERVOMOTOR;
	ftmParam1.level = pwmLevel;
	ftmParam1.dutyCyclePercent = 7;
	ftmParam1.firstEdgeDelayPercent = 0U;
	ftmParam1.enableComplementary = false;
	ftmParam1.enableDeadtime = false;

	FTM_GetDefaultConfig(&ftmInfo);
	ftmInfo.prescale = kFTM_Prescale_Divide_128;

	FTM_Init(FTM_MOTORS, &ftmInfo);
	FTM_SetupPwm(FTM_MOTORS, &ftmParam0, 1U, kFTM_EdgeAlignedPwm, 50U, CLOCK_GetFreq(kCLOCK_BusClk));
	FTM_SetupPwm(FTM_MOTORS, &ftmParam1, 1U, kFTM_EdgeAlignedPwm, 50U, CLOCK_GetFreq(kCLOCK_BusClk));
	FTM_StartTimer(FTM_MOTORS, kFTM_SystemClock);
}

void setupServo()
{
	//Initialize PWM for Servo motor

	updatePWM_dutyCycle(FTM_CHANNEL_SERVOMOTOR, 0.05);
	FTM_SetSoftwareTrigger(FTM_MOTORS, true);
}

void updatePWM_dutyCycle(ftm_chnl_t channel, float dutyCycle)
{
	uint32_t cnv, cnvFirstEdge = 0, mod;

	/* The CHANNEL_COUNT macro returns -1 if it cannot match the FTM instance */
	assert(-1 != FSL_FEATURE_FTM_CHANNEL_COUNTn(FTM_MOTORS));

	mod = FTM_MOTORS->MOD;
	if(dutyCycle == 0U)
	{
		/* Signal stays low */
		cnv = 0;
	}
	else
	{
		cnv = mod * dutyCycle;
		/* For 100% duty cycle */
		if (cnv >= mod)
		{
			cnv = mod + 1U;
		}
	}

	FTM_MOTORS->CONTROLS[channel].CnV = cnv;
}

void motorTask(void* pvParameters)
{
	//Motor task implementation
	QueueHandle_t queue1 = (QueueHandle_t)pvParameters;
	BaseType_t status;
	int input;

	while(1)
	{
		status = xQueueReceive(queue1, (void *) &input, portMAX_DELAY);
		if (status != pdPASS)
			continue;
		printf("Hello World");
	}
}

void positionTask(void* pvParameters)
{

}
