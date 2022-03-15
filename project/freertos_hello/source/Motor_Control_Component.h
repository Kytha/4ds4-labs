#ifndef MOTOR_CONTROL_COMPONENT_H
#define MOTOR_CONTROL_COMPONENT_H

#include "pin_mux.h"
#include "fsl_port.h"
#include "fsl_ftm.h"
#include "fsl_debug_console.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "Terminal_Component.h"

#define FTM_MOTORS				FTM0
#define FTM_CHANNEL_DC_MOTOR	kFTM_Chnl_0
#define FTM_CHANNEL_SERVOMOTOR	kFTM_Chnl_3

enum MOTOR_MODE
{
	STOP = 0,
	REVERSE = 1,
	FORWARD =2
};
struct MotorMessage
{
	uint16_t speed;
	uint16_t mode;
};

extern QueueHandle_t motor_queue, angle_queue;

void setupMotorComponent();
void setupDCMotor();
void setupServo();
void setupMotorPins();
void setupPWM();

void updatePWM_dutyCycle(ftm_chnl_t channel, float dutyCycle);

void motorTask(void* pvParameters);
void positionTask(void* pvParameters);


#endif /* MOTOR_CONTROL_COMPONENT_H */
