################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Aplicaciones/app_Endstops.c \
../Aplicaciones/app_PIT.c \
../Aplicaciones/app_StepperMotors.c 

OBJS += \
./Aplicaciones/app_Endstops.o \
./Aplicaciones/app_PIT.o \
./Aplicaciones/app_StepperMotors.o 

C_DEPS += \
./Aplicaciones/app_Endstops.d \
./Aplicaciones/app_PIT.d \
./Aplicaciones/app_StepperMotors.d 


# Each subdirectory must supply rules for building sources it contributes
Aplicaciones/%.o: ../Aplicaciones/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DDEBUG -DFRDM_KL25Z -DFREEDOM -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DSDK_OS_BAREMETAL -DFSL_RTOS_BM -I"/home/dario/Modular_Board/frdmkl25z_Modular_code/drivers" -I"/home/dario/Modular_Board/frdmkl25z_Modular_code/utilities" -I"/home/dario/Modular_Board/frdmkl25z_Modular_code/CMSIS" -I"/home/dario/Modular_Board/frdmkl25z_Modular_code/board" -I"/home/dario/Modular_Board/frdmkl25z_Modular_code/source" -I"/home/dario/Modular_Board/frdmkl25z_Modular_code" -I"/home/dario/Modular_Board/frdmkl25z_Modular_code/drivers" -I"/home/dario/Modular_Board/frdmkl25z_Modular_code/CMSIS" -I"/home/dario/Modular_Board/frdmkl25z_Modular_code/utilities" -I"/home/dario/Modular_Board/frdmkl25z_Modular_code/startup" -O0 -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


