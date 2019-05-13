// Own include
#include <BasicVariables.h>
#include <USART.h>

// System include
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

char helloMsg[] = "\rAnalog to digital converter\n\r\n";
char breakLine[3] = "\n\r";
char numberStr[10];

int main(int argc, char** argv) {
    USART_init();
    USART_putString(helloMsg);

    // Configure ADC 
    // Set Pin 0 of PORTA for ADC  by writing 00000 for MUX4-0
    ADMUX &= ~((1<<MUX0) | (1<<MUX1) | (1<<MUX2) | (1<<MUX3) | (1<<MUX4));
    // Set shifting so for ADLAR == 1 ADCH will contain 8 bits form 2 to 9 and ADCL will
    // contain bit 0 and bit 1 of the value on his bit 6 and 7 (indexed from 0) 
    ADMUX |= (1<<ADLAR);
    // Set AVCC as reference voltage - REFS 01
    ADMUX |= (1<<REFS0);
    // Set prescaler, clock 16MHz, sampling rate between (50KHz: 200KHz),
    // 16MHz/50KHz = 320, 16Mhz/200KHz = 80, so prescaler should be between 80;320
    // Only value within this range is 128  
    ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
    // Enable ADC interrupts
    ADCSRA |= (1<<ADIE);
    // Trun on the ACD
    ADCSRA |= (1<<ADEN);
    // Enable the global interrupts
    sei();
    // Start the first conversion
    ADCSRA |= (1<<ADSC);

    // Set LED to see that program working
    DDRC |= (1 << PINC0);
    PORTC |= (1 << PINC0);

    while(1) {
    }
    return 0;
}

// Interrupt routine
ISR(ADC_vect) {
    // Read value
    char adcResult[5];
    uint8_t adcl = ADCL>>6;
    uint8_t adch = ADCH;
    uint16_t result = (ADCH<<2) | (adcl);
    sprintf(adcResult, "%d", result);
    //uint16_t result = (ADCH<<2) | (ADCL>>6);
    // Convert ADC to the string
    //itoa(ADCH, adcResult, 10);
    // Send the string to the COM port
    USART_putString(adcResult);
    USART_putString(breakLine);
    ADCSRA |= (1<<ADSC);
}

// Start the next conversion
