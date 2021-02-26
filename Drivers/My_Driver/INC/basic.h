//
// Created by 28142 on 2021/2/26.
//

#ifndef TEMPLATE_BASIC_H
#define TEMPLATE_BASIC_H

#include "stm32f4xx_hal.h"

typedef enum
{
    MY_PIN_RESET = 0,
    MY_PIN_SET = 1
}MY_PinState;

// Define CS Port And CS Pin
#define MY_CS_PIN GPIO_PIN_3
#define MY_CS_PORT GPIOA

// Define INC Port And INC Pin
#define MY_INC_PIN GPIO_PIN_4
#define MY_INC_PORT GPIOA

// Define UP/DOWN Port And UP/DOWN Pin
#define MY_UD_PIN GPIO_PIN_5
#define MY_UD_PORT GPIOA


void MyOperateCS(MY_PinState PinState);
void MyOperateINC(MY_PinState PinState);
void MyOperateUD(MY_PinState PinState);
void MyDelayMs(int Delay);
void MyDelayUs(int Delay);

#endif //TEMPLATE_BASIC_H
