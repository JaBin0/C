// Own headers
#include <BasicVariables.h>
#include <USART.h>

// System headers
#include <avr/io.h>

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