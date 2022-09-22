/*
* Woomy
*/

#pragma once

#include "types.h"

void memcpy(void *dest, const void *src, u32 size);
void memset(void *dest, u32 value, u32 size) __attribute__((used));
void memset32(void *dest, u32 filler, u32 size);
