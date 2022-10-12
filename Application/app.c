/*
 * app.c
 *
 * Created: 10/12/2022 12:55:44 PM
 *  Author: Marwan Fawzy
 */ 
#include "app.h"

Str_TimerConfiguration_t TIMER_blink = {TIMER2, F_CPU_CLOCK_1024_TIMER_2, NORMAL_MODE};


void app_init()
{
	Enable_INT0(RISING);  //set interrupt high
	Traffic_init();  //start traffic cycle
	init_interrupt_traffic();  //button interrupt
}

void app_start()
{
	normal_cycle();  //blink from green-->yellow-->red and so on... for cars
}

void normal_cycle()
{
	CAR_start();
	delay_5sec();
	for(int i=0;i<5;i++)
	{
		changing_cycle(); //blink for on for half sec and off for half a sec
	}
	PERSON_start(); //pedestrian traffic reverse of normal cycle
	delay_5sec();
	for(int i=0;i<5;i++)
	{
		changing_cycle();
	}
}

void R_To_Y()
{
	delay_5sec();
	for(int i=0;i<5;i++)
	{changing_cycle();}
	PERSON_start();
	delay_5sec();
	for(int i=0;i<5;i++)
	{changing_cycle();}
	normal_cycle();
}

void Y_To_G()
{
	for(int i=0;i<5;i++)
	{changing_cycle();}
	PERSON_start();
	delay_5sec();
	for(int i=0;i<5;i++)
	{changing_cycle();}
	normal_cycle();
}

void G_To_Y()
{
	for(int i=0;i<5;i++)
	{changing_cycle();}
	PERSON_start();
	delay_5sec();
	for(int i=0;i<5;i++)
	{changing_cycle();}
	normal_cycle();
}