#ifndef __IAP_H__
#define __IAP_H__

void IAP_Init(void);
bit IsEnableIAP(void);

extern void (* data bootloader)(void);


#endif
