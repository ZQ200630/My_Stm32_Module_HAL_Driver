/*--------------------------------------------

            XC9104驱动程序

----------------------------------------------*/

#ifndef __XC9104_H
#define __XC9104_H

#include "sys.h"

void MyOperateCS(MY_PinState PinState);
void MyOperateINC(MY_PinState PinState);
void MyOperateUD(MY_PinState PinState);

void MyXC9104Init();
void MyXC9104Inc();
void MyXC9104Dec();
void MyXC9104Clear();
void MyXC9104ToValue(int Value);
void MyXC9104IncValue(int Value);
void MyXC9104DecValue(int Value);

#endif
