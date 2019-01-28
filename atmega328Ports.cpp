

#ifndef __AVR_IO__
  #include <avr/io.h>
#endif

#include "atmega328Ports.h"


Atmega328Ports::Atmega328Ports(void)
{
	pinNumber = 15;
	ddr = get_DDR(pinNumber);
	port = get_PORT(pinNumber);
	pin = get_PIN(pinNumber);

}

Atmega328Ports::Atmega328Ports(int number_pin)
{
	pinNumber = number_pin;
	ddr = get_DDR(number_pin);
	port = get_PORT(number_pin);
	pin = get_PIN(number_pin);

}


volatile uint8_t* Atmega328Ports::get_DDR(int number_pin)
{	
	//if (number_pin == (7 || 8 || 20 || 21 || 22)) return 1;
	volatile uint8_t* function_ddr =  0;

	switch (number_pin) 
	{
		
		case (2):
		case (3):
		case (4):
		case (5):
		case (6):
		case (11):
		case (12):
		case (13):
							function_ddr = &DDRD;
							break;
		case (9):
		case (10):
		case (14):
		case (15):
		case (16):
		case (17):
		case (18):
		case (19): 	
							function_ddr = &DDRB;
							break;
		case (1):
		case (23):
		case (24):
		case (25): 	
		case (26):
		case (27):
		case (28):
							function_ddr = &DDRC;
							break;
		case (7):
		case (8):
		case (20):
		case (21):
		case (22):
							return 0;
							break;
		default:
							break;
		}

		return function_ddr;

}



volatile uint8_t* Atmega328Ports::get_PORT(int number_pin)
{
	volatile uint8_t* function_port = 0;

	switch (number_pin) 
	{
		case (2):
		case (3):
		case (4):
		case (5):
		case (6):
		case (11):
		case (12):
		case (13):
							function_port = &PORTD;
							break;
		case (9):
		case (10):
		case (14):
		case (15):
		case (16):
		case (17):
		case (18):
		case (19): 	
							function_port = &PORTB;
							break;
		case (1):
		case (23):
		case (24):
		case (25): 	
		case (26):
		case (27):
		case (28):
							function_port = &PORTC;
							break;
		case (7):
		case (8):
		case (20):
		case (21):
		case (22):
							function_port = 0;
							break;
		default:
							break;


	}
	return function_port;
}

int Atmega328Ports::get_PIN(int number_pin)
{
	int function_pin = 0;

	switch (number_pin) 
	{
		case (1):
							function_pin = PC6;
							break;
		case (2):
							function_pin = PD0;
							break;
		case (3):
							function_pin = PD1;
							break;
		case (4):
							function_pin = PD2;
							break;
		case (5):
							function_pin = PD3;
							break;
		case (6):
							function_pin = PD4;
							break;
		case (9):
							function_pin = PB6;
							break;
		case (10):
							function_pin = PB7;
							break;
		case (11):
							function_pin = PD5;
							break;
		case (12):
							function_pin = PD6;
							break;
		case (13):
							function_pin = PD7;
							break;
		case(14):
							function_pin = PB0;
							break;
		case(15):
							function_pin = PB1;
							break;
		case(16):
							function_pin = PB2;
							break;
		case(17):
							function_pin = PB3;
							break;
		case(18):
							function_pin = PB4;
							break;
		case(19): 	
							function_pin = PB5;
							break;
		case (23):
							function_pin = PC0;
							break;
		case (24):
							function_pin = PC1;
							break;							
		case (25): 	
							function_pin = PC2;
							break;
		case (26):
							function_pin = PC3;
							break;
		case (27):
							function_pin = PC4;
							break;
		case (28):
							function_pin = PC5;
							break;
		case (7):
		case (8):
		case (20):
		case (21):
		case (22):
							return 0;
							break;
	}

	return function_pin;
}


int Atmega328Ports::setPinHigh(void)
{
	//volatile uint8_t* function_ddr =  get_DDR(number_pin);
	//int function_pin =  get_PIN(number_pin);
	//volatile uint8_t* function_port =  get_PORT(number_pin);



	
	//set as output
	//*function_ddr |= (1 << function_pin);
	//*function_port |= (1 << function_pin);


	*ddr |= (1 << pin);
	*port |= (1 << pin);

	return 0;

}



int Atmega328Ports::setPinLow(void)
{
	//volatile uint8_t* function_ddr =  get_DDR(number_pin);
	//int function_pin =  get_PIN(number_pin);
	//volatile uint8_t* function_port =  get_PORT(number_pin);

	//set as output
	*ddr |= (1 << pin);
	*port &= ~(1 << pin);

	return 0;

}