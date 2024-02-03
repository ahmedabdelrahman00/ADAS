#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_


/***************************************************************
*************************** Includes ***************************
****************************************************************/

#include "STD_TYPES.h"


/***************************************************************
********************** Type Definitions ************************
****************************************************************/

typedef enum {
	EXTI_LINE_0 = 0,
	EXTI_LINE_1,
	EXTI_LINE_2,
	EXTI_LINE_3,
	EXTI_LINE_4,
	EXTI_LINE_5,
	EXTI_LINE_6,
	EXTI_LINE_7,
	EXTI_LINE_8,
	EXTI_LINE_9,
	EXTI_LINE_10,
	EXTI_LINE_11,
	EXTI_LINE_12,
	EXTI_LINE_13,
	EXTI_LINE_14,
	EXTI_LINE_15
}EXTI_LINE_t;


typedef enum{
	EXIT_PORTA=0,
	EXIT_PORTB,
	EXIT_PORTC
}EXTI_PORT_t;

typedef enum{
	ON_FALLING,
	ON_RISING,
	ON_CHANGE
}EXTI_TriggerMode_t;


/***************************************************************
****************************** APIs ****************************
****************************************************************/

/*Func: EXTI_VEnableEXTI
  Return: void
  Parameters: EXTI_LINE_t copy_tLineNumber
  		copy_tLineNumber options:
					EXTI_LINE_0
					EXTI_LINE_1
					EXTI_LINE_2
					EXTI_LINE_3
					EXTI_LINE_4
					EXTI_LINE_5
					EXTI_LINE_6
					EXTI_LINE_7
					EXTI_LINE_8
					EXTI_LINE_9
					EXTI_LINE_10
					EXTI_LINE_11
					EXTI_LINE_12
					EXTI_LINE_13
					EXTI_LINE_14
					EXTI_LINE_15
  documentation: To enable external interrupt for specific line
 * */
void EXTI_VEnableEXTI(EXTI_LINE_t copy_tLineNumber);


/*Func: EXTI_VDisableEXIT
  Return: void
  Parameters: EXTI_LINE_t copy_tLineNumber
  		copy_tLineNumber options:
					EXTI_LINE_0
					EXTI_LINE_1
					EXTI_LINE_2
					EXTI_LINE_3
					EXTI_LINE_4
					EXTI_LINE_5
					EXTI_LINE_6
					EXTI_LINE_7
					EXTI_LINE_8
					EXTI_LINE_9
					EXTI_LINE_10
					EXTI_LINE_11
					EXTI_LINE_12
					EXTI_LINE_13
					EXTI_LINE_14
					EXTI_LINE_15
  documentation: To Disable external interrupt for specific line
 * */
void EXTI_VDisableEXIT(EXTI_LINE_t copy_tLineNumber);


/*Func: EXTI_VSoftwareInterrupt
  Return: void
  Parameters: EXTI_LINE_t copy_tLineNumber
  		copy_tLineNumber options:
					EXTI_LINE_0
					EXTI_LINE_1
					EXTI_LINE_2
					EXTI_LINE_3
					EXTI_LINE_4
					EXTI_LINE_5
					EXTI_LINE_6
					EXTI_LINE_7
					EXTI_LINE_8
					EXTI_LINE_9
					EXTI_LINE_10
					EXTI_LINE_11
					EXTI_LINE_12
					EXTI_LINE_13
					EXTI_LINE_14
					EXTI_LINE_15
  documentation: To simulate there is an interrupt in specific External line
 * */
void EXTI_VSoftwareInterrupt(EXTI_LINE_t copy_tLineNumber);


/*Func: EXTI_VSetTriggerSource
  Return: void
  Parameters: EXTI_LINE_t copy_LineNumber, EXTI_TriggerMode_t copy_tTriggerMode
  		copy_tLineNumber options:
					EXTI_LINE_0
					EXTI_LINE_1
					EXTI_LINE_2
					EXTI_LINE_3
					EXTI_LINE_4
					EXTI_LINE_5
					EXTI_LINE_6
					EXTI_LINE_7
					EXTI_LINE_8
					EXTI_LINE_9
					EXTI_LINE_10
					EXTI_LINE_11
					EXTI_LINE_12
					EXTI_LINE_13
					EXTI_LINE_14
					EXTI_LINE_15
		copy_tTriggerMode
					ON_FALLING
					ON_RISING
					ON_CHANGE
  documentation: To choose when interrupt will occur
		. When pin is high it will happen (ON_RISING)
		. When pin is Low it will happen (ON_FALLING)
		. When pin is change from high to low or from
			low to high will happen (ON_CHANGE)
 * */
void EXTI_VSetTriggerSource(EXTI_LINE_t copy_LineNumber, EXTI_TriggerMode_t copy_tTriggerMode);


/*Func: EXTI_VSetExtiConfig
  Return: void
  Parameters: EXTI_LINE_t copy_tLineNumber, u8 copy_u8GpioPortNum
  		copy_tLineNumber options:
					EXTI_LINE_0
					EXTI_LINE_1
					EXTI_LINE_2
					EXTI_LINE_3
					EXTI_LINE_4
					EXTI_LINE_5
					EXTI_LINE_6
					EXTI_LINE_7
					EXTI_LINE_8
					EXTI_LINE_9
					EXTI_LINE_10
					EXTI_LINE_11
					EXTI_LINE_12
					EXTI_LINE_13
					EXTI_LINE_14
					EXTI_LINE_15
		copy_u8GpioPortNum
					EXIT_PORTA
					EXIT_PORTB
					EXIT_PORTC
  documentation: To choose what pin in the group is activated
		EX:
			if choosed EXTI_LINE_5 and PORTB mean PIN5 in GROUP is
			activated to have an interrupt occure in it but PIN5 in
			GROUPA and GROUPC will not be activated
 * */
void EXTI_VSetExtiConfig(EXTI_LINE_t copy_tLineNumber, u8 copy_u8GpioPortNum);


/*Func: EXTI0_VCallBack
  Return: void
  Parameters: void(*ptr)(void) => (pointer to function)
  documentation: To give the driver the function you want to be executed
				 when interrupt is fired for Line EXTI_LINE_0
 * */
void EXTI0_VCallBack(void(*ptr)(void));


/*Func: EXTI1_VCallBack
  Return: void
  Parameters: void(*ptr)(void) => (pointer to function)
  documentation: To give the driver the function you want to be executed
				 when interrupt is fired for Line EXTI_LINE_0
 * */
void EXTI1_VCallBack(void(*ptr)(void));

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
