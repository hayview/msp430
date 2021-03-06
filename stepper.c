#include <msp430.h> 

/*
 * main.c
 */

#define DIR_PIN 		 0x01
#define STEP_PIN 		 0x02

#define FORWARD			 0x01
#define BACKWARD		 0x00

#define DELAY_CYCLES	 	16000

void initPin(void){
	P2DIR |= (DIR_PIN | STEP_PIN);
	P2OUT &=~(DIR_PIN | STEP_PIN);
	}

void rotateMotor(int steps, char direction){
	char pin2_out;
	int i;
	pin2_out = (DIR_PIN & direction);

	for (i = 0; i < steps; i++){
		P2OUT = (pin2_out | STEP_PIN);
		_delay_cycles(DELAY_CYCLES);

		P2OUT =  pin2_out;
		_delay_cycles(DELAY_CYCLES);
	}

}

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
    BCSCTL2 = SELM_0 | DIVM_0 | DIVS_0;

    if (CALBC1_16MHZ != 0xFF) {
        /* Adjust this accordingly to your VCC rise time */
        __delay_cycles(100000);

        /* Follow recommended flow. First, clear all DCOx and MODx bits. Then
         * apply new RSELx values. Finally, apply new DCOx and MODx bit values.
         */
        DCOCTL = 0x00;
        BCSCTL1 = CALBC1_16MHZ;     /* Set DCO to 16MHz */
        DCOCTL = CALDCO_16MHZ;
    }

    	initPin();

   	rotateMotor(800, FORWARD);
   	__delay_cycles(100000);
   	__delay_cycles(100000);
   	__delay_cycles(100000);
   	__delay_cycles(100000);
   	__delay_cycles(100000);
   	__delay_cycles(100000);

   	rotateMotor(800, BACKWARD);
   	__delay_cycles(100000);
   	__delay_cycles(100000);
   	__delay_cycles(100000);
   	__delay_cycles(100000);
   	__delay_cycles(100000);
   	__delay_cycles(100000);

   	rotateMotor(1600, FORWARD);
   	__delay_cycles(100000);
   	__delay_cycles(100000);
   	__delay_cycles(100000);
   	__delay_cycles(100000);
   	__delay_cycles(100000);
   	__delay_cycles(100000);

   	rotateMotor(1600, BACKWARD);
   	__delay_cycles(100000);
   	__delay_cycles(100000);
   	__delay_cycles(100000);
   	__delay_cycles(100000);
   	__delay_cycles(100000);
   	__delay_cycles(100000);

}
