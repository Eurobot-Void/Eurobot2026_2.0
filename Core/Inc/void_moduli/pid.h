#ifndef INC_VOID_MODULI_PID_H_
#define INC_VOID_MODULI_PID_H_

typedef struct {
	const float Kp, Ki;
	float prev_error, output;
} PI_t;

void update_PI(PI_t *pi, float ref, float measured);

#endif /* INC_VOID_MODULI_PID_H_ */
