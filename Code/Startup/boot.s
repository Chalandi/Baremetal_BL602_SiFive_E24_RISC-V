/******************************************************************************************
  Filename    : boot.s
  
  Core        : RV32IMAFCB (SiFive E24 RISC-V)
  
  MCU         : BL602
    
  Author      : Chalandi Amine
 
  Owner       : Chalandi Amine
  
  Date        : 22.10.2025
  
  Description : boot routine

******************************************************************************************/

/*******************************************************************************************
  \brief  
  
  \param  
  
  \return 
********************************************************************************************/
.section .boot
.type _start, @function
.align 2
.globl _start

_start:
        /* note: The system clock is set to 160MHz by the BL602's bootROM 
                 RISC-V mtime clock (rtc_toggle signal) is set to 10MHz
        */

        /* setup the exception vector table (CLIC vectored) */
        la t0, ExceptionVectorTable
        addi t0, t0, 3
        csrw mtvec, t0

        /* setup the interrupt vector table (CLIC vectored) */
        la t0, InterruptVectorTable
        csrw mtvt, t0

        /* enable global interrupt flag */
        csrsi mstatus, (1ul << 3)

        /* setup the stack pointer */
        la sp, __STACK_TOP

        /* setup the C/C++ runtime environment */
        j Startup_Init


.size _start, .-_start

/*******************************************************************************************
  \brief  
  
  \param  
  
  \return 
********************************************************************************************/
.section .text.vivt
.type ExceptionVectorTable, @function
.align 6
.globl ExceptionVectorTable

ExceptionVectorTable:
                      j .

.size ExceptionVectorTable, .-ExceptionVectorTable

/*
-----------------------------------------------------------------
 Register | ABI Name | Description                      | Saver
-----------------------------------------------------------------
 x0       | zero     | Hard-wired zero                  | -
 x1       | ra       | Return address                   | Caller
 x2       | sp       | Stack pointer                    | Callee
 x3       | gp       | Global pointer                   | -
 x4       | tp       | Thread pointer                   | -
 x5-7     | t0-2     | Temporaries                      | Caller
 x8       | s0/fp    | Saved register/frame pointer     | Callee
 x9       | s1       | Saved register                   | Callee
 x10-11   | a0-1     | Function arguments/return values | Caller
 x12-17   | a2-7     | Function arguments               | Caller
 x18-27   | s2-11    | Saved registers                  | Callee
 x28-31   | t3-6     | Temporaries                      | Caller
 f0-7     | ft0-7    | FP temporaries                   | Caller
 f8-9     | fs0-1    | FP saved registers               | Callee
 f10-11   | fa0-1    | FP arguments/return values       | Caller
 f12-17   | fa2-7    | FP arguments                     | Caller
 f18-27   | fs2-11   | FP saved registers               | Callee
 f28-31   | ft8-11   | FP temporaries                   | Caller
-----------------------------------------------------------------
*/
