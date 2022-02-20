#include "ch552.h"
#include "Debug.h"
#include "iap.h"

sbit LED = P3^0;

void main()
{
	UINT8 time_div,time_tick,task_tick;
	
	CfgFsys();
	mDelaymS(10);

	IAP_Init();
	
	time_div = 1;
	time_tick = 100;
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
			
		mDelaymS(1);
		
		if (IsEnableIAP() == 1)
		{

			EA = 0;
			USB_INT_EN = 0x00;
            USB_CTRL = bUC_RESET_SIE | bUC_CLR_ALL;
            mDelaymS(100);

			bootloader();
		}
	}
}
