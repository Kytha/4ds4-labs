################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../freertos/freertos_kernel/croutine.c \
../freertos/freertos_kernel/event_groups.c \
../freertos/freertos_kernel/list.c \
../freertos/freertos_kernel/queue.c \
../freertos/freertos_kernel/stream_buffer.c \
../freertos/freertos_kernel/tasks.c \
../freertos/freertos_kernel/timers.c 

OBJS += \
./freertos/freertos_kernel/croutine.o \
./freertos/freertos_kernel/event_groups.o \
./freertos/freertos_kernel/list.o \
./freertos/freertos_kernel/queue.o \
./freertos/freertos_kernel/stream_buffer.o \
./freertos/freertos_kernel/tasks.o \
./freertos/freertos_kernel/timers.o 

C_DEPS += \
./freertos/freertos_kernel/croutine.d \
./freertos/freertos_kernel/event_groups.d \
./freertos/freertos_kernel/list.d \
./freertos/freertos_kernel/queue.d \
./freertos/freertos_kernel/stream_buffer.d \
./freertos/freertos_kernel/tasks.d \
./freertos/freertos_kernel/timers.d 


# Each subdirectory must supply rules for building sources it contributes
freertos/freertos_kernel/%.o: ../freertos/freertos_kernel/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MK66FN2M0VMD18 -DCPU_MK66FN2M0VMD18_cm4 -DFRDM_K66F -DFREEDOM -DSERIAL_PORT_TYPE_UART=1 -DSDK_OS_FREE_RTOS -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello/board" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello/source" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello/drivers" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello/device" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello/utilities" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello/component/uart" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello/component/serial_manager" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello/component/lists" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello/CMSIS" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello/freertos/freertos_kernel/include" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/frdmk66f_freertos_hello/freertos/freertos_kernel/portable/GCC/ARM_CM4F" -O0 -fno-common -g3 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


