#ifndef __USART__
#define __USART__

#define BAUDRATE 9600
#define BAUD_PRESCALLER ((F_CPU/(BAUDRATE * 16UL)) - 1)

// Initialize USART
void USART_init(void);

// READ Byte form USART
unsigned char USART_receive(void);

// Send Byte over USART
void USART_send(unsigned char data);

// Send string over USART
void USART_putString(char* stringPtr);
#endif