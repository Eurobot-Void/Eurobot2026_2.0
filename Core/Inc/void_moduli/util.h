#ifndef INC_VOID_MODULI_UTIL_H_
#define INC_VOID_MODULI_UTIL_H_

#include <math.h>

static inline float normalize_rad_angle(float angle) //ovo je samo ogranicenje da se ugao nalzi izmedju minu pi i pi
{
	if (angle > M_PI) {
		return angle - 2 * M_PI;
	}
	if (angle < -M_PI) {
		return angle + 2 * M_PI;
	}

	return angle;
}

static inline float clamp(float x, float min, float max) //Funkcija koju pravim za ogranicenje napona, smanjen kod
{
	if (x > max)
		return max;
	if (x < min)
		return min;
	return x;
}

#endif /* INC_VOID_MODULI_UTIL_H_ */
