#ifndef LED_COMPONENT_H
#define LED_COMPONENT_H

#include "pin_mux.h"
#include "fsl_port.h"
#include "fsl_ftm.h"
#include "fsl_debug_console.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "Motor_Control_Component.h"
#include "Terminal_Component.h"

#include <stdarg.h>

#define FTM_LED 				FTM3
#define FTM_RED_CHANNEL			kFTM_Chnl_1
#define FTM_GREEN_CHANNEL		kFTM_Chnl_5
#define FTM_BLUE_CHANNEL		kFTM_Chnl_4

extern QueueHandle_t led_queue;

void setupLEDComponent();
void setupLEDs();
void setupLEDPins();

void ledTask(void* pvParameters);

#endif /* TERMINAL_COMPONENT_H */
