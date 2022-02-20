#include "ch552.h"
#include "Debug.h"
#include "iap.h"

#include <rtx51tny.h>

sbit LED = P3 ^ 0;

void job0(void) _task_ 0
{
	CfgFsys();
	mDelaymS(10);
	IAP_Init();

	os_create_task(1); /* start task 1                         */
	os_create_task(2); /* start task 2                         */
	os_delete_task(0);
}

void job1(void) _task_ 1
{
	while (1)
	{ /* endless loop                         */
		if (IsEnableIAP() == 1)
		{
			EA = 0; //Close the total interrupt, must add
            USB_INT_EN = 0x00;
            USB_CTRL = bUC_RESET_SIE | bUC_CLR_ALL;
			mDelaymS(100);

			bootloader();
		}
		os_wait2(K_TMO, 5); /* wait for timeout: 5 ticks 50mS           */
	}
}

void job2(void) _task_ 2
{
	bit pwmset = 0;
    
	P3_MOD_OC &= ~(bPWM1_);
	P3_DIR_PU |= bPWM1_;
	PIN_FUNC |= bPWM1_PIN_X;   //PWM映射脚P30
	PWM_CK_SE = 4;			   //分频,默认时钟Fsys
	PWM_CTRL |= bPWM_CLR_ALL;  //强制清除PWM FIFO和COUNT
	PWM_CTRL &= ~bPWM_CLR_ALL; //取消清除PWM FIFO和COUNT
	//PWM_CTRL |= bPWM1_POLAR;   //PWM1输出默认高，低有效
    PWM_CTRL &= ~bPWM1_POLAR;  //PWM1输出默认低，高有效
	PWM_DATA1 = 0x00;		   //设置PWM输出占空比
	PWM_CTRL |= bPWM1_OUT_EN;  //允许PWM1输出

	while (1)
	{ /* endless loop                         */
		if (pwmset == 0)
		{
			pwmset = 1;
			PWM_DATA1 = 0;
		}
		else
		{
			pwmset = 0;
			PWM_DATA1 = 32;
		}
		os_wait2(K_IVL, 50); /* wait for timeout: 50 ticks   500ms       */
	}
}
