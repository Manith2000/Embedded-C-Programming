#include <xc.h>
#include "ADC.h"
#include "LEDarray.h"
/************************************
/ ADC_init_init
/ Function used to initialise ADC module and set it up
/ to sample on pin RA3
************************************/
void ADC_init(void)
{
    TRISAbits.TRISA3=1; // Select pin RA3 as input
    ANSELAbits.ANSELA3=1; //Ensure analogue circuitry is active (it is by default - watch out for this later in the course!)

    // Set up the ADC module - check section 32 of the datasheet for more details
    ADREFbits.ADNREF = 0; // Use Vss (0V) as negative reference
    ADREFbits.ADPREF = 0b00; // Use Vdd (3.3V) as positive reference
    ADPCH=0b11; // Select channel RA3/ANA3 for ADC
    ADCON0bits.ADFM = 0; // Left-justified result (i.e. no leading 0s)
    ADCON0bits.ADCS = 1; // Use internal Fast RC (FRC) oscillator as clock source for conversion
    ADCON0bits.ADON = 1; // Enable ADC
}

unsigned int ADC_getval(void)
{
    while (1) {
    unsigned int tmpval;
       
    ADCON0bits.GO = 1; // Start ADC conversion

    while (ADCON0bits.GO); // Wait until conversion done (bit is cleared automatically when done)
        
    tmpval = ADRESH; // Get 8 most significant bits of the ADC result - if we wanted the 
	// full 10bit result we would also need to read the 2 LSBs from ADRESL and combine the result.
	// An 8bit result is sufficient for our needs here

    tmpval = 290 - tmpval; //invert readings for LDR so brighter is a bigger number

    return tmpval; //return this value when the function is called
}
}
void ADC_intensity(unsigned int number) 
{   //Ambient Light = 125 units
    //Dark = 45 units
    //Linear interpolation was used to apply unit intervals to form intensity scale
    LEDarray_init();
    
    if (number >= 125) { //Find out if 8th bit is set (1) or clear(0)
        LATBbits.LATB1=1;   //Pin RB1 is 8th Bit
    }
    
    if (number >= 115) { //Find out if 7th bit is set (1) or clear(0)
        LATBbits.LATB0=1;   //Pin RB0 is 7th Bit
    }    
    
    if (number >= 105) {  //Find out if 6th bit is set (1) or clear(0)
        LATFbits.LATF0=1;   //Pin RF0 is 6th Bit
    }
    
    if (number >= 95) {  //Find out if 5th bit is set (1) or clear(0)
        LATAbits.LATA5=1;   //Pin RA5 is 5th Bit
    }
    
    if (number >= 85) {  //Find out if 4th bit is set (1) or clear(0)
        LATAbits.LATA4=1;   //Pin RA4 is 4th Bit
    }
    
    if (number >= 75) {   //Find out if 3rd bit is set (1) or clear(0)
        LATFbits.LATF6=1;   //Pin RF6 is 3rd Bit
    }
    
    if (number >= 65) {   //Find out if 2nd bit is set (1) or clear(0)
        LATAbits.LATA2=1;   //Pin RA2 is 2nd Bit
    }   
    
    if (number >= 55) {   //Find out if 1st bit is set (1) or clear(0)
        LATGbits.LATG1=1;   //Pin RG1 is 1st Bit
    }
    
    if (number >= 45) {   //Find out if 0th bit is set (1) or clear(0)
        LATGbits.LATG0=1;   //Pin RG0 is 0th Bit
    }
}



