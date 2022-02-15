################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../component/serial_manager/fsl_component_serial_manager.c \
../component/serial_manager/fsl_component_serial_port_uart.c 

OBJS += \
./component/serial_manager/fsl_component_serial_manager.o \
./component/serial_manager/fsl_component_serial_port_uart.o 

C_DEPS += \
./component/serial_manager/fsl_component_serial_manager.d \
./component/serial_manager/fsl_component_serial_port_uart.d 


# Each subdirectory must supply rules for building sources it contributes
component/serial_manager/%.o: ../component/serial_manager/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCPU_MK66FN2M0VMD18 -DCPU_MK66FN2M0VMD18_cm4 -DFRDM_K66F -DFREEDOM -DSERIAL_PORT_TYPE_UART=1 -DSDK_OS_FREE_RTOS -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello_problem2/board" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello_problem2/source" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello_problem2/drivers" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello_problem2/device" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello_problem2/utilities" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello_problem2/component/uart" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello_problem2/component/serial_manager" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello_problem2/component/lists" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello_problem2/CMSIS" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello_problem2/freertos/freertos_kernel/include" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello_problem2/freertos/freertos_kernel/portable/GCC/ARM_CM4F" -O0 -fno-common -g3 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


