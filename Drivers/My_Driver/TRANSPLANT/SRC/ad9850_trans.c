#include "ad9850_trans.h"
#include "config.h"

void MyOperateWCLK(MY_PinState PinState) {
    switch (PinState) {
        case MY_PIN_SET:
            HAL_GPIO_WritePin(MY_AD9850_CONTROL_PORT, MY_AD9850_WCLK_PIN, GPIO_PIN_SET);
            break;
        case MY_PIN_RESET:
            HAL_GPIO_WritePin(MY_AD9850_CONTROL_PORT, MY_AD9850_WCLK_PIN, GPIO_PIN_RESET);
            break;
        default:
            break;
    }
}

void MyOperateFQUD(MY_PinState PinState) {
    switch (PinState) {
        case MY_PIN_SET:
            HAL_GPIO_WritePin(MY_AD9850_CONTROL_PORT, MY_AD9850_FQUD_PIN, GPIO_PIN_SET);
            break;
        case MY_PIN_RESET:
            HAL_GPIO_WritePin(MY_AD9850_CONTROL_PORT, MY_AD9850_FQUD_PIN, GPIO_PIN_RESET);
            break;
        default:
            break;
    }
}

void MyOperateRST(MY_PinState PinState) {
    switch (PinState) {
        case MY_PIN_SET:
            HAL_GPIO_WritePin(MY_AD9850_CONTROL_PORT, MY_AD9850_RST_PIN, GPIO_PIN_SET);
            break;
        case MY_PIN_RESET:
            HAL_GPIO_WritePin(MY_AD9850_CONTROL_PORT, MY_AD9850_RST_PIN, GPIO_PIN_RESET);
            break;
        default:
            break;
    }
}

void MyOperateDataParallel(unsigned char W0) {
    MY_AD9850_DATA_PORT_PARALLEL->ODR = W0;
}


/********************************************
函数名称：Init_AD9834
功    能：初始化AD9834
参    数：无
返回值  ：无
*********************************************/
void Init_AD9850(void)
{

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Pin = MY_AD9850_FQUD_PIN | MY_AD9850_WCLK_PIN | MY_AD9850_RST_PIN;
    HAL_GPIO_Init(MY_AD9850_CONTROL_PORT, &GPIO_InitStruct);
#ifdef MODE_SEIAL   //串行模式
    GPIO_InitStruct.Pin = GPIO_PIN_5;
    HAL_GPIO_Init(MY_AD9850_DATA_PORT_SERIAL, &GPIO_InitStruct);
    MyAD9850ResetSreial() ;
#endif

#ifdef MODE_PARALLEL //并行模式
    GPIO_InitStruct.Pin = GPIO_PIN_All;
    HAL_GPIO_Init(MY_AD9850_DATA_PORT_PARALLEL, &GPIO_InitStruct);
    MyAD9850ResetParallel();
#endif

}

