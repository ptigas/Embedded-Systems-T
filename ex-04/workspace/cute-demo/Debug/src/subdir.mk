################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Test.cpp \
../src/demo.cpp 

OBJS += \
./src/Test.o \
./src/demo.o 

CPP_DEPS += \
./src/Test.d \
./src/demo.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"C:\Users\pkesseli\Software\cpp\embedded-programming\ex-03\workspace\cute-demo\cute" -I"C:\Users\pkesseli\Software\cpp\embedded-programming\ex-03\workspace\cute-demo\boost" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


