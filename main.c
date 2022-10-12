/*
 * GccApplication1.c
 *
 * Created: 10/12/2022 12:54:01 PM
 * Author : Marwan Fawzy
 */ 

#include <avr/io.h>


#include "Application/app.h"

//extern u8 flag;
int main(void)
{
	DIO_Port_Direction(2,OUTPUT);
	app_init();
	while(1)
	{
		app_start();
	}
}
ISR(EXT_INT_0) //when button clicked
{

	Disable_INT(); //disable button
	u8 red_reading,yellow_reading,green_reading;
	DIO_Pin_Read(RED_CAR,&red_reading); //call pin function that returns pointer state of traffic
	DIO_Pin_Read(YELLOW_CAR,&yellow_reading);
	DIO_Pin_Read(GREEN_CAR,&green_reading);

	if(red_reading) //for car
	{
		G_To_Y(); //for pedestrian
	}

	else if(yellow_reading)
	{
		Y_To_G();
	}

	else if(green_reading)
	{
		R_To_Y();
	}
	Enable_INT0(RISING); //re-inits interrupt


}