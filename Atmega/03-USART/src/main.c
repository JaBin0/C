// Own include
#include <BasicVariables.h>
#include <USART.h>

// System include
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

char string[] = "\rUSART proof of concept\n\r\n";
char numberStr[10];
uint16_t number;

int main(int argc, char** argv) {
    DDRC |= (1 << PINC0);
    PORTC |= (1 << PINC0);

    USART_init();

    number = 0;
    USART_putString(string);

    while(1) {
        sprintf(numberStr, "%d\n\r", number);
        USART_putString(numberStr);
        number+=2;
        if(bit_is_clear(PORTC, 0)) {
            PORTC |= (1 << PINC0);
        }
        else {
            PORTC &= ~(1 << PINC0);
        }
        _delay_ms(1000);
    }
    return 0;
}