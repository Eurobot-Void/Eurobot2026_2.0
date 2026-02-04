/*
 * odom.h
 *
 *  Created on: Feb 3, 2026
 *      Author: Win11
 */

#ifndef INC_VOID_MODULI_ODOM_H_
#define INC_VOID_MODULI_ODOM_H_
#include "stm32f4xx_hal.h"

extern volatile float x, y, theta, v_l, v_r, w, v; //da bi bilo vidljivo u ostalim fajlovima

void odom_loop();
float normalize_rad_angle(float angle);


#endif /* INC_VOID_MODULI_ODOM_H_ */
