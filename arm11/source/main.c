/*
* Woomy
*/


#include "types.h"
#include "memory.h"

void prepareForFirmlaunch(void);
extern u32 prepareForFirmlaunchSize;

extern volatile Arm11Operation operation;

static void initScreens(u32 brightnessLevel, struct fb *fbs)
{
    *(vu32 *)0x10141200 = 0x1007F;

    *(vu32 *)0x10202204 = 0x01000000;
    *(vu32 *)0x10202A04 = 0x01000000;

    *(vu32 *)0x10202014 = 0x00000001;
    *(vu32 *)0x1020200C &= 0xFFFEFFFE;
    *(vu32 *)0x10202240 = brightnessLevel;
    *(vu32 *)0x10202A40 = brightnessLevel;
    *(vu32 *)0x10202244 = 0x1023E;
    *(vu32 *)0x10202A44 = 0x1023E;
    *(vu32 *)0x10400400 = 0x000001c2;
    *(vu32 *)0x10400404 = 0x000000d1;
    *(vu32 *)0x10400408 = 0x000001c1;
    *(vu32 *)0x1040040c = 0x000001c1;
    *(vu32 *)0x10400410 = 0x00000000;
    *(vu32 *)0x10400414 = 0x000000cf;
    *(vu32 *)0x10400418 = 0x000000d1;
    *(vu32 *)0x1040041c = 0x01c501c1;
    *(vu32 *)0x10400420 = 0x00010000;
    *(vu32 *)0x10400424 = 0x0000019d;
    *(vu32 *)0x10400428 = 0x00000002;
    *(vu32 *)0x1040042c = 0x00000192;
    *(vu32 *)0x10400430 = 0x00000192;
    *(vu32 *)0x10400434 = 0x00000192;
    *(vu32 *)0x10400438 = 0x00000001;
    *(vu32 *)0x1040043c = 0x00000002;
    *(vu32 *)0x10400440 = 0x01960192;
    *(vu32 *)0x10400444 = 0x00000000;
    *(vu32 *)0x10400448 = 0x00000000;
    *(vu32 *)0x1040045C = 0x00f00190;
    *(vu32 *)0x10400460 = 0x01c100d1;
    *(vu32 *)0x10400464 = 0x01920002;
    *(vu32 *)0x10400468 = (u32)fbs[0].top_left;
    *(vu32 *)0x1040046C = (u32)fbs[1].top_left;
    *(vu32 *)0x10400470 = 0x80341;
    *(vu32 *)0x10400474 = 0x00010501;
    *(vu32 *)0x10400478 = 0;
    *(vu32 *)0x10400494 = (u32)fbs[0].top_right;
    *(vu32 *)0x10400498 = (u32)fbs[1].top_right;
    *(vu32 *)0x10400490 = 0x000002D0;
    *(vu32 *)0x1040049C = 0x00000000;

    for(u32 i = 0; i < 256; i++)
        *(vu32 *)0x10400484 = 0x10101 * i;

    *(vu32 *)0x10400500 = 0x000001c2;
    *(vu32 *)0x10400504 = 0x000000d1;
    *(vu32 *)0x10400508 = 0x000001c1;
    *(vu32 *)0x1040050c = 0x000001c1;
    *(vu32 *)0x10400510 = 0x000000cd;
    *(vu32 *)0x10400514 = 0x000000cf;
    *(vu32 *)0x10400518 = 0x000000d1;
    *(vu32 *)0x1040051c = 0x01c501c1;
    *(vu32 *)0x10400520 = 0x00010000;
    *(vu32 *)0x10400524 = 0x0000019d;
    *(vu32 *)0x10400528 = 0x00000052;
    *(vu32 *)0x1040052c = 0x00000192;
    *(vu32 *)0x10400530 = 0x00000192;
    *(vu32 *)0x10400534 = 0x0000004f;
    *(vu32 *)0x10400538 = 0x00000050;
    *(vu32 *)0x1040053c = 0x00000052;
    *(vu32 *)0x10400540 = 0x01980194;
    *(vu32 *)0x10400544 = 0x00000000;
    *(vu32 *)0x10400548 = 0x00000011;
    *(vu32 *)0x1040055C = 0x00f00140;
    *(vu32 *)0x10400560 = 0x01c100d1;
    *(vu32 *)0x10400564 = 0x01920052;
    *(vu32 *)0x10400568 = (u32)fbs[0].bottom;
    *(vu32 *)0x1040056C = (u32)fbs[1].bottom;
    *(vu32 *)0x10400570 = 0x80301;
    *(vu32 *)0x10400574 = 0x00010501;
    *(vu32 *)0x10400578 = 0;
    *(vu32 *)0x10400590 = 0x000002D0;
    *(vu32 *)0x1040059C = 0x00000000;

    for(u32 i = 0; i < 256; i++)
        *(vu32 *)0x10400584 = 0x10101 * i;

    *(vu32 *)0x10202204 = 0x00000000;
    *(vu32 *)0x10202A04 = 0x00000000;
}

static void setupFramebuffers(struct fb *fbs)
{
    *(vu32 *)0x10202204 = 0x01000000;
    *(vu32 *)0x10202A04 = 0x01000000;

    *(vu32 *)0x10400468 = (u32)fbs[0].top_left;
    *(vu32 *)0x1040046c = (u32)fbs[1].top_left;
    *(vu32 *)0x10400494 = (u32)fbs[0].top_right;
    *(vu32 *)0x10400498 = (u32)fbs[1].top_right;
    *(vu32 *)0x10400568 = (u32)fbs[0].bottom;
    *(vu32 *)0x1040056c = (u32)fbs[1].bottom;

    *(vu32 *)0x10400470 = 0x80341;
    *(vu32 *)0x10400478 = 0;
    *(vu32 *)0x10400490 = 0x2D0;
    *(vu32 *)0x10400570 = 0x80301;
    *(vu32 *)0x10400578 = 0;
    *(vu32 *)0x10400590 = 0x2D0;

    *(vu32 *)0x10202204 = 0x00000000;
    *(vu32 *)0x10202A04 = 0x00000000;
}

static void clearScreens(struct fb *fb)
{

    vu32 *REGs_PSC0 = (vu32 *)0x10400010,
         *REGs_PSC1 = (vu32 *)0x10400020;

    REGs_PSC0[0] = (u32)fb->top_left >> 3;
    REGs_PSC0[1] = (u32)(fb->top_left + SCREEN_TOP_FBSIZE) >> 3; //End address
    REGs_PSC0[2] = 0;
    REGs_PSC0[3] = (2 << 8) | 1;

    REGs_PSC1[0] = (u32)fb->bottom >> 3;
    REGs_PSC1[1] = (u32)(fb->bottom + SCREEN_BOTTOM_FBSIZE) >> 3;
    REGs_PSC1[2] = 0;
    REGs_PSC1[3] = (2 << 8) | 1;

    while(!((REGs_PSC0[3] & 2) && (REGs_PSC1[3] & 2)));
}

static void swapFramebuffers(bool isAlternate)
{
    u32 isAlternateTmp = isAlternate ? 1 : 0;
    *(vu32 *)0x10400478 = (*(vu32 *)0x10400478 & 0xFFFFFFFE) | isAlternateTmp;
    *(vu32 *)0x10400578 = (*(vu32 *)0x10400578 & 0xFFFFFFFE) | isAlternateTmp;
}

static void updateBrightness(u32 brightnessLevel)
{
    *(vu32 *)0x10202240 = brightnessLevel;
    *(vu32 *)0x10202A40 = brightnessLevel;
}

static void deinitScreens(void)
{
    *(vu32 *)0x10202A44 = 0;
    *(vu32 *)0x10202244 = 0;
    *(vu32 *)0x10202014 = 0;
}

void main(void)
{
    operation = ARM11_READY;

    while(true)
    {
        switch(operation)
        {
            case ARM11_READY:
                continue;
            case INIT_SCREENS:
                initScreens(*(vu32 *)ARM11_PARAMETERS_ADDRESS, (struct fb *)(ARM11_PARAMETERS_ADDRESS + 4));
                break;
            case SETUP_FRAMEBUFFERS:
                setupFramebuffers((struct fb *)ARM11_PARAMETERS_ADDRESS);
                break;
            case CLEAR_SCREENS:
                clearScreens((struct fb *)ARM11_PARAMETERS_ADDRESS);
                break;
            case SWAP_FRAMEBUFFERS:
                swapFramebuffers(*(volatile bool *)ARM11_PARAMETERS_ADDRESS);
                break;
            case UPDATE_BRIGHTNESS:
                updateBrightness(*(vu32 *)ARM11_PARAMETERS_ADDRESS);
                break;
            case DEINIT_SCREENS:
                deinitScreens();
                break;
            case PREPARE_ARM11_FOR_FIRMLAUNCH:
                memcpy((void *)0x1FFFFC00, (void *)prepareForFirmlaunch, prepareForFirmlaunchSize);
                *(vu32 *)0x1FFFFFFC = 0;
                ((void (*)(u32, volatile Arm11Operation *))0x1FFFFC00)(ARM11_READY, &operation);
        }

        operation = ARM11_READY;
    }
}
