################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include USART/subdir.mk
-include Keypad/subdir.mk
-include GIE/subdir.mk
-include EXITI/subdir.mk
-include DIO/subdir.mk
-include ADC/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
SEND.lss \

FLASH_IMAGE += \
SEND.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: SEND.elf secondary-outputs

# Tool invocations
SEND.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SEND.map -mmcu=atmega32 -o "SEND.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SEND.lss: SEND.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SEND.elf  >"SEND.lss"
	@echo 'Finished building: $@'
	@echo ' '

SEND.hex: SEND.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SEND.elf  "SEND.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SEND.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SEND.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SEND.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
