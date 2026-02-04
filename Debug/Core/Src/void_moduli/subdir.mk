################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/void_moduli/ax12.c \
../Core/Src/void_moduli/enc.c \
../Core/Src/void_moduli/ir_sensor.c \
../Core/Src/void_moduli/odom.c \
../Core/Src/void_moduli/position.c \
../Core/Src/void_moduli/pwm.c \
../Core/Src/void_moduli/servo.c 

OBJS += \
./Core/Src/void_moduli/ax12.o \
./Core/Src/void_moduli/enc.o \
./Core/Src/void_moduli/ir_sensor.o \
./Core/Src/void_moduli/odom.o \
./Core/Src/void_moduli/position.o \
./Core/Src/void_moduli/pwm.o \
./Core/Src/void_moduli/servo.o 

C_DEPS += \
./Core/Src/void_moduli/ax12.d \
./Core/Src/void_moduli/enc.d \
./Core/Src/void_moduli/ir_sensor.d \
./Core/Src/void_moduli/odom.d \
./Core/Src/void_moduli/position.d \
./Core/Src/void_moduli/pwm.d \
./Core/Src/void_moduli/servo.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/void_moduli/%.o Core/Src/void_moduli/%.su Core/Src/void_moduli/%.cyclo: ../Core/Src/void_moduli/%.c Core/Src/void_moduli/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-void_moduli

clean-Core-2f-Src-2f-void_moduli:
	-$(RM) ./Core/Src/void_moduli/ax12.cyclo ./Core/Src/void_moduli/ax12.d ./Core/Src/void_moduli/ax12.o ./Core/Src/void_moduli/ax12.su ./Core/Src/void_moduli/enc.cyclo ./Core/Src/void_moduli/enc.d ./Core/Src/void_moduli/enc.o ./Core/Src/void_moduli/enc.su ./Core/Src/void_moduli/ir_sensor.cyclo ./Core/Src/void_moduli/ir_sensor.d ./Core/Src/void_moduli/ir_sensor.o ./Core/Src/void_moduli/ir_sensor.su ./Core/Src/void_moduli/odom.cyclo ./Core/Src/void_moduli/odom.d ./Core/Src/void_moduli/odom.o ./Core/Src/void_moduli/odom.su ./Core/Src/void_moduli/position.cyclo ./Core/Src/void_moduli/position.d ./Core/Src/void_moduli/position.o ./Core/Src/void_moduli/position.su ./Core/Src/void_moduli/pwm.cyclo ./Core/Src/void_moduli/pwm.d ./Core/Src/void_moduli/pwm.o ./Core/Src/void_moduli/pwm.su ./Core/Src/void_moduli/servo.cyclo ./Core/Src/void_moduli/servo.d ./Core/Src/void_moduli/servo.o ./Core/Src/void_moduli/servo.su

.PHONY: clean-Core-2f-Src-2f-void_moduli

