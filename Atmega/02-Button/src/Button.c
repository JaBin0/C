#define F_CPU 16000000UL // 16 Mhz clock speed
#ifndef __AVR_ATmega32A__
    #define __AVR_ATmega32A__
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(int argc, char** argv) {
    DDRC = 0x03;
    PORTC |= (1<<PINC0);
    PORTC |= (1<<PINC2);

    uint8_t pressed = 0;

    while(1) {
        if (bit_is_clear(PINC, 2)) {
            // It is needed inside, if not pressed will be switched during one click
            if(pressed == 0) {
                pressed = 1;
                PORTC ^= (1<<PINC0);
                PORTC ^= (1<<PINC1);
            }
        }
        else {
            pressed = 0;
        }
    }
    return 0;
}