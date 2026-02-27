#include "void_moduli/pid.h"
#include "void_moduli/util.h"

void update_PI(PI_t *pi, float ref, float measured) {
	float error = ref - measured;
	pi->output += pi->Kp * (error - pi->prev_error) + pi->Ki * error;
	pi->prev_error = error;
}
