/*
 * enc.h
 *
 *  Created on: Feb 3, 2026
 *      Author: Win11
 */

#ifndef INC_VOID_MODULI_ENC_H_
#define INC_VOID_MODULI_ENC_H_

#include "stm32f4xx_hal.h"
#include "tim.h"

#define ENC_START_INC 65535/2

//Prototipovi funkcija

void encoders_init();

int32_t enc1_get_delta_inc();
int32_t enc2_get_delta_inc();



#endif /* INC_VOID_MODULI_ENC_H_ */
