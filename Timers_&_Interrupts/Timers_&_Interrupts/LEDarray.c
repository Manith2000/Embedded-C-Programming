#include <xc.h> 
#include "LEDarray.h"

/************************************
/ LEDarray_init
/ Function used to initialise pins to drive the LEDarray
************************************/
void LEDarray_init(void)
{
    //set up TRIS registers for pins connected to LED array
    //Following pins set to output
	TRISGbits.TRISG0=0; //Pin RG0 
    TRISGbits.TRISG1=0; //Pin RG1
    TRISAbits.TRISA2=0; //Pin RA2
    TRISAbits.TRISA4=0; //Pin RA4 
    TRISAbits.TRISA5=0; //Pin RA5
    TRISFbits.TRISF6=0; //Pin RF6  
    TRISFbits.TRISF0=0; //Pin RF0 
    TRISBbits.TRISB0=0; //Pin RB0 
    TRISBbits.TRISB1=0; //Pin RB1
    
    //set initial output LAT values (they may have random values when powered on)
    //Following pins are initialised to random output LAT values
    LATGbits.LATG0=0; //Pin RG0 
    LATGbits.LATG1=0; //Pin RG1
    LATAbits.LATA2=0; //Pin RA2
    LATAbits.LATA4=0; //Pin RA4 
    LATAbits.LATA5=0; //Pin RA5
    LATFbits.LATF6=0; //Pin RF6  
    LATFbits.LATF0=0; //Pin RF0 
    LATBbits.LATB0=0; //Pin RB0 
    LATBbits.LATB1=0; //Pin RB1
    
    

}   


/************************************
/ LEDarray_disp_bin
/ Function used to display a number on the LED array in binary
************************************/
void LEDarray_disp_bin(unsigned int number)
{
    //some code to turn on/off the pins connected to the LED array
    //if statements and bit masks can be used to determine if a particular pin should be on/off
	//see Readme.md for examples
    
    /* Note the bits from least significant to most significant are as follows: 
    Pins RG0,RG1,RA2,RF6,RA4,RA5,RF0,RB0,RB1*/
    
    
    LEDarray_init(); //reinitialise LED latches to 0 if any iterations of this function has been run
    
    //Note that for Ex 2.2 the 8 most significants bits are displayed, so the last (9th) LED is not used
    if (number & 0b1000000000000000) { //Find out if 7th bit is set (1) or clear(0)
        LATBbits.LATB0=1;   //Pin RB0 is 7th Bit
    }    
    
    if (number & 0b0100000000000000) {  //Find out if 6th bit is set (1) or clear(0)
        LATFbits.LATF0=1;   //Pin RF0 is 6th Bit
    }
    
    if (number & 0b0010000000000000) {  //Find out if 5th bit is set (1) or clear(0)
        LATAbits.LATA5=1;   //Pin RA5 is 5th Bit
    }
    
    if (number & 0b0001000000000000) {  //Find out if 4th bit is set (1) or clear(0)
        LATAbits.LATA4=1;   //Pin RA4 is 4th Bit
    }
    
    if (number & 0b0000100000000000) {   //Find out if 3rd bit is set (1) or clear(0)
        LATFbits.LATF6=1;   //Pin RF6 is 3rd Bit
    }
    
    if (number & 0b0000010000000000) {   //Find out if 2nd bit is set (1) or clear(0)
        LATAbits.LATA2=1;   //Pin RA2 is 2nd Bit
    }   
    
    if (number & 0b0000001000000000) {   //Find out if 1st bit is set (1) or clear(0)
        LATGbits.LATG1=1;   //Pin RG1 is 1st Bit
    }
    
    if (number & 0b0000000100000000) {   //Find out if 0th bit is set (1) or clear(0)
        LATGbits.LATG0=1;   //Pin RG0 is 0th Bit
    }    
       
}