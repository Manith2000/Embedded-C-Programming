#include <xc.h>
#include "interrupts.h"

/************************************
 * Function to turn on interrupts and set if priority is used
 * Note you also need to enable peripheral interrupts in the INTCON register to use CM1IE.
************************************/
void Interrupts_init(void)
{
	// turn on global interrupts, peripheral interrupts and the interrupt source 
	PIE0bits.TMR0IE = 1; //enable timer interrupts
    INTCONbits.PEIE = 1; //enable peripheral interrupts
    INTCONbits.GIE=1; 	//turn on interrupts globally 
    // It's a good idea to turn on global interrupts last, once all other interrupt configuration is done.
}

/************************************
 * High priority interrupt service routine
 * Make sure all enabled interrupts are checked and flags cleared
************************************/
void __interrupt(high_priority) HighISR()
{//add your ISR code here i.e. check the flag, do something (i.e. toggle an LED), clear the flag...    
    	    
    if (PIR0bits.TMR0IF) { //check TMR0IF bit (set by overflow)
       LATHbits.LATH3 = !LATHbits.LATH3; //toggle RH3 LED
       PIR0bits.TMR0IF = 0; //clear flag
    }
    
}

