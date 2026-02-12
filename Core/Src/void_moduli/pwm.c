#include <math.h>
#include "timer.h"
#include "gpio.h"
#include "void_moduli/pwm.h"
#include "void_moduli/position.h"
#include "void_moduli/util.h"

volatile float v_l_measured = 0;
volatile float v_r_measured = 0; //brzine lijevog i desnog tocka koje se racunaju u odom.c

const float v_r_max = 0.5; //moramo ograniciti
const float v_l_max = 0.5;

volatile float v_r_ref = 0; //one koje treba da dostignemo, racunaju se u set_ref_velocity
volatile float v_l_ref = 0;

volatile float v_r_trapez = 0;
volatile float v_l_trapez = 0;

const float acc_max = 0.25;

volatile float motor_output_l = 0; //izlaz pid regulatora
volatile float motor_output_r = 0;
const float Kp_l = 25, Kp_r = 20; //Kp povecavamo dok robot ne krene da podrhtava, a onda Ki povecavamo, i omda Kp sredimo
const float Ki_l = 2.5, Ki_r = 2;
volatile float prev_error_l = 0; //prethodna greska
volatile float prev_error_r = 0;

void set_ref_velocity(float v, float w) {
	v_r_ref = v + w * HALF_SEPARATION_WHEEL;
	v_l_ref = v - w * HALF_SEPARATION_WHEEL;

	v_l_ref = clamp(v_l_ref, -v_l_max, v_l_max);
	v_r_ref = clamp(v_r_ref, -v_r_max, v_r_max);
}

static inline void set_motor_voltage(float voltage, volatile uint32_t *CCR, uint16_t GPIO_Pin) {
	voltage = clamp(voltage, -MAX_VOLTAGE, MAX_VOLTAGE);
	GPIO_PinState direction = (voltage > 0) ? GPIO_PIN_RESET : GPIO_PIN_SET;
	HAL_GPIO_WritePin(GPIOA, GPIO_Pin, direction); //na nuli kad ide napred
	*CCR = (uint32_t) (fabsf(voltage) / MAX_VOLTAGE * ARR_MAX); //koliki je pwm signal
}

void set_m_left_voltage(float voltage) {
	set_motor_voltage(voltage, &TIM4->CCR1, GPIO_PIN_9);
}

void set_m_right_voltage(float voltage) {
	set_motor_voltage(voltage, &TIM3->CCR2, GPIO_PIN_8);
}

static inline float update_trapez(float v_ref, float v_trapez, float step) {
	float diff = v_ref - v_trapez; //koliko jos treba da dostignem brzinu
	//ako je diff negativno, brzina je velika, treba usporiti
	//znaci ako je veca razlika od toga koliko smijem promijeniti brzinu odjednom
	v_trapez += clamp(diff, -step, step);
	return v_trapez;
}

void bdc_loop() {
	float step = acc_max * DT; //ovo je zapravo promjena brzine(maksimalna odjednom)

	v_l_trapez = update_trapez(v_l_ref, v_l_trapez, step);
	v_r_trapez = update_trapez(v_r_ref, v_r_trapez, step);

	//PI REGULACIJA
	float error_l = v_l_trapez - v_l_measured;
	float error_r = v_r_trapez - v_r_measured; //brzina koja nam treba minus mjerena, trapezna brzina je izracunata brzina koja nam treba

	motor_output_l += Kp_l * (error_l - prev_error_l) + Ki_l * error_l;
	motor_output_r += Kp_r * (error_r - prev_error_r) + Ki_r * error_r;

	prev_error_l = error_l;
	prev_error_r = error_r;

	motor_output_l = clamp(motor_output_l, -MAX_VOLTAGE, MAX_VOLTAGE);
	motor_output_r = clamp(motor_output_r, -MAX_VOLTAGE, MAX_VOLTAGE); //opet da ogranicimo ako je izlazni napon iz regulatora veci ili manji od maksimalnog napona koji mozemo dovesti na motor
	//Medjutim, takav napon ne mozemo dovesti na drajver, treba nam smjer i pwm signal

	set_m_left_voltage(motor_output_l);
	set_m_right_voltage(motor_output_r); //znaci odredili smo i smjer i ccr registar
}
