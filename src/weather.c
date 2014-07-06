#include <avr/io.h>

#include "uart.h"

void init(){
        USART_INIT();
}

int main (void){
        init();
}