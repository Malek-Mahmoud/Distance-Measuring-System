/*
 * main.c
 *
 *  Created on: ١٩‏/١٠‏/٢٠٢١
 *      Author: ASiel
 */
#include "std_types.h"
#include "ultrasonic.h"
#include "lcd.h"
#include "avr/io.h"

int main(void)
{
	uint16 l_measuredDistance;
	LCD_init();
	ultrasonic_init();
	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);

	LCD_displayString("Distance =   cm");
	while(1)
	{
		l_measuredDistance = ultrasonic_readDistance();
		LCD_moveCursor(0,10);
		if(l_measuredDistance >= 100)
		{
			LCD_intgerToString(l_measuredDistance);
		}
		else
		{
			LCD_intgerToString(l_measuredDistance);
			LCD_displayCharacter(' ');
		}
	}
	return 0;
}

