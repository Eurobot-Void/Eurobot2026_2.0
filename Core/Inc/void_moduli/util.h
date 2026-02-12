#ifndef INC_VOID_MODULI_UTIL_H_
#define INC_VOID_MODULI_UTIL_H_

#include <math.h>

//ovo je samo ogranicenje da se ugao nalzi izmedju minu pi i pi
static inline float normalize_rad_angle(float angle) {
	if (angle > M_PI) {
		return angle - 2 * M_PI;
	}
	if (angle < -M_PI) {
		return angle + 2 * M_PI;
	}
	return angle;
}

//Funkcija koju pravim za ogranicenje napona, smanjen kod
static inline float clamp(float x, float min, float max) {
	if (x > max)
		return max;
	if (x < min)
		return min;
	return x;
}

#endif /* INC_VOID_MODULI_UTIL_H_ */
