/*
 * ADC.h
 *
 * Created: 11/26/2014 5:45:32 PM
 *  Author: safifi
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "std_macros.h"
void ADC_init();
uint16_t ADC_read(uint8_t channel_num);

#endif /* ADC_H_ */