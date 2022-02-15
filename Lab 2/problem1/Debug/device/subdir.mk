################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../device/system_MK66F18.c 

OBJS += \
./device/system_MK66F18.o 

C_DEPS += \
./device/system_MK66F18.d 


# Each subdirectory must supply rules for building sources it contributes
device/%.o: ../device/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MK66FN2M0VMD18 -DCPU_MK66FN2M0VMD18_cm4 -DFRDM_K66F -DFREEDOM -DSERIAL_PORT_TYPE_UART=1 -DSDK_OS_FREE_RTOS -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello/board" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello/source" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello/drivers" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello/device" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello/utilities" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello/component/uart" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello/component/serial_manager" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello/component/lists" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello/CMSIS" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello/freertos/freertos_kernel/include" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello/freertos/freertos_kernel/portable/GCC/ARM_CM4F" -O0 -fno-common -g3 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


