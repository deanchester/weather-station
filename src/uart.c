#include <avr/io.h>

#include "uart.h"

void USART_INIT(){
        UCSRA = 0x00;
        UCSRB = (1<<RXEN)|(1<<TXEN);
        UCSRC = 0x86;
        
        UBRRH = 0x00;
        UBRRL = 0x40;
}

void USART_Transmit(unsigned char data) {
        /* Wait for empty transmit buffer */ 
        //while ( !( UCSRA & (1<<UDRE)) );
        while((UCSRA & 0x20) == 0x00);
        /* Put data into buffer, sends the data */ 
        UDR = data;
}



unsigned char USART_Receive(void) {
        /* Wait for empty transmit buffer */ 
        //while ( !( UCSRA & (1<<UDRE)) );
        while((UCSRA & 0x80) == 0x00);
        /* Put data into buffer, sends the data */ 
        return UDR;
}