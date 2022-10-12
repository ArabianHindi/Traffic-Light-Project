/*
 * button.c
 *
 * Created: 10/12/2022 12:58:22 PM
 *  Author: Marwan Fawzy
 */ 
#include "button.h"

void button_init(u8 pin)
{
	DIO_Pin_Init(pin,INPUT);
}

void button_status(u8 pin,u8 *reading)
{
	DIO_Port_Read(pin,reading);
}

void init_interrupt_traffic()
{
	button_init(button);
}