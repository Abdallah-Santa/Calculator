################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Calculator.c \
../HKPD__Program.c \
../HLCD_Program.c \
../MDIO_Program.c 

OBJS += \
./Calculator.o \
./HKPD__Program.o \
./HLCD_Program.o \
./MDIO_Program.o 

C_DEPS += \
./Calculator.d \
./HKPD__Program.d \
./HLCD_Program.d \
./MDIO_Program.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


