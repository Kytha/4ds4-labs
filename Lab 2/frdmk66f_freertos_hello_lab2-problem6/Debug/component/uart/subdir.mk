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
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MK66FN2M0VMD18 -DCPU_MK66FN2M0VMD18_cm4 -DFRDM_K66F -DFREEDOM -DSERIAL_PORT_TYPE_UART=1 -DSDK_OS_FREE_RTOS -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/home/ds/Desktop/4ds4/lab 2/Problem5/frdmk66f_freertos_hello_lab2-problem6/board" -I"/home/ds/Desktop/4ds4/lab 2/Problem5/frdmk66f_freertos_hello_lab2-problem6/source" -I"/home/ds/Desktop/4ds4/lab 2/Problem5/frdmk66f_freertos_hello_lab2-problem6/drivers" -I"/home/ds/Desktop/4ds4/lab 2/Problem5/frdmk66f_freertos_hello_lab2-problem6/device" -I"/home/ds/Desktop/4ds4/lab 2/Problem5/frdmk66f_freertos_hello_lab2-problem6/utilities" -I"/home/ds/Desktop/4ds4/lab 2/Problem5/frdmk66f_freertos_hello_lab2-problem6/component/uart" -I"/home/ds/Desktop/4ds4/lab 2/Problem5/frdmk66f_freertos_hello_lab2-problem6/component/serial_manager" -I"/home/ds/Desktop/4ds4/lab 2/Problem5/frdmk66f_freertos_hello_lab2-problem6/component/lists" -I"/home/ds/Desktop/4ds4/lab 2/Problem5/frdmk66f_freertos_hello_lab2-problem6/CMSIS" -I"/home/ds/Desktop/4ds4/lab 2/Problem5/frdmk66f_freertos_hello_lab2-problem6/freertos/freertos_kernel/include" -I"/home/ds/Desktop/4ds4/lab 2/Problem5/frdmk66f_freertos_hello_lab2-problem6/freertos/freertos_kernel/portable/GCC/ARM_CM4F" -O0 -fno-common -g3 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


