/*
 * GPIO.h
 *
 * Created: 6/26/2017 12:05:16 PM
 *  Author: AYA SAMEH
 *
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include "std_macros.h"

#define INIT_GPIO_PORT DDRD |= 0x80; DDRC |= 0x0c;
 
#define LED_ON     (CLRBIT(PORTD,PD7));
#define LED_OFF    (SETBIT(PORTD,PD7));
#define Fan_ON     (SETBIT(PORTC,PC2));
#define Fan_OFF    (CLRBIT(PORTC,PC2));
#define Servo_ON   (SETBIT(PORTC,PC3));
#define Servo_OFF  (CLRBIT(PORTC,PC3));

#endif /* GPIO_H_ */