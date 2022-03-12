
#include <avr/io.h>
#define F_CPU 8000000UL
#include "AVR_Counter_Timer.h"

void PWM_T1_initialize()
{
	//Using Fast PWM in T1 [16 bit]
	//motor needs 50Hz of PWM to work
	//to get 50Hz of PWM, we change TOP of timer1
	ICR1 = 2499; //TOP, as PWM_freq = (CPU_freq / N) / (1+TOP), N is the pre-scaler
	
	//Set Fast PWM in T1, Clear OC1A on compare match, pre-scaler of 64
	TCCR1A = (1<<WGM11) | (1<<COM1A1);
	TCCR1B = (1<<WGM12) | (1<<CS10) | (1<<CS11);
}
