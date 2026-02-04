/*
 * position.h
 *
 *  Created on: Feb 3, 2026
 *      Author: Win11
 */

#ifndef INC_VOID_MODULI_POSITION_H_
#define INC_VOID_MODULI_POSITION_H_
typedef enum
{
	IDLE,
	HEADING_POSE,
	TRANSLATE_TO_GOAL,
	GOAL_POSITION
}Motion_state_t;
extern Motion_state_t current_state;
//Prototipovi funkcija
void set_ref_position(float x_goal, float y_goal, float theta_goal);
void position_loop();


#endif /* INC_VOID_MODULI_POSITION_H_ */
