.section .text.start, "ax", %progbits
.align 4
.global _start
.type   _start, %function
_start:
b start

.global operation
operation:
    .word 0

start:
    cpsid aif, #0x13
    ldr r0, =0x54078
    mcr p15, 0, r0, c1, c0, 0

    mov r0, #0xF
    mcr p15, 0, r0, c1, c0, 1
    mov r0, #0
    mcr p15, 0, r0, c7, c5, 4
    mcr p15, 0, r0, c7, c7, 0
    mcr p15, 0, r0, c7, c10, 4

    ldr sp, =__stack_top__
    mov fp, #0

    ldr r0, =__bss_start__
    mov r1, #0
    ldr r2, =__bss_end__
    sub r2, r0
    bl memset

    bl __libc_init_array

    b main

.global prepareForFirmlaunch
.type   prepareForFirmlaunch, %function
prepareForFirmlaunch:
    str r0, [r1]
    mov r0, #0x20000000

    _wait_for_core0_entrypoint_loop:
        ldr r1, [r0, #-4]
        cmp r1, #0
        beq _wait_for_core0_entrypoint_loop

    bx r1
prepareForFirmlaunchEnd:

.global prepareForFirmlaunchSize
prepareForFirmlaunchSize: .word prepareForFirmlaunchEnd - prepareForFirmlaunch
