################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
ADC/%.obj: ../ADC/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/Programmi/ti/ccs1210/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/Programmi/ti/ccs1210/ccs/ccs_base/arm/include" --include_path="D:/Programmi/simplelink_msp432p4_sdk_3_40_01_02/source" --include_path="D:/Programmi/ti/ccs1210/ccs/ccs_base/arm/include/CMSIS" --include_path="D:/Gakkou/thirdYear/I_semestre/EmbeededSWforIoT/WorkSpace/EmbeddedBros2" --include_path="D:/Programmi/ti/ccs1210/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="ADC/$(basename $(<F)).d_raw" --obj_directory="ADC" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


