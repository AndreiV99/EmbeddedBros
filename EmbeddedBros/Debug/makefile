################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/Programmi/ti/ccs1210/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./Crystalfontz128x128_ST7735.obj" \
"./HAL_I2C.obj" \
"./HAL_MSP_EXP432P401R_Crystalfontz128x128_ST7735.obj" \
"./HAL_TMP006.obj" \
"./main.obj" \
"./startup_msp432p401r_ccs.obj" \
"./system_msp432p401r.obj" \
"./ADC/adc.obj" \
"./Buzzer/buzzer.obj" \
"./Display/display.obj" \
"./Images/boo.obj" \
"./Images/go.obj" \
"./Images/goomba.obj" \
"./Images/mario.obj" \
"./Images/marioMini.obj" \
"./Images/one.obj" \
"./Images/sonic.obj" \
"./Images/sonicMini.obj" \
"./Images/three.obj" \
"./Images/toad.obj" \
"./Images/toadMini.obj" \
"./Images/two.obj" \
"./Images/yoshi.obj" \
"./Images/yoshiMini.obj" \
"./LED/led.obj" \
"./Timer/timer.obj" \
"../msp432p401r.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \
-l"D:/Programmi/simplelink_msp432p4_sdk_3_40_01_02/source/ti/devices/msp432p4xx/driverlib/ccs/msp432p4xx_driverlib.lib" \
-l"D:/Programmi/simplelink_msp432p4_sdk_3_40_01_02/source/ti/grlib/lib/ccs/m4f/grlib.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include ADC/subdir_vars.mk
-include Buzzer/subdir_vars.mk
-include Display/subdir_vars.mk
-include Images/subdir_vars.mk
-include LED/subdir_vars.mk
-include Timer/subdir_vars.mk
-include subdir_rules.mk
-include ADC/subdir_rules.mk
-include Buzzer/subdir_rules.mk
-include Display/subdir_rules.mk
-include Images/subdir_rules.mk
-include LED/subdir_rules.mk
-include Timer/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
EmbeddedBros2.out \

EXE_OUTPUTS__QUOTED += \
"EmbeddedBros2.out" \

BIN_OUTPUTS += \
EmbeddedBros2.hex \

BIN_OUTPUTS__QUOTED += \
"EmbeddedBros2.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "EmbeddedBros2.out"

# Tool invocations
EmbeddedBros2.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: Arm Linker'
	"D:/Programmi/ti/ccs1210/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"EmbeddedBros2.map" --heap_size=1024 --stack_size=512 -i"D:/Programmi/ti/ccs1210/ccs/ccs_base/arm/include" -i"D:/Programmi/ti/ccs1210/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/lib" -i"D:/Programmi/ti/ccs1210/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="EmbeddedBros2_linkInfo.xml" --rom_model -o "EmbeddedBros2.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

EmbeddedBros2.hex: $(EXE_OUTPUTS)
	@echo 'Building secondary target: "$@"'
	@echo 'Invoking: Arm Hex Utility'
	"D:/Programmi/ti/ccs1210/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armhex" --memwidth=8 --romwidth=8 --diag_wrap=off -o "EmbeddedBros2.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building secondary target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "Crystalfontz128x128_ST7735.obj" "HAL_I2C.obj" "HAL_MSP_EXP432P401R_Crystalfontz128x128_ST7735.obj" "HAL_TMP006.obj" "main.obj" "startup_msp432p401r_ccs.obj" "system_msp432p401r.obj" "ADC\adc.obj" "Buzzer\buzzer.obj" "Display\display.obj" "Images\boo.obj" "Images\go.obj" "Images\goomba.obj" "Images\mario.obj" "Images\marioMini.obj" "Images\one.obj" "Images\sonic.obj" "Images\sonicMini.obj" "Images\three.obj" "Images\toad.obj" "Images\toadMini.obj" "Images\two.obj" "Images\yoshi.obj" "Images\yoshiMini.obj" "LED\led.obj" "Timer\timer.obj" 
	-$(RM) "Crystalfontz128x128_ST7735.d" "HAL_I2C.d" "HAL_MSP_EXP432P401R_Crystalfontz128x128_ST7735.d" "HAL_TMP006.d" "main.d" "startup_msp432p401r_ccs.d" "system_msp432p401r.d" "ADC\adc.d" "Buzzer\buzzer.d" "Display\display.d" "Images\boo.d" "Images\go.d" "Images\goomba.d" "Images\mario.d" "Images\marioMini.d" "Images\one.d" "Images\sonic.d" "Images\sonicMini.d" "Images\three.d" "Images\toad.d" "Images\toadMini.d" "Images\two.d" "Images\yoshi.d" "Images\yoshiMini.d" "LED\led.d" "Timer\timer.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

