#include "void_moduli/servo.h"
#include "void_moduli/util.h"

#define PCA9685_MODE1       0x00  // str. 10, datasheet
#define PCA9685_MODE2       0x01
#define PCA9685_LED0_ON_L   0x06
#define PCA9685_PRESCALE    0xFE

#define MODE1_RESTART       7     // str 14.
#define MODE1_SLEEP         4
#define MODE1_AI            5

#define PCA9685_OSC_FREQ    25000000UL // 25MHz fiksna vrednost unutrasnjeg oscilatora, iz datasheet
#define PCA9685_PWM_RES     4096        // 12-bitni je driver

static I2C_HandleTypeDef *servo_i2c;

static void PCA9685_write_reg(uint8_t reg, uint8_t data) {
	HAL_I2C_Mem_Write(servo_i2c, PCA9685_ADDR, reg, 1, &data, 1, 10);
}

static uint8_t PCA9685_read_reg(uint8_t reg) {
	uint8_t data;
	HAL_I2C_Mem_Read(servo_i2c, PCA9685_ADDR, reg, 1, &data, 1, 10);
	return data;
}

static void PCA9685_set_pwm_freq(float freq) {
	uint8_t oldmode = PCA9685_read_reg(PCA9685_MODE1);
	uint8_t sleepmode = (oldmode & ~(1 << MODE1_RESTART)) | (1 << MODE1_SLEEP);

	float prescale_value = (PCA9685_OSC_FREQ / (PCA9685_PWM_RES * freq)) - 1.0f; // formula iz datasheet-a, str. 25
	uint8_t prescale = (uint8_t) (prescale_value + 0.5f); // castujemo zato sto reg prihvata samo 8 bita i zaokruzujemo

	PCA9685_write_reg(PCA9685_MODE1, sleepmode);
	PCA9685_write_reg(PCA9685_PRESCALE, prescale);
	PCA9685_write_reg(PCA9685_MODE1, oldmode);
	HAL_Delay(1);
	PCA9685_write_reg(PCA9685_MODE1, oldmode | (1 << MODE1_RESTART));
}

static void PCA9685_set_pwm(uint8_t channel, uint16_t on, uint16_t off) {
	uint8_t reg = PCA9685_LED0_ON_L + 4 * channel;
	uint8_t data[4];
	data[0] = on & 0xFF;
	data[1] = on >> 8;
	data[2] = off & 0xFF;
	data[3] = off >> 8;
	HAL_I2C_Mem_Write(servo_i2c, PCA9685_ADDR, reg, 1, data, 4, 10);
}

void servo_init(I2C_HandleTypeDef *hi2c) {
	servo_i2c = hi2c;
	PCA9685_write_reg(PCA9685_MODE1, (1 << MODE1_AI));
	PCA9685_write_reg(PCA9685_MODE2, 0x04);
	PCA9685_set_pwm_freq(SERVO_HZ);
}

void servo_set_angle(uint8_t channel, float angle) {
	if (channel >= SERVO_COUNT)
		return;
	angle = clamp(angle, 0.0f, 180.0f);
	float pulse_imp = SERVO_MIN_IMP
			+ (angle / 180.0f) * (SERVO_MAX_IMP - SERVO_MIN_IMP);
	float ticks = (pulse_imp * SERVO_HZ * PCA9685_PWM_RES) / 1000000.0f;
	PCA9685_set_pwm(channel, 0, (uint16_t) ticks);
}
