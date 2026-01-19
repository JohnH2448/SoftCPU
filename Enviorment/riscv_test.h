// See LICENSE for license details.

#ifndef _ENV_PHYSICAL_SINGLE_CORE_H
#define _ENV_PHYSICAL_SINGLE_CORE_H

#include "../encoding.h"

//-----------------------------------------------------------------------
// Begin Macro
//-----------------------------------------------------------------------

#define RVTEST_RV64U                                                    \
  .macro init;                                                          \
  .endm

#define RVTEST_RV64UF                                                   \
  .macro init;                                                          \
  RVTEST_FP_ENABLE;                                                     \
  .endm

#define RVTEST_RV64UV                                                   \
  .macro init;                                                          \
  RVTEST_VECTOR_ENABLE;                                                 \
  .endm

#define RVTEST_RV64UVX                                                  \
  .macro init;                                                          \
  RVTEST_ZVE32X_ENABLE;                                                 \
  .endm

#define RVTEST_RV32U                                                    \
  .macro init;                                                          \
  .endm

#define RVTEST_RV32UF                                                   \
  .macro init;                                                          \
  RVTEST_FP_ENABLE;                                                     \
  .endm

#define RVTEST_RV32UV                                                   \
  .macro init;                                                          \
  RVTEST_VECTOR_ENABLE;                                                 \
  .endm

#define RVTEST_RV32UVX                                                  \
  .macro init;                                                          \
  RVTEST_ZVE32X_ENABLE;                                                 \
  .endm

#define RVTEST_RV64M                                                    \
  .macro init;                                                          \
  RVTEST_ENABLE_MACHINE;                                                \
  .endm

#define RVTEST_RV64S                                                    \
  .macro init;                                                          \
  RVTEST_ENABLE_SUPERVISOR;                                             \
  .endm

#define RVTEST_RV32M                                                    \
  .macro init;                                                          \
  RVTEST_ENABLE_MACHINE;                                                \
  .endm

#define RVTEST_RV32S                                                    \
  .macro init;                                                          \
  RVTEST_ENABLE_SUPERVISOR;                                             \
  .endm

#if __riscv_xlen == 64
# define CHECK_XLEN li a0, 1; slli a0, a0, 31; bgez a0, 1f; RVTEST_PASS; 1:
#else
# define CHECK_XLEN li a0, 1; slli a0, a0, 31; bltz a0, 1f; RVTEST_PASS; 1:
#endif

#define INIT_XREG                                                       \
  li x1, 0;                                                             \
  li x2, 0;                                                             \
  li x3, 0;                                                             \
  li x4, 0;                                                             \
  li x5, 0;                                                             \
  li x6, 0;                                                             \
  li x7, 0;                                                             \
  li x8, 0;                                                             \
  li x9, 0;                                                             \
  li x10, 0;                                                            \
  li x11, 0;                                                            \
  li x12, 0;                                                            \
  li x13, 0;                                                            \
  li x14, 0;                                                            \
  li x15, 0;                                                            \
  li x16, 0;                                                            \
  li x17, 0;                                                            \
  li x18, 0;                                                            \
  li x19, 0;                                                            \
  li x20, 0;                                                            \
  li x21, 0;                                                            \
  li x22, 0;                                                            \
  li x23, 0;                                                            \
  li x24, 0;                                                            \
  li x25, 0;                                                            \
  li x26, 0;                                                            \
  li x27, 0;                                                            \
  li x28, 0;                                                            \
  li x29, 0;                                                            \
  li x30, 0;                                                            \
  li x31, 0;

/* --- Unsupported on your core: PMP. Make it a no-op. --- */
#define INIT_PMP   /* no PMP */
#define INIT_RNMI  /* no RNMI */
#define INIT_SATP  /* no VM */


/* --- Delegation CSRs unsupported. Keep the useful part: interrupts off. --- */
#define DELEGATE_NO_TRAPS                                               \
  csrwi mie, 0;                                                         \
  .align 2;                                                             \
1:

/* --- No S-mode. Don’t touch mideleg or MPP for supervisor. --- */
#define RVTEST_ENABLE_SUPERVISOR                                        \
  /* no supervisor mode on this core */

/* --- Already machine-only; optionally force MPP=M, but you don’t need to. --- */
/* If you want *zero* extra CSR touching, keep this a no-op. */
#define RVTEST_ENABLE_MACHINE                                           \
  /* machine-only core; no-op */

/* --- No F extension. Don’t touch FS/fcsr. --- */
#define RVTEST_FP_ENABLE                                                \
  /* no floating point on this core */

/* --- No vector extension. Don’t touch VS/vcsr/fcsr. --- */
#define RVTEST_VECTOR_ENABLE                                            \
  /* no vector on this core */

#define RVTEST_ZVE32X_ENABLE                                            \
  /* no Zve32x on this core */

/* --- Single-hart core; avoid mhartid dependency. --- */
#define RISCV_MULTICORE_DISABLE                                         \
  /* single hart; no-op */

/* Keep these as-is */
#define EXTRA_TVEC_USER
#define EXTRA_TVEC_MACHINE
#define EXTRA_INIT
#define EXTRA_INIT_TIMER
#define FILTER_TRAP
#define FILTER_PAGE_FAULT

#define INTERRUPT_HANDLER j other_exception /* No interrupts should occur */

#define RVTEST_CODE_BEGIN                                               \
        .section .text.init;                                            \
        .align  6;                                                      \
        .globl _start;                                                  \
_start:                                                                 \
        j reset_vector;                                                 \
        .align 2;                                                       \
trap_vector:                                                            \
        csrr t5, mcause;                                                \
        li   t6, CAUSE_MACHINE_ECALL;                                   \
        beq  t5, t6, rvtest_pass_trap;                                  \
rvtest_fail_trap:                                                       \
        li   x5, 0x00000bad;                                            \
        mv   x6, TESTNUM;                                               \
rvtest_hang_fail:                                                       \
        j    rvtest_hang_fail;                                          \
rvtest_pass_trap:                                                       \
        li   x5, 0x0000600d;                                            \
        mv   x6, TESTNUM;                                               \
rvtest_hang_pass:                                                       \
        j    rvtest_hang_pass;                                          \
reset_vector:                                                           \
        INIT_XREG;                                                      \
        RISCV_MULTICORE_DISABLE;                                        \
        INIT_RNMI;                                                      \
        INIT_SATP;                                                      \
        INIT_PMP;                                                       \
        DELEGATE_NO_TRAPS;                                              \
        li   TESTNUM, 0;                                                \
        la   t0, trap_vector;                                           \
        csrw mtvec, t0;                                                 \
        addi x0, x0, 0;                                                 \
        addi x0, x0, 0;                                                 \
        addi x0, x0, 0;                                                 \
        addi x0, x0, 0;                                                 \
        CHECK_XLEN;                                                     \
        csrwi mstatus, 0;                                               \
        init;                                                           \
        EXTRA_INIT;                                                     \
        EXTRA_INIT_TIMER;                                               \
        la   t0, 1f;                                                    \
        csrw mepc, t0;                                                  \
        mret;                                                           \
1:

//-----------------------------------------------------------------------
// End Macro
//-----------------------------------------------------------------------

#define RVTEST_CODE_END                                                 \
        unimp

//-----------------------------------------------------------------------
// Pass/Fail Macro
//-----------------------------------------------------------------------

#define RVTEST_PASS                                                     \
        fence;                                                          \
        li TESTNUM, 1;                                                  \
        li a7, 93;                                                      \
        li a0, 0;                                                       \
        ecall

#define TESTNUM gp
#define RVTEST_FAIL                                                     \
        fence;                                                          \
1:      beqz TESTNUM, 1b;                                               \
        sll TESTNUM, TESTNUM, 1;                                        \
        or TESTNUM, TESTNUM, 1;                                         \
        li a7, 93;                                                      \
        addi a0, TESTNUM, 0;                                            \
        ecall

//-----------------------------------------------------------------------
// Data Section Macro
//-----------------------------------------------------------------------

#define EXTRA_DATA

#define RVTEST_DATA_BEGIN                                               \
        EXTRA_DATA                                                      \
        .pushsection .tohost,"aw",@progbits;                            \
        .align 6; .global tohost; tohost: .dword 0; .size tohost, 8;    \
        .align 6; .global fromhost; fromhost: .dword 0; .size fromhost, 8;\
        .popsection;                                                    \
        .align 4; .global begin_signature; begin_signature:

#define RVTEST_DATA_END .align 4; .global end_signature; end_signature:

#endif
