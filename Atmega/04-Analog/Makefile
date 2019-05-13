# Add inputs and outputs from these tool invocations to the build variables 
# Name of the project
NAME:=Analog

CC:=avr-gcc 

# Path to the avr-gcc
AVR_GCC_PATH:= D:\Programs\AtmelStudio_7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin

# Add avr-gcc path to the environment variables
export PATH := $(AVR_GCC_PATH);$(PATH)

# Switch comments if debug is needed
#DEBUG:=-DDEBUG
DEBUG:= 

LFLAGS:=\
-funsigned-char \
-funsigned-bitfields

BUILD_DIR:=build/

# Object folder
ODIR:=build/obj

# Define include path
INCLUDE_PATH:=\
-I"D:\Programs\AtmelStudio_7.0\7.0\Packs\atmel\ATmega_DFP\1.2.132\include" \
-I"src"


# Define list of source files
C_SRCS +=\
src/main.c \
src/USART.c

# Define list of object files
_OBJS += \
main.o \
USART.o

C_DEPS +=  \
main.d += \
USART.d

OBJS_AS_ARGS = $(patsubst %,$(ODIR)/%,$(_OBJS))
C_DEPS_AS_ARGS +=  $(patsubst %,$(ODIR)/%,$(C_DEPS))

OUTPUT_FILE_PATH +=$(NAME).elf

OUTPUT_FILE_PATH_AS_ARGS +=$(BUILD_DIR)$(NAME).elf

OUTPUT_FILE_DEP:= $(BUILD_DIR)./makedep.mk


# AVR32/GNU C Compiler
$(ODIR)/%.o: src/%.c
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	@echo Creating object folder
	if not exist $(BUILD_DIR)obj mkdir $(BUILD_DIR)obj
	@echo Building file: $<
	$(CC) -x c -o $@ $< $(LFLAGS)$(DEBUG) $(INCLUDE_PATH)  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32a -B "D:\Programs\AtmelStudio_7.0\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega32a" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"
	@echo Finished building: $<
	@echo .  

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)
	
$(OUTPUT_FILE_PATH): $(OBJS_AS_ARGS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Invoking: AVR/GNU Linker : 5.4.0
	@echo Building target: $@
	$(CC) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="$(BUILD_DIR)$(NAME).map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega32a -B "D:\Programs\AtmelStudio_7.0\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega32a"  
	@echo Finished building target: $@
	"D:\Programs\AtmelStudio_7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "$(BUILD_DIR)$(NAME).elf" "$(BUILD_DIR)$(NAME).hex"
	"D:\Programs\AtmelStudio_7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "$(BUILD_DIR)$(NAME).elf" "$(BUILD_DIR)$(NAME).eep" || exit 0
	"D:\Programs\AtmelStudio_7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "$(BUILD_DIR)$(NAME).elf" > "$(BUILD_DIR)$(NAME).lss"
	"D:\Programs\AtmelStudio_7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "$(BUILD_DIR)$(NAME).elf" "$(BUILD_DIR)$(NAME).srec"
	"D:\Programs\AtmelStudio_7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "$(BUILD_DIR)$(NAME).elf"

# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS)
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "$(BUILD_DIR)$(NAME).elf" "$(BUILD_DIR)$(NAME).a" "$(BUILD_DIR)$(NAME).hex" "$(BUILD_DIR)$(NAME).lss" "$(BUILD_DIR)$(NAME).eep" "$(BUILD_DIR)$(NAME).map" "$(BUILD_DIR)$(NAME).srec" "$(BUILD_DIR)$(NAME).usersignatures"
	