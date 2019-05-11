# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../src/Blink.c

OBJS +=  \
Blink.o

OBJS_AS_ARGS +=  \
Blink.o

C_DEPS +=  \
Blink.d

C_DEPS_AS_ARGS +=  \
Blink.d

OUTPUT_FILE_PATH +=Blink.elf

OUTPUT_FILE_PATH_AS_ARGS +=Blink.elf

OUTPUT_FILE_DEP:= ./makedep.mk


# AVR32/GNU C Compiler


%.o: ../src/%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Programs\AtmelStudio_7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Programs\AtmelStudio_7.0\7.0\Packs\atmel\ATmega_DFP\1.2.132\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32a -B "D:\Programs\AtmelStudio_7.0\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega32a" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)D:\Programs\AtmelStudio_7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="Blink.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega32a -B "D:\Programs\AtmelStudio_7.0\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega32a"  
	@echo Finished building target: $@
	"D:\Programs\AtmelStudio_7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "Blink.elf" "Blink.hex"
	"D:\Programs\AtmelStudio_7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "Blink.elf" "Blink.eep" || exit 0
	"D:\Programs\AtmelStudio_7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "Blink.elf" > "Blink.lss"
	"D:\Programs\AtmelStudio_7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "Blink.elf" "Blink.srec"
	"D:\Programs\AtmelStudio_7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "Blink.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "Blink.elf" "Blink.a" "Blink.hex" "Blink.lss" "Blink.eep" "Blink.map" "Blink.srec" "Blink.usersignatures"
	