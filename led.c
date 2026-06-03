#include <LPC21xx.H>
#include "led.h"

#define LED0_bm (1 << 16)
#define LED1_bm (1 << 17)
#define LED2_bm (1 << 18)
#define LED3_bm (1 << 19)

enum eStepDirection{LEFT, RIGHT};

void LedOn (unsigned char ucLedIndeks) {

    IOCLR1 = LED0_bm|LED1_bm|LED2_bm|LED3_bm; 

    switch (ucLedIndeks) {
        case 0: {
            IOSET1 = LED0_bm; 
            break;
        }
        case 1: {
            IOSET1 = LED1_bm; 
            break;
        }
        case 2: {
            IOSET1 = LED2_bm; 
            break;
        }
        case 3: {
            IOSET1 = LED3_bm; 
            break;
        }
        default: 
            break;
        
    }
}

void LedInit () {

    IO1DIR = IO1DIR|(LED0_bm|LED1_bm|LED2_bm|LED3_bm);  
    IO1CLR = LED0_bm|LED1_bm|LED2_bm|LED3_bm;  

}

void LedStep (enum eStepDirection eDirection) {

    static unsigned int sucLedPosition = 0;

    if (LEFT == eDirection) {
        sucLedPosition = (sucLedPosition + 1) % 4;
    }
    else {
        sucLedPosition = (sucLedPosition + 3) % 4;
    }

    LedOn(sucLedPosition);
}

void LedStepLeft () {

    LedStep(LEFT);
}

void LedStepRight () {

    LedStep(RIGHT);
}
