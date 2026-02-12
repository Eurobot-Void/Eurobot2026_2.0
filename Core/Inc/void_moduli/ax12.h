#ifndef INC_VOID_MODULI_AX12_H_
#define INC_VOID_MODULI_AX12_H_

#include "usart.h"

#define AX12_ID 6
#define INSTRUCTION_WRITE 0x03 //instrukcija za upisivanje vrednosti u registar
#define AX12_GOAL_POSITION 0x1E //u ovaj registar se upisuje
#define AX12_RACK_DOWN 100
#define AX12_RACK_UP 950 //POZICIJE LETVE-sigurne vrednosti

void ax12_init(UART_HandleTypeDef *huart); //funkcija u kojoj govorimo koji uart koristimo
void ax12_set_position(uint8_t id, uint16_t position);
void ax12_rack_down(void);
void ax12_rack_up(void);

#endif /* INC_VOID_MODULI_AX12_H_ */
