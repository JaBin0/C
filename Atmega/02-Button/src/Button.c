#define F_CPU 16000000UL // 16 Mhz clock speed
#ifndef __AVR_ATmega32A__
#define __AVR_ATmega32A__
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(int argc, char** argv) {
    DDRC = 0xFF;

    while(1) {
        PORTC = 0xFF;
        _delay_ms(100);
        PORTC = 0x00;
        _delay_ms(100);
    }
    return 0;
}