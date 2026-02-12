#ifndef INC_VOID_MODULI_UTIL_H_
#define INC_VOID_MODULI_UTIL_H_

float normalize_rad_angle(float angle);
static inline float clamp(float x, float max, float min) //Funkcija koju pravim za ogranicenje napona, smanjen kod
{
	if (x > max)
		return max;
	if (x < min)
		return min;
	return x;
}

#endif /* INC_VOID_MODULI_UTIL_H_ */
