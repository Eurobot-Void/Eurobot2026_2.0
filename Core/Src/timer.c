#include "stm32f4xx_hal.h"
#include "timer.h"
#include "void_moduli/odom.h"
#include "void_moduli/pwm.h"
#include "void_moduli/position.h"

uint32_t sys_ms = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == TIM1) {
		sys_ms++;

		if (sys_ms % ODOM_MS == 0) {
			odom_loop();
			bdc_loop();
		}

		if (sys_ms % 20 == 0) {
			position_loop();
		}
	}
}

