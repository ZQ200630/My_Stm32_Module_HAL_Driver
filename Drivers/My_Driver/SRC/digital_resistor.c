//
// Created by 28142 on 2021/2/26.
//
#include "digital_resistor.h"

void MyResInc() {
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

void MyResDec() {
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

void MyResClear() {
    for (int i = 0; i < 120; ++i) {
        MyResDec();
    }
}

void MyResIncValue(int Value) {
    for (int i = 0; i < Value; i++) {
        MyResInc();
    }
}

void MyResDecValue(int Value) {
    for (int i = 0; i < Value; i++) {
        MyResDec();
    }
}

void MyResToValue(int Value) {
    MyResClear();
    MyResDecValue(Value);
}