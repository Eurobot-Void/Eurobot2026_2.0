#include <math.h>
#include "void_moduli/util.h"

float normalize_rad_angle(float angle) //ovo je samo ogranicenje da se ugao nalzi izmedju minu pi i pi
{
	if (angle > M_PI) {
		return angle - 2 * M_PI;
	}
	if (angle < -M_PI) {
		return angle + 2 * M_PI;
	}

	return angle;
}
