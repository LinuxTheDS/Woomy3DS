/*
*  as different from the original version.
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;

#define SCREEN_TOP_WIDTH     400
#define SCREEN_BOTTOM_WIDTH  320
#define SCREEN_HEIGHT        240
#define SCREEN_TOP_FBSIZE    (3 * SCREEN_TOP_WIDTH * SCREEN_HEIGHT)
#define SCREEN_BOTTOM_FBSIZE (3 * SCREEN_BOTTOM_WIDTH * SCREEN_HEIGHT)
#define ARM11_PARAMETERS_ADDRESS  0x1FFFF000

struct fb {
     u8 *top_left;
     u8 *top_right;
     u8 *bottom;
};

typedef enum
{
    INIT_SCREENS = 0,
    SETUP_FRAMEBUFFERS,
    CLEAR_SCREENS,
    SWAP_FRAMEBUFFERS,
    UPDATE_BRIGHTNESS,
    DEINIT_SCREENS,
    PREPARE_ARM11_FOR_FIRMLAUNCH,
    ARM11_READY,
} Arm11Operation;
