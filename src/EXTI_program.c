
/***************************************************************
*************************** Includes ***************************
****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


/***************************************************************
**************************** Globals ***************************
****************************************************************/

static void (*EXTI0_callBack)(void) = 0;
static void (*EXTI1_callBack)(void) = 0;


/***************************************************************
****************************** APIs ****************************
****************************************************************/

/*
Return: void
Input: EXTI_LINE_t copy_tLineNumber
func: Enable interrupt for specific Line
*/
void EXTI_VEnableEXTI(EXTI_LINE_t copy_tLineNumber){
	SET_BIT(EXTI->EXTI_IMR, copy_tLineNumber);
}


/*
Return: void
Input: EXTI_LINE_t copy_tLineNumber
func: Disable interrupt for specific Line
*/
void EXTI_VDisableEXIT(EXTI_LINE_t copy_tLineNumber){
	CLR_BIT(EXTI->EXTI_IMR, copy_tLineNumber);
}


/*
Return: void
Input: EXTI_LINE_t copy_tLineNumber
func: Function used to simulate the occurence of EXTI for specific line
*/
void EXTI_VSoftwareInterrupt(EXTI_LINE_t copy_tLineNumber){
	SET_BIT(EXTI->EXTI_SWIER,copy_tLineNumber);
}


/*
Return: void
Input: EXTI_LINE_t copy_LineNumber, EXTI_TriggerMode_t copy_tTriggerMode
func: Set the trigger source that will fire the interupt (ON_RISING,ON_FALLING,ON_CHANGE)
*/
void EXTI_VSetTriggerSource(EXTI_LINE_t copy_LineNumber, EXTI_TriggerMode_t copy_tTriggerMode){
	switch(copy_tTriggerMode){
		case ON_FALLING:
			SET_BIT(EXTI->EXTI_FTSR,copy_LineNumber);
			break;
		case ON_RISING:
			SET_BIT(EXTI->EXTI_RTSR,copy_LineNumber);
			break;
		case ON_CHANGE:
			SET_BIT(EXTI->EXTI_FTSR,copy_LineNumber);
			SET_BIT(EXTI->EXTI_RTSR,copy_LineNumber);
			break;
	}
}


/*
Return: void
Input: EXTI_LINE_t copy_tLineNumber, u8 copy_u8GpioPortNum
func: Config the external interrupt pin will be from which port
*/
void EXTI_VSetExtiConfig(EXTI_LINE_t copy_tLineNumber, u8 copy_u8GpioPortNum){
	if(copy_tLineNumber == 0){
		SYSCFG->SYSCFG_EXTICR[0] |= (u32)(copy_u8GpioPortNum);
	}else{
		u8 reg = copy_tLineNumber /	4;
		SYSCFG->SYSCFG_EXTICR[reg] |= ((u32)copy_u8GpioPortNum << (copy_tLineNumber % 4));
	}
}


/*
Return: void
Input: void(*ptr)(void)
func: Set the callback function for EXTI0
*/
void EXTI0_VCallBack(void(*ptr)(void)){
	EXTI0_callBack = ptr;
}


/*
Return: void
Input: void(*ptr)(void)
func: Set the callback function for EXTI1
*/
void EXTI1_VCallBack(void(*ptr)(void)){
	EXTI1_callBack = ptr;
}

void EXTI0_IRQHandler(void){
	(*EXTI0_callBack)();
	SET_BIT(EXTI->EXTI_PR,0);
}

void EXTI1_IRQHandler(void){
	(*EXTI1_callBack)();
	SET_BIT(EXTI->EXTI_PR,1);
}
