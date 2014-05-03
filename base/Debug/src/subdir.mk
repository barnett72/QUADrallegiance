################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/controller.cpp \
../src/main.cpp \
../src/stick.cpp \
../src/transmitter.cpp \
../src/trigger.cpp 

OBJS += \
./src/controller.o \
./src/main.o \
./src/stick.o \
./src/transmitter.o \
./src/trigger.o 

CPP_DEPS += \
./src/controller.d \
./src/main.d \
./src/stick.d \
./src/transmitter.d \
./src/trigger.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -std=c++11 -I"/home/matt/workspace/rpi/wiringPi" -I"/home/matt/workspace/rpi/base/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


