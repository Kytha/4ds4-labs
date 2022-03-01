################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../component/uart/fsl_adapter_uart.c 

OBJS += \
./component/uart/fsl_adapter_uart.o 

C_DEPS += \
./component/uart/fsl_adapter_uart.d 


# Each subdirectory must supply rules for building sources it contributes
component/uart/%.o: ../component/uart/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MK66FN2M0VMD18 -DCPU_MK66FN2M0VMD18_cm4 -DFRDM_K66F -DFREEDOM -DSERIAL_PORT_TYPE_UART=1 -DSDK_OS_FREE_RTOS -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/4ds4-labs/Lab 2/experiment_4/board" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/4ds4-labs/Lab 2/experiment_4/source" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/4ds4-labs/Lab 2/experiment_4/drivers" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/4ds4-labs/Lab 2/experiment_4/device" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/4ds4-labs/Lab 2/experiment_4/utilities" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/4ds4-labs/Lab 2/experiment_4/component/uart" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/4ds4-labs/Lab 2/experiment_4/component/serial_manager" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/4ds4-labs/Lab 2/experiment_4/component/lists" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/4ds4-labs/Lab 2/experiment_4/CMSIS" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/4ds4-labs/Lab 2/experiment_4/freertos/freertos_kernel/include" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/4ds4-labs/Lab 2/experiment_4/freertos/freertos_kernel/portable/GCC/ARM_CM4F" -O0 -fno-common -g3 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


