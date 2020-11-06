#include <xc.h>
#include "timers.h"

/************************************
 * Function to set up timer 0
************************************/
void Timer0_init(void)
{
    T0CON1bits.T0CS=0b010; // Fosc/4
    T0CON1bits.T0ASYNC=1; // see datasheet errata - needed to ensure correct operation when Fosc/4 used as clock source
    T0CON1bits.T0CKPS=0b1000; // 1:256 (approx. overflow/1 second)
    T0CON0bits.T016BIT=1;	//16bit mode	
	
    // it's a good idea to initialise the timer registers so we know we are at 0
    
    //Improve accuracy by the following method:
    //for 1:256PS the time interval will be 0.000016s which means 62500 increments
    //the maximum increments is 65535. Therefore initialise with 65535-62500 = 3035 increments
    TMR0H=0b00001011; //3035 is written in 16-bit 
    TMR0L=0b11011011;
    T0CON0bits.T0EN=1;	//start the timer
}

/************************************
 * Function to return the full 16bit timer value
 * Note TMR0L and TMR0H must be read in the correct order, or TMR0H will not contain the correct value
************************************/
unsigned int get16bitTMR0val(void)
{
	unsigned int curr_count; 
    
    curr_count = TMR0L + (TMR0H << 8 );  //Add the lowest & highest 8 bits. 
    //note that highest 8 bits are shifted to left to add as a 16-bit value
    
    return curr_count;
    //add your code to get the full 16 bit timer value here
}
