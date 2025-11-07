
// **********************************************************************************************************************
//                                                  OSEK OS Configuration
// **********************************************************************************************************************

// **********************************************************************************************************************
// Filename        : OsTcb.h
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

#ifndef __OS_TCB_H__
#define __OS_TCB_H__

#include "OsTypes.h"

typedef enum {
    T1,
    T2,
    OS_INVALID_TASK,
    OS_NUMBER_OF_TASKS = OS_INVALID_TASK,
}OsTaskId_t;

#define OS_NUMBER_OF_TASKS_ON_CORE0 2


typedef enum {
    ALARM_TOGGLE_LED,
    ALARM_TOGGLE_LED_WINDOW,
    OS_INVALID_ALARM,
    OS_NUMBER_OF_ALARMS = OS_INVALID_ALARM
}OsAlarmId_t;

typedef enum {
    RES_SCHEDULER_CORE0,
    OS_INVALID_RESOURCE,
    OS_NUMBER_OF_RESOURCES = OS_INVALID_RESOURCE
}OsResourceId_t;

#define RES_SCHEDULER osResSchedulerMappingPerCore[osGetLogicalCoreId(osGetCoreId())]

typedef enum {
    OS_INVALID_SPINLOCK,
    OS_NUMBER_OF_SPINLOCKS = OS_INVALID_SPINLOCK
}OsSpinlockId_t;

/* task function prototype */
TASK(T1);
TASK(T2);

/* IPCs */

/* hooks function */




/* event mask definition */
#define EVT_TOGGLE_LED    0x1
#define EVT_TOGGLE_LED_CYCLE    0x1

/* wait event mask for each task */
#define T1_WAIT_EVENT_MASK    0x1
#define T2_WAIT_EVENT_MASK    0x1

#define OS_NUMBER_OF_CORES    1UL

extern const OsIntIsrLtType OsIsrLookupTable_core0[69];
extern const osObjectCoreAsgn_t osTaskCoreAsgnLookupTable[2];
extern const osObjectCoreAsgn_t osAlarmCoreAsgnLookupTable[2];
extern const osObjectCoreAsgn_t osResourceCoreAsgnLookupTable[1];
extern const uint8_t osLogicalToPhysicalCoreIdMapping[1];

extern volatile Ocb_t* OCB_Cfg[1];

/* ISR functions prototypes */
ISR(SysTickTimer);
void osDispatchHandler(void);
ISR(Undefined);

#define OS_SYSTICK_FREQ_MHZ               10ULL
#define OS_SYSTICK_RELOAD_VALUE           0x270f

#endif /* __OS_TCB_H__ */
