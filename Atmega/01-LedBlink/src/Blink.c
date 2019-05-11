#define F_CPU 16000000UL // 16 Mhz clock speed
#define __AVR_ATmega32A__

#include <avr/io.h>
#include <util/delay.h>

int main(int argc, char** argv) {
    DDRC = 0xFF;

    while(1) {
        PORTC = 0xFF;
        _delay_ms(1200);
        PORTC = 0x00;
        _delay_ms(1200);
    }
    return 0;
}