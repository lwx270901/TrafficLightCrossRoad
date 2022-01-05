/*
 * input_reading.c
 *
 *  Created on: Sep 30, 2021
 *      Author: ADMIN
 */


# include "main.h"
// we aim to work with more than one buttons
# define N0_OF_BUTTONS 3
int current_button_state[3];
void button_reading ( void )
{
	for(int i = 0; i < N0_OF_BUTTONS;i++)
	{
		static unsigned char last_button[N0_OF_BUTTONS];
		unsigned char raw_button[N0_OF_BUTTONS] ;
		unsigned char filtered_button[N0_OF_BUTTONS] ;
		last_button[i] = raw_button[i] ;
		raw_button[i] = HAL_GPIO_ReadPin ( GPIOB ,(GPIO_PIN_13 << i) );
		if( last_button[i] == raw_button[i] )
		{
			filtered_button[i] = raw_button[i] ;
		}
		current_button_state[i] = filtered_button[i];
	}
}

int get(int index)
{
	return current_button_state[index];
}











