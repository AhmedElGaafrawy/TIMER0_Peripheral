/*
 * main.c
 *
 *  Created on : Apr 17, 2020
 *  Version	   : 1.0.0
 *  Author     : Ahmed El-Gaafarwy
 */
#include "../LIBRARY/stdTypes.h"
#include "../LIBRARY/BIT_MATH.h"
#include "../LIBRARY/errorStates.h"
#include "../LIBRARY/AVR_REG.h"

#include "../MCAL/GIE/GIE_int.h"

#include "../MCAL/TIMER0_int.h"
#include "../MCAL/TIMER0_priv.h"

void fun (void * ptr);

int main ()
{
	DDRA=0xff;
	PORTA=0;
	DDRB|=(1<<3);
	TIMER0_enuInit();
	TIMER0_VIOD_SET_CTC_VALUE(124);
	TIMER0_enuGeneratePWM(25);
	//TIMER0_enuDelayMilliSecond(fun , NULL , 1000 , 10000);
	//TIMER0_VOID_ENABLE_CTC_INTERRUPT();
	//TIMER0_VIOD_SET_CTC_VALUE(254);
	//GIE_enuEnable();
	while (1);
	return 0;
}

void fun (void * ptr)
{
	PORTA=~PORTA;
}
