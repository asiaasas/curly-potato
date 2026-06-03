#include "led.h"
#include "keyboard.h"  
#include "timer_interrupts.h"
//git test
void Automat(void) {
enum LedMoveState {STOP, LEFT, RIGHT};
static enum LedMoveState eLedState = STOP;
enum eKeyboardState eCurrentKey;
eCurrentKey = eKeyboardRead();

switch (eLedState) {
   	 
        	case STOP: {
            	if (BUTTON_0 == eCurrentKey) {
                	eLedState = LEFT;
            	}
            	else if (BUTTON_2 == eCurrentKey) {
                	eLedState = RIGHT;
            	}
            	else {
    	 
                	eLedState = STOP;
            	}
            	break;
        	}
       	 
        	case LEFT: {
            	if (BUTTON_1 == eCurrentKey) {

                	eLedState = STOP;
            	}
            	else {
 
                	LedStepLeft();
                	eLedState = LEFT;
            	}
            	break;
        	}
       	 
        	case RIGHT: {
            	if (BUTTON_1 == eCurrentKey) {

                	eLedState = STOP;
            	}
            	else {

                	LedStepRight();
                	eLedState = RIGHT;
            	}
            	break;
        	}
       	 
        	default: {
            	break;
        	}
    	}
		}

int main () {
	unsigned int iMainLoopCtr;
	
	LedInit(); 
	KeyboardInit(); 

	Timer0Interrupts_Init(20000, &Automat);

	while(1) {
	 	iMainLoopCtr++;
	}
}
//test zmiany
