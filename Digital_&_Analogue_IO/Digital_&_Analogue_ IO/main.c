
#pragma config FEXTOSC = HS     // External Oscillator mode Selection bits (HS (crystal oscillator) above 8 MHz; PFM set to high power)
#pragma config RSTOSC = EXTOSC_4PLL// Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)

#include <xc.h>
#include "LEDarray.h"

#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  

void main(void) 
{
	LEDarray_init(); //initialise LED array to 0 output
    RF2button_init(); //initialise RF2 button for digital input
    unsigned int count=0; //initialise counter at 0 since 0 RF2 button presses
    unsigned int buttoncount=1;
    while (1) {//infinite while loop
       
        if (count>511) {count=0;} //reset count when it gets too big for 8-bit LED array
        
        if (buttoncount == 1){  //execute only for first button press      
		
        if (!PORTFbits.RF2) {//if RF2 button is pressed
        count++; //iterate count by one
        buttoncount++; //iterate button press count by one
        LEDarray_disp_bin(count); //display the count on LED array
        }  
        
        }
        
        while (!PORTFbits.RF2) {} /*this prevents code from executing any further 
        if button is pressed*/
            
        buttoncount = 1; //reinitialise button presses to one after the button is released (not held)
        
    }
}   