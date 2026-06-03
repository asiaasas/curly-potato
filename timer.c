#include <LPC21xx.H>
#include "timer.h"

#define COUNTER_ENABLE_bm (1 << 0)
#define COUNTER_RESET_bm  (1 << 1)

#define MR0_INTERRUPT_bm  (1 << 0)
#define MR0_RESET_bm  	(1 << 1)
#define MR0_INT_FLAG_bm   (1 << 0)

void InitTimer0(void) {
	T0TCR = COUNTER_ENABLE_bm; //uruchomienie timera
}

void WaitOnTimer0(unsigned int uiTime) {
	T0TCR = T0TCR | COUNTER_RESET_bm; //reset licznika timera
	T0TCR = T0TCR & (~COUNTER_RESET_bm); //zdjecie blokady resetu
    
	while (T0TC < (uiTime * 15)) {

	}
}

void InitTimer0Match0(unsigned int iDelayTime) {
    
	T0TCR = COUNTER_RESET_bm; //reset licznika timera
	T0MR0 = iDelayTime * 15; //ustawienie czasu oczekiwania
	T0MCR = MR0_INTERRUPT_bm | MR0_RESET_bm; // ustawienie flagi przerwania po osiagnieciu odpowiedniej wartosci i reset licznika
  T0IR = MR0_INT_FLAG_bm; //wyzerowanie starej flagi
	T0TCR = COUNTER_ENABLE_bm; //start timera
}


void WaitOnTimer0Match0(void) {
	while ((T0IR & MR0_INT_FLAG_bm) == 0) {

	}
	T0IR = MR0_INT_FLAG_bm; //wyzerowanie flagi
}
