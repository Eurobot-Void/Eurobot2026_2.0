/*
 * user_main.c
 *
 *  Created on: Feb 3, 2026
 *      Author: Win11
 */

#include "void_moduli/enc.h"
#include "stm32f4xx_hal.h"
#include "void_moduli/pwm.h"
#include "void_moduli/position.h"
#include "void_moduli/ax12.h"
#include "void_moduli/servo.h"
#include "tim.h"
static int step=0;
void user_main() {

	HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim5, TIM_CHANNEL_ALL);

	encoders_init();

	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);

	HAL_TIM_Base_Start_IT(&htim1); //Pokreni interrupt tajmer
//	current_state =IDLE;
//	set_ref_position(0.3 ,0, 0);
//	current_state =IDLE;
//	set_ref_position(0.3, 0.3, 0);
	switch(step)
	{
	  case 0:
	    current_state=IDLE;
	    set_ref_position(0.3 ,0, 0);
	    if(current_state==GOAL_POSITION)
	      {
		step=1;
	      }
	    break;

	  case 1:
	    current_state=IDLE;
	    set_ref_position(0.3, 0.3, 0);
	    break;

	}



//	ax12_rack_down();
//	HAL_Delay(1000);
//	ax12_rack_up();
//	HAL_Delay(1000);
}

