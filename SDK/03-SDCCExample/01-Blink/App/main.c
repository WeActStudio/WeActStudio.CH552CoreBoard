// Blink an LED connected to pin 1.7

#include <stdint.h>
#include <string.h>>

#include "ch552.h"
#include "debug.h"
#include "bootloader.h"

#include "time.h"

#define ENABLE_IAP_PIN 6
SBIT(EnableIAP, 0xB0, ENABLE_IAP_PIN);
#define LED_PIN 0
SBIT(LED, 0xB0, LED_PIN);

void IAP_Init()
{
    P3_MOD_OC = P3_MOD_OC | (1 << ENABLE_IAP_PIN);
    P3_DIR_PU = P3_DIR_PU | (1 << ENABLE_IAP_PIN);

    mDelaymS(10);

    if (EnableIAP == 1)
    {

        EA = 0; //Close the total interrupt, must add
        mDelaymS(100);

        bootloader();
    }
}

void main()
{
    CfgFsys();

    mDelaymS(100);

    IAP_Init();

    time_MsTick_init();

    EA = 1;
    
    uint8_t time_div,time_tick,task_tick;
    time_div = 1;
	time_tick = 0;
	task_tick = 5;
    while (1)
    {
        time_tick++;
		if(time_tick > 100)
		{
			time_tick = 0;
			time_div ++;
			if(time_div == task_tick)
			{
				time_div = 1;
				LED = !LED;
			}
		}

        time_MsTick_Delay(0); // 1ms

        if (EnableIAP == 1)
        {
            USB_INT_EN = 0;
            USB_CTRL = bUC_RESET_SIE | bUC_CLR_ALL | bUC_DMA_EN;
            EA = 0; 

            mDelaymS(100);
            bootloader();
        }
    }
}

void Timer2_Interrupt(void) __interrupt(INT_NO_TMR2)
{
    time_MsTickInterrupt();
}
