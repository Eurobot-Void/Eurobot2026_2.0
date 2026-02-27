#ifndef INC_VOID_MODULI_UTIL_H_
#define INC_VOID_MODULI_UTIL_H_

#include <math.h>

// opseg [-pi, pi)
static inline float normalize_rad_angle(float angle) {
	return angle - (floorf((angle + M_PI) / M_TWOPI)) * M_TWOPI;
}

static inline float clamp(float x, float min, float max) {
	return fminf(fmaxf(x, min), max);
}

#endif /* INC_VOID_MODULI_UTIL_H_ */
