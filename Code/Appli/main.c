/******************************************************************************************
  Filename    : main.c
  
  Core        : RV32IMAFCB (SiFive E24 RISC-V)
  
  MCU         : BL602
    
  Author      : Chalandi Amine
 
  Owner       : Chalandi Amine
  
  Date        : 21.10.2025
  
  Description : Application main function
  
******************************************************************************************/

//-----------------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------------
#include <stdint.h> 
#include "BL602.h"
#include "riscv-csr.h"
#include "printf.h"

//-----------------------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------------------
#define TIMEOUT_500MS  (uint64_t)5000000

//-----------------------------------------------------------------------------------------
// Macros
//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
// Globals
//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
// Function Prototypes
//-----------------------------------------------------------------------------------------
void __attribute__((interrupt)) Isr_TIMER_Interrupt (void);

//-----------------------------------------------------------------------------------------
/// \brief  
///
/// \param  
///
/// \return 
//-----------------------------------------------------------------------------------------
void main(void)
{
  /* configure IO3 as output */
  glb->GPIO_CFGCTL1.bit.reg_gpio_3_func_sel = GPIO_FUN_SWGPIO;
  glb->GPIO_CFGCTL1.bit.reg_gpio_3_ie       = 0ul;
  glb->GPIO_CFGCTL1.bit.reg_gpio_3_drv      = 0ul;
  glb->GPIO_CFGCTL1.bit.reg_gpio_3_smt      = 0ul;
  glb->GPIO_CFGCTL34.bit.reg_gpio_3_oe      = 1ul;

  /* enabled selective hardware vectoring */
  CLIC_CFG |= 1ul;

  /* enable timer interrupt in CLIC vectored mode */
  CLIC_INTIE[7] = 1u;

  /* set the timeout to 500ms */
  CLIC_MTIMECMP = (uint64_t)(CLIC_MTIME + TIMEOUT_500MS);

  /* configure gpio function for uart tx and rx */
  glb->GPIO_CFGCTL8.bit.reg_gpio_16_func_sel = GPIO_FUN_UART;
  glb->GPIO_CFGCTL3.bit.reg_gpio_7_func_sel  = GPIO_FUN_UART;

  /* select uart function for each gpio pin */
  glb->UART_SIG_SEL_0.bit.uart_sig_0_sel=2u; /* gpio_16(SIG0) --> UART0_TXD (2) */
  glb->UART_SIG_SEL_0.bit.uart_sig_7_sel=3u; /* gpio_7(SIG7)  --> UART0_RXD (3) */

  /* set the uart clock freq to 160MHz */
  HBN->HBN_GLB.bit.hbn_uart_clk_sel = 1u;

  /* set uart baudrate to 115200 kbps */
  uart->uart_bit_prd.bit.cr_utx_bit_prd = 1389;
  uart->uart_bit_prd.bit.cr_urx_bit_prd = 1389;

  /* enable uart tx */
  uart->utx_config.bit.cr_utx_frm_en = 1u;
  uart->utx_config.bit.cr_utx_len = 1u;
  uart->utx_config.bit.cr_utx_en = 1u;

  /* output a text message on the uart console */
  printf("BareMetal BL602 SW is Alive!\n\r");

  /* endless loop */
  while(1);
}

//-----------------------------------------------------------------------------------------
/// \brief  
///
/// \param  
///
/// \return 
//-----------------------------------------------------------------------------------------
void Isr_TIMER_Interrupt (void)
{
  /* toggle the IO3 pin */
  glb->GPIO_CFGCTL32.bit.reg_gpio_3_o ^= 1ul;

  /* set the timeout to 500ms */
  CLIC_MTIMECMP = (uint64_t)(CLIC_MTIME + TIMEOUT_500MS);
}
