#define F_CPU 16000000UL // 16 Mhz clock speed
#ifndef __AVR_ATmega32A__
    #define __AVR_ATmega32A__
#endif

#define BAUDRATE 9600
#define BAUD_PRESCALLER ((F_CPU/(BAUDRATE * 16UL)) - 1)

#include <avr/io.h>
#include <util/delay.h>

// Initialize USART
void USART_init(void);
// READ Byte form USART
unsigned char USART_receive(void);
void USART_send(unsigned char data);
void USART_putString(char* stringPtr);

char string[] = "Hello World Bartek \n\r\n";

int main(int argc, char** argv) {
    DDRC |= (1 << PINC0);
    PORTC |= (1 << PINC0);
    USART_init();

    while(1) {
        USART_putString(string);
        if(bit_is_clear(PORTC, 0)) {
            PORTC |= (1 << PINC0);
        }
        else {
            PORTC &= ~(1 << PINC0);
        }
        _delay_ms(3000);
    }
    return 0;
}

void USART_init(void) {
    UBRRH = (uint8_t)(BAUD_PRESCALLER>>8);
    UBRRL = (uint8_t)(BAUD_PRESCALLER);

    UCSRB = (1<<RXEN)|(1<<TXEN); // Enable read and write
    UCSRC = (1<<UCSZ0)|(1<<UCSZ1)|(1<<URSEL); // 
}

unsigned char USART_receive(void) {
    while(!(UCSRA & (1<<RXC)));
    return UDR;
}

void USART_send(unsigned char data) {
    while(!(UCSRA & (1 << UDRE)));
    UDR = data;
}

void USART_putString(char* stringPtr) {
    while(*stringPtr != 0x00) {
        USART_send(*stringPtr);
        stringPtr++;
    }
}