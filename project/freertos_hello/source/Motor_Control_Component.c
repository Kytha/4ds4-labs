#include "Motor_Control_Component.h"

QueueHandle_t motor_queue;
QueueHandle_t angle_queue;

ftm_config_t ftmInfo;
ftm_chnl_pwm_signal_param_t ftmParam;
ftm_chnl_pwm_signal_param_t ftmParam2;
ftm_pwm_level_select_t pwmLevel = kFTM_HighTrue;

void setupMotorComponent()
{
	setupMotorPins();

	setupDCMotor();
	setupServo();

    /*************** Motor Task ***************/
	//Create Motor Queue
	//Create Motor Task

	motor_queue = xQueueCreate(32, sizeof(void*));
	if (motor_queue == NULL)
	{
		PRINTF("Motor queue creation failed!.\r\n");
		while (1);
	}

	BaseType_t motorStatus = xTaskCreate(motorTask, "motorTask", 200, (void*)motor_queue, 3, NULL);
	if (motorStatus != pdPASS)
	{
		PRINTF("Motor task creation failed!.\r\n");
		while (1);
	}

    /*************** Position Task ***************/
	//Create Angle Queue
	//Create Position Task

	angle_queue = xQueueCreate(32, sizeof(void*));
	if (angle_queue == NULL)
	{
		PRINTF("Angle queue creation failed!.\r\n");
		while (1);
	}

	BaseType_t positionStatus = xTaskCreate(positionTask, "positionTask", 200, (void*)angle_queue, 3, NULL);
	if (positionStatus != pdPASS)
	{
		PRINTF("Position task creation failed!.\r\n");
		while (1);
	}

	setupPWM();

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
	ftmParam.chnlNumber = FTM_CHANNEL_DC_MOTOR;
	ftmParam.level = pwmLevel;
	ftmParam.dutyCyclePercent = 7;
	ftmParam.firstEdgeDelayPercent = 0U;
	ftmParam.enableComplementary = false;
	ftmParam.enableDeadtime = false;
}

void setupPWM()
{
	FTM_GetDefaultConfig(&ftmInfo);
	ftmInfo.prescale = kFTM_Prescale_Divide_128;
	FTM_Init(FTM_MOTORS, &ftmInfo);
	ftm_chnl_pwm_signal_param_t ftmParams [2]= {ftmParam, ftmParam2};

	FTM_SetupPwm(FTM_MOTORS, ftmParams, 2U, kFTM_EdgeAlignedPwm, 50U,CLOCK_GetFreq(kCLOCK_BusClk));
	FTM_StartTimer(FTM_MOTORS, kFTM_SystemClock);
}

void setupServo()
{
	//Initialize PWM for Servo motor
	//Initialize PWM for Servo motor
	ftmParam2.chnlNumber = FTM_CHANNEL_SERVOMOTOR;
	ftmParam2.level = pwmLevel;
	ftmParam2.dutyCyclePercent = 7;
	ftmParam2.firstEdgeDelayPercent = 0U;
	ftmParam2.enableComplementary = false;
	ftmParam2.enableDeadtime = false;

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
	struct MotorMessage mm;

	while(1)
	{
		status = xQueueReceive(queue1, (void *) &mm, portMAX_DELAY);
		if (status != pdPASS)
			continue;
		float temp;
		uint16_t mode = mm.mode;
		switch(mode)
		{
		case STOP:
			updatePWM_dutyCycle(FTM_CHANNEL_DC_MOTOR, 0.07334);
			break;
		case FORWARD:
			temp = ((float)mm.speed - 1000.0f)*0.000025 + 0.07334;
			updatePWM_dutyCycle(FTM_CHANNEL_DC_MOTOR, temp);
			break;
		case REVERSE:
			temp =  0.07334 - ((float)mm.speed - 1000.0f)*0.000025;
			updatePWM_dutyCycle(FTM_CHANNEL_DC_MOTOR, temp);
			break;
		default:
			break;
		}
		FTM_SetSoftwareTrigger(FTM_MOTORS, true);
	}
}

void positionTask(void* pvParameters)
{
	QueueHandle_t queue1 = (QueueHandle_t)pvParameters;
	BaseType_t status;
	uint16_t value;
	while(1)
	{
		status = xQueueReceive(queue1, (void *) &value, portMAX_DELAY);
		if (status != pdPASS)
			continue;
		float temp = ((float)value - 1500.0f)*0.00005 + 0.075;
		updatePWM_dutyCycle(FTM_CHANNEL_SERVOMOTOR, temp);
		FTM_SetSoftwareTrigger(FTM_MOTORS, true);
	}

}
