/*--------------------------------------------

            AD9850驱动程序

----------------------------------------------*/

#ifndef __AD9850_H
#define __AD9850_H

#include "sys.h"

/*选择数据通信方式，只能选择一个*/
//#define MODE_SEIAL   //串行模式
#define MODE_PARALLEL  //并行模式

#define MY_AD9850_SYSTEM_COLCK     100000000

#ifdef MODE_SEIAL   //串行模式数据口
void MyOperateDataSerial(MY_PinState PinState);
#endif

void MyOperateWCLK(MY_PinState PinState);

void MyOperateFQUD(MY_PinState PinState);

void MyOperateRST(MY_PinState PinState);

void MyOperateDataParallel(unsigned char W0);

/* 串行模式操作函数 */
#ifdef MODE_SEIAL
void MyAD9850ResetSreial(void) ;
void MyAD9850WriteSerial(unsigned char W0,unsigned long freq) ;
#endif

/* 并行模式操作函数 */
#ifdef MODE_PARALLEL
void MyAD9850ResetParallel(void) ;
void MyAD9850WriteParallel(unsigned char W0,unsigned long freq) ;
#endif

void Init_AD9850(void) ;

#endif /* AD8950_H */
