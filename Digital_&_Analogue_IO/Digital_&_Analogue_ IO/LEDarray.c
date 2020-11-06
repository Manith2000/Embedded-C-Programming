#include <xc.h>
#include "LEDarray.h"
#include "ADC.h"

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
    
    if (number & 256) { //Find out if 8th bit is set (1) or clear(0)
        LATBbits.LATB1=1;   //Pin RB1 is 8th Bit
    }
    
    if (number & 128) { //Find out if 7th bit is set (1) or clear(0)
        LATBbits.LATB0=1;   //Pin RB0 is 7th Bit
    }    
    
    if (number & 64) {  //Find out if 6th bit is set (1) or clear(0)
        LATFbits.LATF0=1;   //Pin RF0 is 6th Bit
    }
    
    if (number & 32) {  //Find out if 5th bit is set (1) or clear(0)
        LATAbits.LATA5=1;   //Pin RA5 is 5th Bit
    }
    
    if (number & 16) {  //Find out if 4th bit is set (1) or clear(0)
        LATAbits.LATA4=1;   //Pin RA4 is 4th Bit
    }
    
    if (number & 8) {   //Find out if 3rd bit is set (1) or clear(0)
        LATFbits.LATF6=1;   //Pin RF6 is 3rd Bit
    }
    
    if (number & 4) {   //Find out if 2nd bit is set (1) or clear(0)
        LATAbits.LATA2=1;   //Pin RA2 is 2nd Bit
    }   
    
    if (number & 2) {   //Find out if 1st bit is set (1) or clear(0)
        LATGbits.LATG1=1;   //Pin RG1 is 1st Bit
    }
    
    if (number & 1) {   //Find out if 0th bit is set (1) or clear(0)
        LATGbits.LATG0=1;   //Pin RG0 is 0th Bit
    }    
       
}

void RF2button_init(void) {
    // setup pin RF2 for input (connected to button)
    TRISFbits.TRISF2=1; //set TRIS value for pin (input)
    ANSELFbits.ANSELF2=0; //turn off analogue input on pin  
}
/************************************
/ Function LEDarray_disp_dec
/ Used to display a number on the LEDs
/ where each LED is a value of 10
************************************/
void LEDarray_disp_dec(unsigned int number)
{
	
	//some code to manipulate the variable number into the correct
	//format and store in disp_val for display on the LED array

	LEDarray_init();//reinitialise LED latches to 0 if any iterations of this function has been run
    
    if (number >= 90) { //Find out if 8th bit is set (1) or clear(0)
        LATBbits.LATB1=1;   //Pin RB1 is 8th Bit
    }
    
    if (number >= 80) { //Find out if 7th bit is set (1) or clear(0)
        LATBbits.LATB0=1;   //Pin RB0 is 7th Bit
    }    
    
    if (number >= 70) {  //Find out if 6th bit is set (1) or clear(0)
        LATFbits.LATF0=1;   //Pin RF0 is 6th Bit
    }
    
    if (number >= 60) {  //Find out if 5th bit is set (1) or clear(0)
        LATAbits.LATA5=1;   //Pin RA5 is 5th Bit
    }
    
    if (number >= 50) {  //Find out if 4th bit is set (1) or clear(0)
        LATAbits.LATA4=1;   //Pin RA4 is 4th Bit
    }
    
    if (number >= 40) {   //Find out if 3rd bit is set (1) or clear(0)
        LATFbits.LATF6=1;   //Pin RF6 is 3rd Bit
    }
    
    if (number >= 30) {   //Find out if 2nd bit is set (1) or clear(0)
        LATAbits.LATA2=1;   //Pin RA2 is 2nd Bit
    }   
    
    if (number >= 20) {   //Find out if 1st bit is set (1) or clear(0)
        LATGbits.LATG1=1;   //Pin RG1 is 1st Bit
    }
    
    if (number >= 10) {   //Find out if 0th bit is set (1) or clear(0)
        LATGbits.LATG0=1;   //Pin RG0 is 0th Bit
    }
}



/************************************
/ LEDarray_disp_PPM
/ Function used to display a level on the LED array with peak hold
/ cur_val is the current level from the most recent sample, and max is the peak value for the last second
/ these input values need to calculated else where in your code
************************************/
  
void LEDarray_disp_PPM(unsigned int cur_val , unsigned int max_val){
        
    ADC_intensity(cur_val); /*Reuse ADC_intensity func in ADC.c file to display
    current value on intensity meter*/
    
    //The following if statements are used to display maximum value on LED
    
    // Note: ambient light = 125 units & dark = 50 units.
    // Similar to ADC_intensity func, linear interpolation was used to seperate to equal intervals
    
    if (max_val >= 125 ) { //Find out if 8th bit is set (1) or clear(0)
        LATBbits.LATB1=1;   //Pin RB1 is 8th Bit
    }

    if (max_val >= 115 & max_val < 125) { //Find out if 7th bit is set (1) or clear(0)
        LATBbits.LATB0=1;   //Pin RB0 is 7th Bit
    }    

    if (max_val >= 110 & max_val < 115) {  //Find out if 6th bit is set (1) or clear(0)
        LATFbits.LATF0=1;   //Pin RF0 is 6th Bit
    }

    if (max_val >= 100 & max_val < 110) {  //Find out if 5th bit is set (1) or clear(0)
        LATAbits.LATA5=1;   //Pin RA5 is 5th Bit
    }

    if (max_val >= 90 & max_val < 100) {  //Find out if 4th bit is set (1) or clear(0)
        LATAbits.LATA4=1;   //Pin RA4 is 4th Bit
    }

    if (max_val >= 80 & max_val < 90) {   //Find out if 3rd bit is set (1) or clear(0)
        LATFbits.LATF6=1;   //Pin RF6 is 3rd Bit
    }

    if (max_val>= 70 & max_val < 80) {   //Find out if 2nd bit is set (1) or clear(0)
        LATAbits.LATA2=1;   //Pin RA2 is 2nd Bit
    }   

    if (max_val >= 60 & max_val< 70) {   //Find out if 1st bit is set (1) or clear(0)
        LATGbits.LATG1=1;   //Pin RG1 is 1st Bit
    }

    if (max_val >= 50 & max_val < 60) {   //Find out if 0th bit is set (1) or clear(0)
        LATGbits.LATG0=1;   //Pin RG0 is 0th Bit
    }
    
}
