################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/AEB_Program.c \
../src/Car_Movement_program.c \
../src/DCmotor_program.c \
../src/EXTI_program.c \
../src/FCW_Program.c \
../src/GPIO_Program.c \
../src/RCC_program.c \
../src/TF_LUNA_LIDAR_PROGRAM.c \
../src/Timer_program.c \
../src/UART_program.c \
../src/main.c 

OBJS += \
./src/AEB_Program.o \
./src/Car_Movement_program.o \
./src/DCmotor_program.o \
./src/EXTI_program.o \
./src/FCW_Program.o \
./src/GPIO_Program.o \
./src/RCC_program.o \
./src/TF_LUNA_LIDAR_PROGRAM.o \
./src/Timer_program.o \
./src/UART_program.o \
./src/main.o 

C_DEPS += \
./src/AEB_Program.d \
./src/Car_Movement_program.d \
./src/DCmotor_program.d \
./src/EXTI_program.d \
./src/FCW_Program.d \
./src/GPIO_Program.d \
./src/RCC_program.d \
./src/TF_LUNA_LIDAR_PROGRAM.d \
./src/Timer_program.d \
./src/UART_program.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


