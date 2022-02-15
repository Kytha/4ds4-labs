/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_uart.h"
#include "fsl_ftm.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define TARGET_UART UART4
volatile char ch;
volatile int new_char = 0;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
#define FTM_MOTOR				FTM0
#define FTM_CHANNEL_DC_MOTOR	kFTM_Chnl_0
#define FTM_CHANNEL_SERVOMOTOR	kFTM_Chnl_3

#define TARGET_UART UART4
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

	FTM_Init(FTM_MOTOR, &ftmInfo);
	FTM_SetupPwm(FTM_MOTOR, &ftmParam0, 1U, kFTM_EdgeAlignedPwm, 50U, CLOCK_GetFreq(kCLOCK_BusClk));
	FTM_SetupPwm(FTM_MOTOR, &ftmParam1, 1U, kFTM_EdgeAlignedPwm, 50U, CLOCK_GetFreq(kCLOCK_BusClk));
	FTM_StartTimer(FTM_MOTOR, kFTM_SystemClock);
}

void updatePWM_dutyCycle(ftm_chnl_t channel, float dutyCycle)
{
	uint32_t cnv, cnvFirstEdge = 0, mod;

	/* The CHANNEL_COUNT macro returns -1 if it cannot match the FTM instance */
	assert(-1 != FSL_FEATURE_FTM_CHANNEL_COUNTn(FTM_MOTOR));

	mod = FTM_MOTOR->MOD;
	if (dutyCycle == 0U)
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

	FTM_MOTOR->CONTROLS[channel].CnV = cnv;
}

void setupUART2()
{
	uart_config_t config;
	UART_GetDefaultConfig(&config);

	config.baudRate_Bps = 57600;
	config.enableTx = true;
	config.enableRx = true;
	config.enableRxRTS = true;
	config.enableTxCTS = true;
	UART_Init(TARGET_UART, &config, CLOCK_GetFreq(kCLOCK_BusClk));
}
void setupUART3()
{
	uart_config_t config;
	UART_GetDefaultConfig(&config);
	config.baudRate_Bps = 57600;
	config.enableTx = true;
	config.enableRx = true;
	config.enableRxRTS = true;
	config.enableTxCTS = true;
	UART_Init(TARGET_UART, &config, CLOCK_GetFreq(kCLOCK_BusClk));
	/******** Enable Interrupts *********/
	UART_EnableInterrupts(TARGET_UART, kUART_RxDataRegFullInterruptEnable);
	EnableIRQ(UART4_RX_TX_IRQn);
}

void UART4_RX_TX_IRQHandler()
{
	UART_GetStatusFlags(TARGET_UART);
	ch = UART_ReadByte(TARGET_UART);
	new_char = 1;
}

void updateServo(float input)
{
	float dutyCycle = (input + 100)*0.025/100.f + 0.05;
	updatePWM_dutyCycle(FTM_CHANNEL_DC_MOTOR, dutyCycle);
	FTM_SetSoftwareTrigger(FTM_MOTOR, true);
}

void updateMotor(float input)
{
	float dutyCycle = input * 0.025f/100.0f + 0.0615;
	updatePWM_dutyCycle(FTM_CHANNEL_SERVOMOTOR, dutyCycle);
	FTM_SetSoftwareTrigger(FTM_MOTOR, true);
}

void zeros(char* arr, int size) {
	for(int i = 0; i < size; i++)
	{
		*(arr +i) = '\0';
	}
}

int main(void)
{
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitDebugConsole();

	setupPWM();
	setupUART3();


	/******* Delay *******/
	for(volatile int i = 0U; i < 1000000; i++)
		__asm("NOP");

	updatePWM_dutyCycle(FTM_CHANNEL_SERVOMOTOR, 0.1);
	updatePWM_dutyCycle(FTM_CHANNEL_DC_MOTOR, 0.6);
	FTM_SetSoftwareTrigger(FTM_MOTOR, true);

	char ch;
	//char txbuff[] = "Hello World\r\n";
	//PRINTF("%s", txbuff);
	//UART_WriteBlocking(TARGET_UART, txbuff, sizeof(txbuff) - 1);
	char buffer[32];
	zeros(buffer, 32);

	int cursor = 0;
	int isServoInput = 1;
	while (1)
	{
		if(new_char)
		{
			new_char = 0;
			PUTCHAR(ch);

		//scanf("%c", &ch);
		//UART_ReadBlocking(TARGET_UART, &ch, 1);

			if(ch == '\n')
			{
				float input = (float)atof(buffer);
				if(input > 100 || input < -100)
				{
					cursor = 0;
					zeros(buffer,32);
					continue;
				}
				if(isServoInput)
				{
					updateServo(input);
					cursor = 0;
					zeros(buffer,32);
				}else
				{
					updateMotor(input);
					zeros(buffer,32);
					cursor = 0;
				}
				isServoInput = isServoInput == 1 ? 0 : 1;
			} else
			{
				buffer[cursor] = ch;
				cursor = (cursor+1)%32;
			}
		//PUTCHAR(ch);
		}
	}
}

