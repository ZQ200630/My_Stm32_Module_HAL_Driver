#include "xc9104_trans.h"
#include "config.h"

void MyOperateCS(MY_PinState PinState) {
    switch (PinState) {
        case MY_PIN_SET:
            HAL_GPIO_WritePin(MY_XC9104_CS_PORT, MY_XC9104_CS_PIN, GPIO_PIN_SET);
            break;
        case MY_PIN_RESET:
            HAL_GPIO_WritePin(MY_XC9104_CS_PORT, MY_XC9104_CS_PIN, GPIO_PIN_RESET);
            break;
        default:
            break;
    }
}

void MyOperateINC(MY_PinState PinState) {
    switch (PinState) {
        case MY_PIN_SET:
            HAL_GPIO_WritePin(MY_XC9104_INC_PORT, MY_XC9104_INC_PIN, GPIO_PIN_SET);
            break;
        case MY_PIN_RESET:
            HAL_GPIO_WritePin(MY_XC9104_INC_PORT, MY_XC9104_INC_PIN, GPIO_PIN_RESET);
            break;
        default:
            break;
    }
}

void MyOperateUD(MY_PinState PinState) {
    switch (PinState) {
        case MY_PIN_SET:
            HAL_GPIO_WritePin(MY_XC9104_UD_PORT, MY_XC9104_UD_PIN, GPIO_PIN_SET);
            break;
        case MY_PIN_RESET:
            HAL_GPIO_WritePin(MY_XC9104_UD_PORT, MY_XC9104_UD_PIN, GPIO_PIN_RESET);
            break;
        default:
            break;
    }
}

void MyXC9104Init() {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Pin = MY_XC9104_CS_PIN;
    HAL_GPIO_Init(MY_XC9104_CS_PORT, &GPIO_InitStruct);
    GPIO_InitStruct.Pin = MY_XC9104_UD_PIN;
    HAL_GPIO_Init(MY_XC9104_UD_PORT, &GPIO_InitStruct);
    GPIO_InitStruct.Pin = MY_XC9104_INC_PIN;
    HAL_GPIO_Init(MY_XC9104_INC_PORT, &GPIO_InitStruct);

    MyXC9104Clear();
}