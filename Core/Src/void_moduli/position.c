#include <math.h>
#include "void_moduli/position.h"
#include "void_moduli/odom.h"
#include "void_moduli/pwm.h"
#include "void_moduli/util.h"

#define V_MIN 0.05
#define W_MIN 0.03

const float Kp_w = 0.0;
const float v_max = 0.7; //m/s
const float a_max = 0.2; //m/s*s
float x_ref = 0.0, y_ref = 0.0, theta_ref = 0.0;
const float eps_dist = 0.05f;   // 5 cm
const float eps_theta = 0.01745f; // 1 stepen
const float w_max = 1.0f; //rad/s
const float alpha_max = 0.5; //rad/s*s ugaono ubrzanje
float x_p = 0, y_p = 0, theta_p = 0;

//Potrebno za sintezu trajektorije
static float s_total; //ukupni put do cilja
static float s1, s2, s3; //tri puta, jedan prilikom ubrzavanja, jedan konstantna brzina, i jedan prilikom usporavanja, to je trapezni profil brzine

static float th_total; //ukupni ugao
static float th1, th2, th3;

static float v_peak;
static float w_peak;
float th = 0.0;

Motion_state_t current_state = IDLE;

void set_ref_position(float x_goal, float y_goal, float theta_goal) {
	if (current_state == IDLE) {
		x_ref = x_goal;
		y_ref = y_goal;
		theta_ref = theta_goal;

		float dx = x_ref - x;
		float dy = y_ref - y;

		s_total = hypotf(dx, dy);

		x_p = x;
		y_p = y;
		theta_p = theta;

		//Sad izracunamo s1, s2 i s3 na osnovu svega
		//mozemo s1, jer je v0 na pocetku 0
		s1 = (v_max * v_max) / (2 * a_max);
		s3 = s1;
		s2 = s_total - 2 * s1;

		//Ako je put bas kratak, trougaoni profil, nikad se ne dostize vmax
		if (s2 < 0) {
			s1 = s_total / 2;
			s2 = 0;
			s3 = s1;
		}
		v_peak = sqrtf(2.0f * a_max * s1); //odmah izracunamo i znamo onda da li smo dostigli v_max, kad se s1 prepolovi ako imamo trougaoni profil

		float heading_angle = atan2f(dy, dx);
		th_total = fabsf(normalize_rad_angle(heading_angle - theta)); //ukupan ugao za koji robot treba da se okrene
		th1 = (w_max * w_max) / (2.0f * alpha_max);
		th3 = th1;
		th2 = th_total - 2.0f * th1;

		if (th2 < 0.0f) {
			th1 = th_total / 2.0f;
			th2 = 0.0f;
			th3 = th1;
		}

		// stvarni maksimum brzine profila
		w_peak = sqrtf(2.0f * alpha_max * th1);

		current_state = HEADING_POSE;
	}

}

static inline float trajectory(float dist, float dist1, float dist2,
		float dist_total, float vel_peak, float acc_max, float vel_min) {
	float vel;

	if (dist < dist1) {
		vel = sqrtf(2.0f * acc_max * dist);
	} else if (dist <= dist1 + dist2) {
		vel = vel_peak;
	} else if (dist <= dist_total) {
		vel = sqrtf(
				vel_peak * vel_peak - 2.0f * acc_max * (dist - dist1 - dist2));
	} else {
		vel = 0.0f;
	}

	if (0.0f < vel && vel < vel_min) {
		vel = vel_min;
	}

	return vel;
}

static float trajectory_v(float s) {
	return trajectory(s, s1, s2, s_total, v_peak, a_max, V_MIN);
}

static float trajectory_w(float th) {
	return trajectory(th, th1, th2, th_total, w_peak, alpha_max, W_MIN);
}

void position_loop() {
	float v_ref = 0;
	float w_ref = 0;
	//uzmi da je s=sqrt((y-yp)na kvadrat +(x-xp)na kvadrat za distancu

	float dx = x_ref - x; //x zeljeno minus trenutno x, dobijemo x koje treba da predjemo
	float dy = y_ref - y;

	float heading_angle = atan2f(dy, dx);

	float distance_error = hypotf(dx, dy);
	float heading_error = normalize_rad_angle(heading_angle - theta); //imamo 3 faze, pa zato imamo i tri greske, prva faza je rotacija ka zeljenom pravcu, druga faza je translaciji, treca faza je rotacija ka cilju

	switch (current_state) {
	case HEADING_POSE:
		v_ref = 0;
//      th_total = fabsf (normalize_rad_angle (heading_angle - theta)); //ukupan ugao za koji robot treba da se okrene
//      th1 = (w_max * w_max) / (2.0f * alpha_max);
//      th3 = th1;
//      th2 = th_total - 2.0f * th1;
//
//      if (th2 < 0.0f)
//	{
//	  th1 = th_total / 2.0f;
//	  th2 = 0.0f;
//	  th3 = th1;
//	}
//      // stvarni maksimum brzine profila
//      w_peak = sqrtf (2.0f * alpha_max * th1);

		th = fabsf(normalize_rad_angle(theta - theta_p));
		w_ref = trajectory_w(th);

		if (fabsf(heading_error) < eps_theta) {
			current_state = TRANSLATE_TO_GOAL;
		}
		break;
	case TRANSLATE_TO_GOAL:
		float s = hypotf(y - y_p, x - x_p); //koliko smo presli do sada ka cilju
		v_ref = trajectory_v(s);

		if (distance_error < eps_dist) {
			w_ref = 0;
			current_state = GOAL_POSITION;
		}
		break;
	case GOAL_POSITION:
		v_ref = 0.0;
		w_ref = 0.0;
		break;
	}
	set_ref_velocity(v_ref, w_ref);
}
