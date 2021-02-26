//
// Created by 28142 on 2021/2/26.
//
#include "basic.h"


void MyOperateCS(MY_PinState PinState) {
    switch (PinState) {
        case MY_PIN_SET:
            HAL_GPIO_WritePin(MY_CS_PORT, MY_CS_PIN, GPIO_PIN_SET);
            break;
        case MY_PIN_RESET:
            HAL_GPIO_WritePin(MY_CS_PORT, MY_CS_PIN, GPIO_PIN_RESET);
            break;
        default:
            break;
    }
}

void MyOperateINC(MY_PinState PinState) {
    switch (PinState) {
        case MY_PIN_SET:
            HAL_GPIO_WritePin(MY_INC_PORT, MY_INC_PIN, GPIO_PIN_SET);
            break;
        case MY_PIN_RESET:
            HAL_GPIO_WritePin(MY_INC_PORT, MY_INC_PIN, GPIO_PIN_RESET);
            break;
        default:
            break;
    }
}

void MyOperateUD(MY_PinState PinState) {
    switch (PinState) {
        case MY_PIN_SET:
            HAL_GPIO_WritePin(MY_INC_PORT, MY_INC_PIN, GPIO_PIN_SET);
            break;
        case MY_PIN_RESET:
            HAL_GPIO_WritePin(MY_INC_PORT, MY_INC_PIN, GPIO_PIN_RESET);
            break;
        default:
            break;
    }
}

void MyDelayUs(int Delay) {

}


void MyDelayMs(int Delay) {

}