// Developed by jmacid


/*
Description:

*/

 

#ifndef atmega328Ports_H
#define atmega328Ports_H

class Atmega328Ports
{
public:
	int pinNumber;
	volatile uint8_t* ddr;
	volatile uint8_t* port;
	int pin;

	Atmega328Ports(void);
	Atmega328Ports(int number_pin);
	int setPinHigh(void);
	int setPinLow(void);


private:
	volatile uint8_t* get_DDR(int number_pin);
	volatile uint8_t* get_PORT(int number_pin);
	int get_PIN(int number_pin);

};

#endif