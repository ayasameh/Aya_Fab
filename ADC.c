/*
 * ADC.
 *
 * Created: 11/26/2014 5:46:08 PM
 *  Author: safifi
 */ 
#include"ADC.h"

void ADC_init(){
	ADCSRA = 0b10000111;
	ADMUX = 0x40;
}
uint16_t ADC_read(uint8_t channel_num){
	ADMUX = 0x40+channel_num;
	ADCSRA |= 1<<6;
	while((ADCSRA & 1<<6));
	return (ADCL+ (ADCH << 8));
}

	