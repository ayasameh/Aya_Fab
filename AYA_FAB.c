/*
 * AYA_FAB.c
 *
 * Created: 6/24/2017 2:01:13 PM
 * Author: AYA SAMEH
 *
 */ 

#include "UART.h"
#include "lcd.h"
#include "GPIO.h"
#include "ADC.h"
#include "Ultrasonic.h"

int main(void)
{
	
	Uart_init(9600);
	lcd_init();
	ADC_init();
	Ultrasonic_init();
	
	INIT_GPIO_PORT;
	PORTD = 0xff;
	
	Fan_OFF;    // on PC2
	Servo_OFF;  // on PC3
	
	uint8_t ch;
	uint8_t control_flag = 0;
	uint16_t LightSensivity = 300;
	uint16_t TempThreshold = 72;
	
	lcd_write_txt(" Home Automation ");
	_delay_ms(1000);
	
    while(1)
    {
		uint32_t distance = Ultrasonic_Read();
		lcd_write_cmd(nd_line);
		lcd_write_txt("Distance: ");
		lcd_write_txt(nd_line+12);
		lcd_write_number(distance);
		
		if (Uart_available())
		{
			ch = Uart_Read();
			if (ch == '4'){ control_flag = 1;}
			else if(ch == 68){ control_flag = 0;}
				
			if(control_flag == 0)
			{	
				if(ch == '1'){ LED_ON;}
				else if(ch == 65){ LED_OFF;}
			 
				if(ch == '2')
				{
					Fan_ON;
					lcd_write_cmd(st_line + 6);
					lcd_write_txt(" the fan"); 
					lcd_write_cmd(st_line); 
					lcd_write_txt(" open ");
				}
				else if(ch == 66)
				{
					Fan_OFF;
					lcd_write_cmd(st_line + 6);
					lcd_write_txt(" the fan"); 
					lcd_write_cmd(st_line); 
					lcd_write_txt(" close ");
				}
					
				if(ch == '3'){Servo_ON;}
			    else if(ch == 68){Servo_OFF;}
				
			}			 
		}
		
		if(control_flag == 1){
			
			uint16_t LightValue = ADC_read(5); 

			if(LightValue > LightSensivity){ LED_ON;}
			else if(LightValue < LightSensivity){ LED_OFF;}
		
			uint16_t TempValue = ADC_read(1);
		
			if(TempValue > TempThreshold){
				Fan_ON;
				lcd_write_cmd(st_line + 6);
				lcd_write_txt(" the fan");
				lcd_write_cmd(st_line);
				lcd_write_txt(" open ");
			}
			else if(TempValue < TempThreshold){
				Fan_OFF;
				lcd_write_cmd(st_line + 6);
				lcd_write_txt(" the fan");
				lcd_write_cmd(st_line);
				lcd_write_txt(" close ");
			}
					
			if(distance < 20){Servo_ON;}
			else{ Servo_OFF;}							 	
		}
	}
}

