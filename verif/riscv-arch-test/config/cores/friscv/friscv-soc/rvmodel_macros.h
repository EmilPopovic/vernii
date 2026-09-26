// Copyright 2026 FER, HPC Architecture and Application Research Center
// SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
//
// Emil Popovic <mail@emilpopovic.me>
// Matej Jurasic <matej.jurasic@cappig.dev>

#ifndef _RVMODEL_SOC_MACROS_H
#define _RVMODEL_SOC_MACROS_H

#define FRISCV_GPIO_ADDR  0x03000000
#define FRISCV_HALT_ADDR  0x50000000
#define FRISCV_PASS_VALUE 0xAABBCCDD
#define FRISCV_FAIL_VALUE 0x0BADC0DE

#define RVMODEL_DATA_SECTION

#define RVMODEL_BOOT

#define RVMODEL_HALT_PASS     \
    li t0, FRISCV_GPIO_ADDR;  \
    li t1, FRISCV_PASS_VALUE; \
    sw t1, 0(t0);             \
    li t0, FRISCV_HALT_ADDR;  \
    sw zero, 0(t0);           \
1:  j 1b;

#define RVMODEL_HALT_FAIL     \
    li t0, FRISCV_GPIO_ADDR;  \
    li t1, FRISCV_FAIL_VALUE; \
    sw t1, 0(t0);             \
    li t0, FRISCV_HALT_ADDR;  \
    sw zero, 0(t0);           \
1:  j 1b;

#define RVMODEL_IO_INIT(_R1, _R2, _R3)
#define RVMODEL_IO_WRITE_STR(_R1, _R2, _R3, _STR_PTR)

#define RVMODEL_ACCESS_FAULT_ADDRESS 0x00000000

#define RVMODEL_INTERRUPT_LATENCY 10
#define RVMODEL_TIMER_INT_SOON_DELAY 100
#define RVMODEL_MTIME_ADDRESS    0x0200BFF8
#define RVMODEL_MTIMECMP_ADDRESS 0x02004000

#define RVMODEL_SET_MEXT_INT(_R1, _R2)
#define RVMODEL_CLR_MEXT_INT(_R1, _R2)

#define RVMODEL_SET_MSW_INT(_R1, _R2) \
    li _R1, 1;                        \
    li _R2, 0x02000000;               \
    sw _R1, 0(_R2);

#define RVMODEL_CLR_MSW_INT(_R1, _R2) \
    li _R2, 0x02000000;               \
    sw zero, 0(_R2);

#define RVMODEL_SET_SEXT_INT(_R1, _R2)
#define RVMODEL_CLR_SEXT_INT(_R1, _R2)

#define RVMODEL_SET_SSW_INT(_R1, _R2) \
    li _R1, 0x2;                      \
    csrs sip, _R1;

#define RVMODEL_CLR_SSW_INT(_R1, _R2) \
    li _R1, 0x2;                      \
    csrc sip, _R1;

#endif
