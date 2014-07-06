#include <avr/io.h>

#include "adc.h"

void ADC_INIT(){
        ADMUX = 0x00;
        ADCSRA = 0xC3;
        
        while(!(ADCSRA & 0x10));
        
        ADCSRA |= 0x10;
}

unsigned int ADC_Read(unsigned char channel){
        ADMUX = channel;
        ADCSRA |= 0x43;
        unsigned int val, low_val, high_val;
        
        while(!(ADCSRA & 0x10));
        
        ADCSRA |= 0x10;
        
        low_val = ADCL;
        high_val = ((unsigned int) (ADCH << 8));
        val = low_val | high_val;
        
        return val;
}