/*
 * input_processing.c
 *
 *  Created on: Sep 30, 2021
 *      Author: ADMIN
 */


# include "main.h"
# include "input_reading.h"
# include "led_display.h"
enum ButtonState { BUTTON_RELEASED , BUTTON_PRESSED ,BUTTON_PRESSED_MORE_THAN_1_SECOND } ;
enum ButtonState buttonState = BUTTON_RELEASED ;
void fsm_for_input_processing(void )
{
	switch ( buttonState )
	{
	case BUTTON_RELEASED :
		if(get(0) == 0)
		{
			buttonState = BUTTON_PRESSED ;
			// INCREASE VALUE OF PORT A BY ONE UNIT
		}
		break;
	case BUTTON_PRESSED:
		if (get(0) == 1)
		{
			buttonState = BUTTON_RELEASED ;
		}
		else
		{
			if( get(0) == 0 )
			{
				buttonState = BUTTON_PRESSED_MORE_THAN_1_SECOND ;
			}
		}
		break;
	case BUTTON_PRESSED_MORE_THAN_1_SECOND :
		if (get(0) == 1)
		{
			buttonState = BUTTON_RELEASED ;
		}
		// todo
		break;
	}
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);
	display7SEG(get(0));
}
