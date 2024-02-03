#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_


/***************************************************************
*************************** Includes ***************************
****************************************************************/

#include "STD_TYPES.h"


/***************************************************************
********************** Type Definitions ************************
****************************************************************/

typedef struct{
	volatile u32 EXTI_IMR;
	volatile u32 EXTI_EMR;
	volatile u32 EXTI_RTSR;
	volatile u32 EXTI_FTSR;
	volatile u32 EXTI_SWIER;
	volatile u32 EXTI_PR;
}EXTI_t;

typedef struct{
	volatile u32 SYSCFG_MEMRMP;
	volatile u32 SYSCFG_PMC;
	volatile u32 SYSCFG_EXTICR[4];
	volatile u32 SYSCFG_CMPCR;
}SYSCFG_t;


/***************************************************************
*************************** Defines ****************************
****************************************************************/

/*Base adreess of EXTI 0x40013c00*/
#define EXIT_BASE_ADDRESS 0x40013C00

/*Base adreess of SYSCFG 0x40013800*/
#define SYSCFG_BASE_ADDRESS 0x40013800

#define  EXTI  		((volatile EXTI_t*)EXIT_BASE_ADDRESS)
#define	 SYSCFG		((volatile SYSCFG_t*)SYSCFG_BASE_ADDRESS)


#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
