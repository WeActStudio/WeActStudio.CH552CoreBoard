#pragma once

void time_MsTick_init(void);
uint16_t time_MsTick_Get(void);
void time_MsTick_Delay(uint16_t delay);
void time_MsTickInterrupt(void);

uint8_t mTimer_x_ModInit(uint8_t x, uint8_t mode);
void mTimer_x_SetData(uint8_t x, uint16_t dat);
