
// **********************************************************************************************************************
//                                                  OSEK OS Configuration
// **********************************************************************************************************************

// **********************************************************************************************************************
// Filename        : OsGenPrioTypes.h
//
// Author          : Amine Chalandi
//
// Owner           : Amine Chalandi
//
// Generator       : OilGenTool
//
// Oil file        : D:/Git_Repo/Baremetal_BL602_SiFive_E24_RISC-V/Build/../Code/Appli/osek_bl602_risc-v.oil
//
// Generation Time : 07.11.2025 12:13:18
//
// Description     : Auto-generated OS Configuration file
//
// **********************************************************************************************************************

#ifndef _OSPRIOTYPES_H_
#define _OSPRIOTYPES_H_

#include "stdint.h"

typedef struct
{
  uint32_t OsGroupPrioLevel0; /* PRIORITY 0 --> 31 */
}OsSchedPrioType;

#define OS_INTERRUPT_NESTING_DEPTH_LEVEL  8

#endif /* _OSPRIOTYPES_H_ */
