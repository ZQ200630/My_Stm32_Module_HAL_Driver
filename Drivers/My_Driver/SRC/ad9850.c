#include "ad9850.h"

/*--------------------并行模式-----------------------*/
#ifdef MODE_PARALLEL
/********************************************
函数名称：AD9850_Reset_Parallel
功    能：在并行模式下复位AD9850
参    数：无
返回值  ：无
*********************************************/
void MyAD9850ResetParallel(void)
{
    MyOperateWCLK(MY_PIN_RESET);
    MyOperateFQUD(MY_PIN_RESET);
    //RST信号
    MyOperateRST(MY_PIN_RESET);
    MyOperateRST(MY_PIN_SET);
    MyDelayMs(2);
    MyOperateRST(MY_PIN_RESET);
}

/********************************************
函数名称：AD9850_Write_Parallel
功    能：在并行模式下写AD9850寄存器
参    数：W0 - W0寄存器的值
          freq - 频率值
返回值  ：无
*********************************************/
void MyAD9850WriteParallel(unsigned char W0,unsigned long freq)
{
    unsigned char wdata ;
    unsigned long  y=(unsigned long)(4294967295/MY_AD9850_SYSTEM_COLCK) ;
    y *= freq ;
    wdata=W0 ;  //写w0
    MyOperateDataParallel(wdata); //MY_AD9850_DATA_PORT
    MyOperateWCLK(MY_PIN_SET);
    MyOperateWCLK(MY_PIN_RESET);

    wdata=y>>24 ;  //写w1
    MyOperateDataParallel(wdata);
    MyOperateWCLK(MY_PIN_SET);
    MyOperateWCLK(MY_PIN_RESET);

    wdata=y>>16 ;  //写w2
    MyOperateDataParallel(wdata);
    MyOperateWCLK(MY_PIN_SET);
    MyOperateWCLK(MY_PIN_RESET);

    wdata=y>>8 ;  //写w3
    MyOperateDataParallel(wdata);
    MyOperateWCLK(MY_PIN_SET);
    MyOperateWCLK(MY_PIN_RESET);

    wdata=y>>0 ;  //写w4
    MyOperateDataParallel(wdata);
    MyOperateWCLK(MY_PIN_SET);
    MyOperateWCLK(MY_PIN_RESET);

    MyOperateFQUD(MY_PIN_SET);  //移入使能
    MyDelayMs(2);
    MyOperateFQUD(MY_PIN_RESET);
}
#endif /* MODE_PARALLEL */
/*------------------------并行模式-------------------------*/
/*---------------------------------------------------------*/

/*------------------------串行模式-------------------------*/
#ifdef MODE_SEIAL
/********************************************
函数名称：AD9850_Reset_Sreial
功    能：在串行模式下复位AD9850
参    数：无
返回值  ：无
*********************************************/
void MyAD9850ResetSreial(void)
{
    MyOperateWCLK(MY_PIN_RESET);
    MyOperateFQUD(MY_PIN_RESET);

    //RST信号
    MyOperateRST(MY_PIN_RESET);
    MyOperateRST(MY_PIN_SET);
    MyDelayMs(2);
    MyOperateRST(MY_PIN_RESET);

    //WCLK信号
    MyOperateWCLK(MY_PIN_RESET);
    MyOperateWCLK(MY_PIN_SET);
    MyDelayMs(2);
    MyOperateWCLK(MY_PIN_RESET);

    //FQUD信号
    MyOperateFQUD(MY_PIN_RESET);
    MyOperateFQUD(MY_PIN_SET);

    MyDelayMs(2);
    MyOperateFQUD(MY_PIN_RESET);
}

/********************************************
函数名称：AD9850_Write_Serial
功    能：在串行模式下写AD9850寄存器
参    数：W0 - W0寄存器的值
          freq - 频率值
返回值  ：无
*********************************************/
void MyAD9850WriteSerial(unsigned char W0,unsigned long freq)
{
    unsigned char i,wdata ;
    unsigned long  y ;
    y = (unsigned long )268435456.0/MY_AD9850_SYSTEM_COLCK*freq ;

    wdata = y>>0 ;   //写w4
    for(i=0 ;i<8 ;i++)
    {
        if(wdata & 0x01)
            MyOperateDataSerial(MY_PIN_SET);
        else
            MyOperateDataSerial(MY_PIN_RESET);
        MyOperateWCLK(MY_PIN_SET);
        wdata >>= 1 ;
        MyOperateWCLK(MY_PIN_RESET);
    }
    wdata = y>>8 ;  //写w3
    for(i=0 ;i<8 ;i++)
    {
        if(wdata & 0x01)
            MyOperateDataSerial(MY_PIN_SET);
        else
            MyOperateDataSerial(MY_PIN_RESET);
        MyOperateWCLK(MY_PIN_SET);
        wdata >>= 1 ;
        MyOperateWCLK(MY_PIN_RESET);
    }
    wdata = y>>16 ;  //写w2
    for(i=0 ;i<8 ;i++)
    {
        if(wdata & 0x01)
            MyOperateDataSerial(MY_PIN_SET);
        else
            MyOperateDataSerial(MY_PIN_RESET);
        MyOperateWCLK(MY_PIN_SET);
        wdata >>= 1 ;
        MyOperateWCLK(MY_PIN_RESET);
    }
    wdata = y>>24 ;  //写w1
    for(i=0 ;i<8 ;i++)
    {
        if(wdata & 0x01)
            MyOperateDataSerial(MY_PIN_SET);
        else
            MyOperateDataSerial(MY_PIN_RESET);
        MyOperateWCLK(MY_PIN_SET);
        wdata >>= 1 ;
        MyOperateWCLK(MY_PIN_RESET);
    }
    wdata = W0 ;  //写w0
    for(i=0 ;i<8 ;i++)
    {
        if(wdata & 0x01)
            MyOperateDataSerial(MY_PIN_SET);
        else
            MyOperateDataSerial(MY_PIN_RESET);
        MyOperateWCLK(MY_PIN_SET);
        wdata >>= 1 ;
        MyOperateWCLK(MY_PIN_RESET);
    }

    MyOperateFQUD(MY_PIN_SET);  //移入使能
    MyDelayMs(2);
    MyOperateFQUD(MY_PIN_RESET);
}
#endif /* MODE_SERIAL */
/*------------------------串行模式-------------------------*/
/*---------------------------------------------------------*/

