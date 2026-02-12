#ifndef INC_VOID_MODULI_PWM_H_
#define INC_VOID_MODULI_PWM_H_

#define MAX_VOLTAGE 12.0 //maksimalan napon koji mozemo dovesti na motor
#define ARR_MAX 2099
#define HALF_SEPARATION_WHEEL 0.07925

extern volatile float v_r_ref;
extern volatile float v_l_ref;

extern volatile float v_r_trapez;
extern volatile float v_l_trapez;

extern volatile float v_r_measured;
extern volatile float v_l_measured; //eksterno definisemo promjenljive jer zelimo da budu vidljive u nekom drugom .c

typedef enum {
	FORWARD, BACKWARD //treba nam za smjer
} Dir_t;

void set_ref_velocity(const float v, const float w);
void bdc_loop();
void set_m_right_voltage(float voltage);
void set_m_left_voltage(float voltage);
void set_dir_m_right(Dir_t dir);
void set_dir_m_left(Dir_t dir);

#endif /* INC_VOID_MODULI_PWM_H_ */
