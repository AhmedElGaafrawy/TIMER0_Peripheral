/*
 * TIMER0_int.h
 *
 *  Created on : Apr 17, 2020
 *  Version	   : 1.0.0
 *  Author     : Ahmed El-Gaafarwy
 */

#ifndef MCAL_TIMER0_INT_H_
#define MCAL_TIMER0_INT_H_


/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : TIMER0_enuCallBackOVF.                                **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : Ptr to fun,Generic Ptr.                               **/
/**	Functionality   : Calling back the function to run at ISR Handler.      **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES TIMER0_enuInit								(void);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : TIMER0_enuDelayMilliSecond.                           **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : Ptr to fun,Generic Ptr,Delay Time and Stop Time.      **/
/**	Functionality   : Working at OVF mode at one and eight prescaler.       **/
/**	                : and any prescaler at CTC mode.                        **/
/**	                : Highest accuracy at CTC mode and 64_Prescaler.        **/
/**                 : Be ensure that OCR0_REG is assigned before Calling.   **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES TIMER0_enuDelayMilliSecond 				(void (*Copy_PfunCallBack)(void*) , void * Copy_PvidParameter , u32 Copy_u32StartDelay , u32 Copy_u32StopTime);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : TIMER0_enuGeneratePWM.                                **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : Duty cycle of PWM.                                    **/
/**	Functionality   : At Fast PWM, the frequency equals :                   **/
/**	                : PRE_1= 31250 Hz, PRE_8= 39026.25 Hz, PRE_64= 488.3 Hz.**/
/**	                : PRE_256= 122 Hz, PRE_1024= 30.5 Hz.                   **/
/**	                                                                        **/
/**	                : At Phase Correct PWM, the frequency equals :          **/
/**	                : PRE_1= 15686.3 Hz, PRE_8= 1960.8 Hz, PRE_64= 245.1 Hz.**/
/**	                : PRE_256= 61.3 Hz, PRE_1024= 15.3 Hz.                  **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES TIMER0_enuGeneratePWM						(u8 Copy_u8DutyCycle);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/




/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : TIMER0_enuCallBackOVF.                                **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : Ptr to fun,Generic Ptr.                               **/
/**	Functionality   : Calling back the function to run at ISR Handler.      **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES TIMER0_enuCallBackOVF						(void (*Copy_PfunCallBack)(void*) , void * Copy_PvidParameter);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/




/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : TIMER0_enuCallBackCTC.                                **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : Ptr to fun,Generic Ptr.                               **/
/**	Functionality   : Calling back the function to run at ISR Handler.      **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES TIMER0_enuCallBackCTC						(void (*Copy_PfunCallBack)(void*) , void * Copy_PvidParameter);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/




#define TIMER0_VIOD_SET_PRELOAD(COPY_U8PRELOAD)			TCNT0_REG=COPY_U8PRELOAD

#define TIMER0_VIOD_SET_CTC_VALUE(COPY_U8CTC_VALUE)		OCR0_REG=COPY_U8CTC_VALUE

#define TIMER0_VOID_ENABLE_OVF_INTERRUPT()				TIMSK_REG|=(1<<0);\
														TIMSK_REG&=~(1<<1)

#define TIMER0_VOID_ENABLE_CTC_INTERRUPT()				TIMSK_REG|=(1<<1);\
														TIMSK_REG&=~(1<<0)

#endif /* MCAL_TIMER0_INT_H_ */
