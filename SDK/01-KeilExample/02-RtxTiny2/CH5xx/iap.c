#include "ch552.h"
#include "Debug.h"

#include "iap.h"

#define BOOT_ADDR  0x3800
#define ENABLE_IAP_PIN 6

sbit EnableIAP = P3^ENABLE_IAP_PIN;
void (* data bootloader)(void) = BOOT_ADDR;

void IAP_Init(void)
{
    USB_CTRL = 0x00;
    USB_CTRL = bUC_RESET_SIE | bUC_CLR_ALL;
    USB_CTRL &= ~bUC_RESET_SIE;
    UDEV_CTRL &= ~bUD_PD_DIS;
    P3_MOD_OC = P3_MOD_OC & ~ (1 << ENABLE_IAP_PIN);
    P3_DIR_PU = P3_DIR_PU & ~ (1 << ENABLE_IAP_PIN);
    
    mDelaymS(10);

    if(EnableIAP == 1)
    {

        EA = 0;
        TMOD = 0;
        mDelaymS(100);

        bootloader();
    }
}

bit IsEnableIAP(void)
{
	return (UDEV_CTRL&bUD_DP_PIN);
}
