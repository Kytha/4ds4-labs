################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include utilities/subdir.mk
-include startup/subdir.mk
-include source/subdir.mk
-include freertos/freertos_kernel/portable/MemMang/subdir.mk
-include freertos/freertos_kernel/portable/GCC/ARM_CM4F/subdir.mk
-include freertos/freertos_kernel/subdir.mk
-include drivers/subdir.mk
-include device/subdir.mk
-include component/uart/subdir.mk
-include component/serial_manager/subdir.mk
-include component/lists/subdir.mk
-include board/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: frdmk66f_freertos_hello_lab2-problem4c.axf

# Tool invocations
frdmk66f_freertos_hello_lab2-problem4c.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="frdmk66f_freertos_hello_lab2-problem4c.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -Xlinker --cref -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -T frdmk66f_freertos_hello_lab2-problem4c_Debug.ld -o "frdmk66f_freertos_hello_lab2-problem4c.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) frdmk66f_freertos_hello_lab2-problem4c.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "frdmk66f_freertos_hello_lab2-problem4c.axf"; # arm-none-eabi-objcopy -v -O binary "frdmk66f_freertos_hello_lab2-problem4c.axf" "frdmk66f_freertos_hello_lab2-problem4c.bin" ; # checksum -p MK66FN2M0xxx18 -d "frdmk66f_freertos_hello_lab2-problem4c.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
