#include "xc9104.h"

void MyXC9104Inc() {
    MyOperateUD(MY_PIN_SET);
    MyDelayUs(1);
    MyOperateCS(MY_PIN_RESET);
    MyDelayUs(1);
    MyOperateINC(MY_PIN_RESET);
    MyDelayUs(10);
    MyOperateINC(MY_PIN_SET);
    MyDelayUs(10);
    MyOperateCS(MY_PIN_SET);
}

void MyXC9104Dec() {
    MyOperateUD(MY_PIN_RESET);
    MyDelayUs(1);
    MyOperateCS(MY_PIN_RESET);
    MyDelayUs(1);
    MyOperateINC(MY_PIN_RESET);
    MyDelayUs(10);
    MyOperateINC(MY_PIN_SET);
    MyDelayUs(10);
    MyOperateCS(MY_PIN_SET);
}

void MyXC9104Clear() {
    for (int i = 0; i < 120; ++i) {
        MyXC9104Dec();
    }
}

void MyXC9104IncValue(int Value) {
    for (int i = 0; i < Value; i++) {
        MyXC9104Inc();
    }
}

void MyXC9104DecValue(int Value) {
    for (int i = 0; i < Value; i++) {
        MyXC9104Dec();
    }
}

void MyXC9104ToValue(int Value) {
    MyXC9104Clear();
    MyXC9104DecValue(Value);
}