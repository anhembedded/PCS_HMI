################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Project/CaoThangFinalProject/Test/Core/u_task/Src/u_applicationTask.c 

C_DEPS += \
./Application/User/u_task/Src/u_applicationTask.d 

OBJS += \
./Application/User/u_task/Src/u_applicationTask.o 


# Each subdirectory must supply rules for building sources it contributes
Application/User/u_task/Src/u_applicationTask.o: C:/Project/CaoThangFinalProject/Test/Core/u_task/Src/u_applicationTask.c Application/User/u_task/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../../Core/Inc -I"C:/Project/CaoThangFinalProject/Test/Core/u_task/Inc" -I"C:/Project/CaoThangFinalProject/Test/Core/u_driver/inc" -I../../Drivers/CMSIS/Include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/target -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../TouchGFX/App -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/target/generated -I../../Drivers/BSP/Components/Common -I../../TouchGFX/gui/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/images/include -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/BSP/STM32469I-Discovery -I../../TouchGFX/generated/fonts/include -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../TouchGFX/generated/videos/include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-u_task-2f-Src

clean-Application-2f-User-2f-u_task-2f-Src:
	-$(RM) ./Application/User/u_task/Src/u_applicationTask.cyclo ./Application/User/u_task/Src/u_applicationTask.d ./Application/User/u_task/Src/u_applicationTask.o ./Application/User/u_task/Src/u_applicationTask.su

.PHONY: clean-Application-2f-User-2f-u_task-2f-Src

