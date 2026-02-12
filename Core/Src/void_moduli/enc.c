#include "void_moduli/enc.h"

int asdf = 0;

void encoders_init() {
	TIM2->CNT = ENC_START_INC;
	TIM5->CNT = ENC_START_INC;
}

int32_t enc1_get_delta_inc() {
	int32_t tmp = (TIM2->CNT - ENC_START_INC);
	asdf += tmp;
	TIM2->CNT = ENC_START_INC;
	return tmp;
}

int32_t enc2_get_delta_inc() {
	int32_t tmp = (TIM5->CNT - ENC_START_INC);
	TIM5->CNT = ENC_START_INC;
	return tmp;
}
