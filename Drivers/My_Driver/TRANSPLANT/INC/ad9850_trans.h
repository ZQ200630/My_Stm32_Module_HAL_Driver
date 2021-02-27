//
// Created by 28142 on 2021/2/27.
//
#include "ad9850.h"

#ifndef __AD9850_TRANS_H
#define __AD9850_TRANS_H

/* AD9850 控制和数据引脚定义 */
#define MY_AD9850_CONTROL_PORT  GPIOA
#define MY_AD9850_FQUD_PIN   GPIO_PIN_2
#define MY_AD9850_WCLK_PIN   GPIO_PIN_3
#define MY_AD9850_RST_PIN    GPIO_PIN_4

#ifdef MODE_PARALLEL  //并行模式数据口0~7
#define MY_AD9850_DATA_PORT_PARALLEL  GPIOC
#endif

#ifdef MODE_SEIAL   //串行模式数据口
#define MY_AD9850_DATA_PORT_SERIAL GPIOA
#define MY_AD9850_DATA_PIN GPIO_PIN_5
#endif

#endif //__AD9850_TRANS_H
