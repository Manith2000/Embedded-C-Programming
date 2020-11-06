// CONFIG1L
#pragma config FEXTOSC = HS     // External Oscillator mode Selection bits (HS (crystal oscillator) above 8 MHz; PFM set to high power)
#pragma config RSTOSC = EXTOSC_4PLL// Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)

// CONFIG3L
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)

#include <xc.h>
#include "LEDarray.h"
#include "interrupts.h"
#include "comparator.h"
#include "timers.h"

#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  


void main(void) {
	//call your initialisation functions to set up the hardware modules
    Interrupts_init();
    LEDarray_init(); //initialise LED RH3 (initially 0 output)
    Timer0_init(); //initialise timer in 16-bit mode
    
    //Initialise LED RH3
    TRISHbits.TRISH3=0; //Pin RH3 LED
    LATHbits.LATH3=0; //Pin RH3 LED
    
    while (1) {
        //TMR0 initialised with 3035 (see timers.c for more detail)
        //Approx. annual error calculated using stopwatch is approx. 29615 seconds 
        LEDarray_disp_bin(get16bitTMR0val()); //display the 8 most sig. bits of 16bitval in binary on LED array
     }
    }
