
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "AVR_Ports.h"
#include "AVR_GPIO_Declarations.h"
#include "AVR_Counter_Timer.h"

int main(void)
{	
	DDRD |= (1<<5); //make PD5 as output [OC1A] (PWM output)
	TCNT1 = 0;		//Set timer1 count to zero
	PWM_T1_initialize();
	
    while (1) 
    {	
		//set servo shaft at +90 position
		OCR1A = 300; //for ~2.4ms [low] in duty cycle of PWM
		_delay_ms(2000);

		//set servo shaft at 0 position
		//OCR1A = 175; //for ~1.4ms [low] in duty cycle of PWM
		//_delay_ms(2000);

		//set servo shaft at -90 position
		OCR1A = 65; //for ~0.52ms [low] in duty cycle of PWM
		_delay_ms(2000);
	}
}

