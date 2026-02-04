/*
 * servo.h
 *
 *  Created on: Feb 3, 2026
 *      Author: Win11
 */

#ifndef INC_VOID_MODULI_SERVO_H_
#define INC_VOID_MODULI_SERVO_H_

#include "stm32f4xx_hal.h"

#define PCA9685_ADDR  (0x40 << 1)
#define SERVO_COUNT   8
#define SERVO_MIN_IMP 1000.0f  // 1ms, tipicna za 0 stepeni, treba testirati
#define SERVO_MAX_IMP 2000.0f  // max vrednost 180 stepeni
#define SERVO_HZ      50.0f    // servo radi na 50Hz

void servo_init(I2C_HandleTypeDef *hi2c);
void servo_set_angle(uint8_t channel, float angle);

#endif /* INC_VOID_MODULI_SERVO_H_ */
