#include <stdint.h>
#include <string.h>
#include "ch552.h"

#include "time.h"

uint16_t __xdata utick;

void time_MsTick_init(void)
{
    utick = 0;
    T2MOD |= (bTMR_CLK | bT2_CLK);
    C_T2 = 0;
    RCLK = 0;
    TCLK = 0;
    CP_RL2 = 0;
    //mTimer_x_ModInit(2, 1);
    mTimer_x_SetData(2, 24000); // 1ms
    TR2 = 1;
    ET2 = 1;
}

void time_MsTick_Inc(void)
{
    utick = utick + 1;
}

uint16_t time_MsTick_Get(void)
{
    return utick;
}

void time_MsTick_Delay(uint16_t delay)
{
    uint16_t __xdata tickstart = time_MsTick_Get();
    uint16_t __xdata wait = delay;

    /* Add a freq to guarantee minimum wait */
    if (wait < 65535)
    {
        wait += 1;
    }

    while ((time_MsTick_Get() - tickstart) < wait)
    {
    }
}

void time_MsTickInterrupt(void)
{
    utick++;
    TF2 = 0;                                                                                                                  
}

/*******************************************************************************
* Function Name  : mTimer_x_ModInit(UINT8 x ,UINT8 mode)
* Description    : CH554定时计数器x模式设置
* Input          : UINT8 mode,Timer模式选择
                   0：模式0，13位定时器，TLn的高3位无效
                   1：模式1，16位定时器
                   2：模式2，8位自动重装定时器
                   3：模式3，两个8位定时器  Timer0
                   3：模式3，Timer1停止									 
* Output         : None
* Return         : 成功  SUCCESS
                   失败  FAIL
*******************************************************************************/
uint8_t mTimer_x_ModInit(uint8_t x, uint8_t mode)
{
    if (x == 0)
    {
        TMOD = TMOD & 0xf0 | mode;
    }
    else if (x == 1)
    {
        TMOD = TMOD & 0x0f | (mode << 4);
    }
    else if (x == 2)
    {
        RCLK = 0;
        TCLK = 0;
        CP_RL2 = 0;
    } //16位自动重载定时器
    else
        return 1;
    return 0;
}

/*******************************************************************************
* Function Name  : mTimer_x_SetData(UINT8 x,UINT16 dat)
* Description    : CH554Timer0 TH0和TL0赋值
* Input          : UINT16 dat;定时器赋值
* Output         : None
* Return         : None
*******************************************************************************/
void mTimer_x_SetData(uint8_t x, uint16_t dat)
{
    uint16_t __xdata tmp;
    tmp = 65536 - dat;
    if (x == 0)
    {
        TL0 = tmp & 0xff;
        TH0 = (tmp >> 8) & 0xff;
    }
    else if (x == 1)
    {
        TL1 = tmp & 0xff;
        TH1 = (tmp >> 8) & 0xff;
    }
    else if (x == 2)
    {
        RCAP2L = TL2 = tmp & 0xff; //16位自动重载定时器
        RCAP2H = TH2 = (tmp >> 8) & 0xff;
    }
}
