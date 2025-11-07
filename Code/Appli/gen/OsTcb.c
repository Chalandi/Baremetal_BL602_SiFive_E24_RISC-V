
// **********************************************************************************************************************
//                                                  OSEK OS Configuration
// **********************************************************************************************************************

// **********************************************************************************************************************
// Filename        : OsTcb.c
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

#include "OsTcb.h"

//=============================================================================
// OS Configuration Summary
//=============================================================================
/*
  OS:
  ╒════════╤═════════════════════════════════════════════════════════════╕
  │ Name   │ Properties                                                  │
  ╞════════╪═════════════════════════════════════════════════════════════╡
  │ MyOSEK │ OsMulticore        =  FLASE                                 │
  │        │                              OsStartupHook      =  FLASE    │
  │        │                              OsErrorHook        =  FLASE    │
  │        │                              OsShutdownHook     =  FLASE    │
  │        │                              OsPreTaskHook      =  FLASE    │
  │        │                              OsPostTaskHook     =  FLASE    │
  │        │                              OsStackCheck       =  TRUE     │
  │        │                              OsClockFrequency   =  10       │
  │        │                              OsMaxVectorEntries =  69       │
  │        │                              OsTickTime         =  1000     │
  │        │                              OsInterruptNestingMaxDepth = 8 │
  │        │                              OsStackAlignment   =  4        │
  ╘════════╧═════════════════════════════════════════════════════════════╛

  Tasks:
  ╒════════╤════════╤════════════╤════════════╤══════════════╤═════════════╤══════════════╤═══════════════════╤═══════════════╕
  │ Task   │ Type   │ Schedule   │   Priority │   Activation │ Autostart   │ Stack size   │   Wait event mask │   Pinned core │
  ╞════════╪════════╪════════════╪════════════╪══════════════╪═════════════╪══════════════╪═══════════════════╪═══════════════╡
  │ T1     │ AUTO   │ FULL       │          2 │            1 │ TRUE        │ 0x400        │                 1 │             0 │
  ├────────┼────────┼────────────┼────────────┼──────────────┼─────────────┼──────────────┼───────────────────┼───────────────┤
  │ T2     │ AUTO   │ FULL       │          5 │            1 │ TRUE        │ 0x400        │                 1 │             0 │
  ╘════════╧════════╧════════════╧════════════╧══════════════╧═════════════╧══════════════╧═══════════════════╧═══════════════╛
  Total number of tasks: 2

  Task's events: 
  ╒════════╤══════════════════════╕
  │ Task   │ Events               │
  ╞════════╪══════════════════════╡
  │ T1     │ EVT_TOGGLE_LED       │
  ├────────┼──────────────────────┤
  │ T2     │ EVT_TOGGLE_LED_CYCLE │
  ╘════════╧══════════════════════╛

  Task's resources: 
  ╒════════╤═════════════╕
  │ Task   │ Resources   │
  ╞════════╪═════════════╡
  │ T1     │             │
  ├────────┼─────────────┤
  │ T2     │             │
  ╘════════╧═════════════╛

  Events:
  ╒══════════════════════╤════════╕
  │ EVENT                │ MASK   │
  ╞══════════════════════╪════════╡
  │ EVT_TOGGLE_LED       │ 0x1    │
  ├──────────────────────┼────────┤
  │ EVT_TOGGLE_LED_CYCLE │ 0x1    │
  ╘══════════════════════╧════════╛
  Total number of events: 2

  Resources:
  ╒═════════════════════╤════════════════════╤════════════╤════════╤═══════════════╕
  │ Resource            │   Priority ceiling │ Property   │   Mask │   Pinned core │
  ╞═════════════════════╪════════════════════╪════════════╪════════╪═══════════════╡
  │ RES_SCHEDULER_CORE0 │                  2 │ STANDARD   │      3 │             0 │
  ╘═════════════════════╧════════════════════╧════════════╧════════╧═══════════════╛
  Total number of resources: 1

  Priority Scheme on core0:
  ╒═════════════════════╤════════════╕
  │ Name                │   Priority │
  ╞═════════════════════╪════════════╡
  │ T1                  │          0 │
  ├─────────────────────┼────────────┤
  │ T2                  │          1 │
  ├─────────────────────┼────────────┤
  │ RES_SCHEDULER_CORE0 │          2 │
  ╘═════════════════════╧════════════╛
  Total priority levels on core0: 3

  Alarms:
  ╒═════════════════════════╤═════════════╤═════════════╤══════════════════════╤════════╤══════════╤═════════════╤════════════╤═══════════════╕
  │ Name                    │ Alarmtime   │ Cycletime   │ Event                │ Task   │ Action   │ Autostart   │ Callback   │   Pinned core │
  ╞═════════════════════════╪═════════════╪═════════════╪══════════════════════╪════════╪══════════╪═════════════╪════════════╪═══════════════╡
  │ ALARM_TOGGLE_LED        │ -           │ -           │ EVT_TOGGLE_LED       │ T1     │ SETEVENT │ FALSE       │ -          │             0 │
  ├─────────────────────────┼─────────────┼─────────────┼──────────────────────┼────────┼──────────┼─────────────┼────────────┼───────────────┤
  │ ALARM_TOGGLE_LED_WINDOW │ -           │ -           │ EVT_TOGGLE_LED_CYCLE │ T2     │ SETEVENT │ FALSE       │ -          │             0 │
  ╘═════════════════════════╧═════════════╧═════════════╧══════════════════════╧════════╧══════════╧═════════════╧════════════╧═══════════════╛
  Total number of alarms: 2

  Interrupts on core0:
  ╒═══════════════════╤════════════╤══════════╤════════╤═══════════╕
  │ Name              │   Category │   Vector │   Prio │ Nesting   │
  ╞═══════════════════╪════════════╪══════════╪════════╪═══════════╡
  │ SysTickTimer      │          2 │        7 │      0 │ FALSE     │
  ├───────────────────┼────────────┼──────────┼────────┼───────────┤
  │ osDispatchHandler │          1 │        3 │      0 │ FALSE     │
  ╘═══════════════════╧════════════╧══════════╧════════╧═══════════╛
  Total number of used interrupts: 2
  Total number of CPU interrupts : 69

  IPC :
  ╒════════╤══════════════╤════════════╤═════════╤════════╤════════╕
  │ Name   │ Owner Task   │ Resource   │ Event   │ Mode   │ Size   │
  ╞════════╪══════════════╪════════════╪═════════╪════════╪════════╡
  ╘════════╧══════════════╧════════════╧═════════╧════════╧════════╛
*/

/********************************************************************************************************************/
/* Task: T1 (core0) */
/********************************************************************************************************************/
TASK(T1);
CREATE_STACK(T1, 0x400, 4);
static OsTcbType OsTcb_T1 = {
                                         pTASK(T1), /* Function */
                                         0, /* FixedPrio */
                                         true, /* Autostart */
                                         pTSTACK(T1, 4), /* pstack_top */
                                         pBSTACK(T1), /* pstack_bot */
                                         pTSTACK(T1, 4), /* pCurrentStackPointer */
                                         SUSPENDED, /* TaskStatus */
                                         0, /* Prio */
                                         0, /* CeilingPrio */
                                         0, /* SetEvtMask */
                                         0x1, /* WaitEvtMask */ 
                                         1, /* MaxAllowedMultipleActivation */
                                         0, /* MultipleActivation */
                                         EXTENDED, /* TaskType */
                                         FULL_PREEMPT /* TaskSchedType */
                                       };

/********************************************************************************************************************/
/* Task: T2 (core0) */
/********************************************************************************************************************/
TASK(T2);
CREATE_STACK(T2, 0x400, 4);
static OsTcbType OsTcb_T2 = {
                                         pTASK(T2), /* Function */
                                         1, /* FixedPrio */
                                         true, /* Autostart */
                                         pTSTACK(T2, 4), /* pstack_top */
                                         pBSTACK(T2), /* pstack_bot */
                                         pTSTACK(T2, 4), /* pCurrentStackPointer */
                                         SUSPENDED, /* TaskStatus */
                                         0, /* Prio */
                                         0, /* CeilingPrio */
                                         0, /* SetEvtMask */
                                         0x1, /* WaitEvtMask */ 
                                         1, /* MaxAllowedMultipleActivation */
                                         0, /* MultipleActivation */
                                         EXTENDED, /* TaskType */
                                         FULL_PREEMPT /* TaskSchedType */
                                       };

/********************************************************************************************************************/
/* OsTasksConfig (core0) */
/********************************************************************************************************************/
static const OsTcbType* OsTasksConfig_core0[2] = {
    &OsTcb_T1,
    &OsTcb_T2,
};

/********************************************************************************************************************/
/* osTaskCoreAsgnLookupTable */
/********************************************************************************************************************/
const osObjectCoreAsgn_t osTaskCoreAsgnLookupTable[2] = {
    {.local_id=0, .pinned_core=0}, /* T1 */
    {.local_id=1, .pinned_core=0}, /* T2 */
};

/********************************************************************************************************************/
/* Alarm: ALARM_TOGGLE_LED (core0) */
/********************************************************************************************************************/
static OsAlarmConfigType OsAlarm_ALARM_TOGGLE_LED = {
                                                     0, /* InitTicks */
                                                     0, /* InitCycles */
                                                     EVT_TOGGLE_LED, /* Event */
                                                     T1, /* TaskId */
                                                     ALARM_SET_EVENT, /* Action */
                                                     ALARM_NO_AUTOSTART, /* AutoStart */
                                                     ALARM_FREE, /* Status */
                                                     0, /* Alarmtype */
                                                     0, /* AlarmCategory */
                                                     0, /* AlarmCheckPoint */
                                                     0 /* CallBackFunc */
                                                   };

/********************************************************************************************************************/
/* Alarm: ALARM_TOGGLE_LED_WINDOW (core0) */
/********************************************************************************************************************/
static OsAlarmConfigType OsAlarm_ALARM_TOGGLE_LED_WINDOW = {
                                                     0, /* InitTicks */
                                                     0, /* InitCycles */
                                                     EVT_TOGGLE_LED_CYCLE, /* Event */
                                                     T2, /* TaskId */
                                                     ALARM_SET_EVENT, /* Action */
                                                     ALARM_NO_AUTOSTART, /* AutoStart */
                                                     ALARM_FREE, /* Status */
                                                     0, /* Alarmtype */
                                                     0, /* AlarmCategory */
                                                     0, /* AlarmCheckPoint */
                                                     0 /* CallBackFunc */
                                                   };

/********************************************************************************************************************/
/* OsAlarmsConfig (core0) */
/********************************************************************************************************************/
static const OsAlarmConfigType* OsAlarmsConfig_core0[2] = {
    &OsAlarm_ALARM_TOGGLE_LED,
    &OsAlarm_ALARM_TOGGLE_LED_WINDOW,
};

/********************************************************************************************************************/
/* osAlarmCoreAsgnLookupTable */
/********************************************************************************************************************/
const osObjectCoreAsgn_t osAlarmCoreAsgnLookupTable[2] = {
    {.local_id=0, .pinned_core=0}, /* ALARM_TOGGLE_LED */
    {.local_id=1, .pinned_core=0}, /* ALARM_TOGGLE_LED_WINDOW */
};

/********************************************************************************************************************/
/* Resource: RES_SCHEDULER_CORE0 (core0) */
/********************************************************************************************************************/
static OsResourceConfigType OsResource_RES_SCHEDULER_CORE0 = {
                                                            2, /* ResCeilingPrio */
                                                            0, /* Occupied */
                                                            0, /* CurrentOccupiedTask */
                                                            3 /* AuthorizedTask */
                                                          };

/********************************************************************************************************************/
/* OsResourceConfig (core0) */
/********************************************************************************************************************/
static const OsResourceConfigType* OsResourcesConfig_core0[1] = {
    &OsResource_RES_SCHEDULER_CORE0,
};

/********************************************************************************************************************/
/* OsResSchedulerMappingPerCore */
/********************************************************************************************************************/
static const OsResourceId_t osResSchedulerMappingPerCore[1] __attribute__((used)) = {
    RES_SCHEDULER_CORE0,
};

/********************************************************************************************************************/
/* osResourceCoreAsgnLookupTable */
/********************************************************************************************************************/
const osObjectCoreAsgn_t osResourceCoreAsgnLookupTable[1] = {
    {.local_id=0, .pinned_core=0}, /* RES_SCHEDULER_CORE0 */
};

/********************************************************************************************************************/
/* OsSpinlockConfig */
/********************************************************************************************************************/
static const OsSpinlockConfigType* OsSpinlocksConfig[0] = {
};

/********************************************************************************************************************/
/* Interrupt LUT (Core0) */
/********************************************************************************************************************/
const OsIntIsrLtType OsIsrLookupTable_core0[69] = {
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 0 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 1 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 2 */
    {(pIsrFunc)&osDispatchHandler, (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 1}, /* Interrupt vector 3 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 4 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 5 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 6 */
    {pISR(SysTickTimer), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2}, /* Interrupt vector 7 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 8 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 9 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 10 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 11 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 12 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 13 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 14 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 15 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 16 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 17 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 18 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 19 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 20 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 21 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 22 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 23 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 24 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 25 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 26 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 27 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 28 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 29 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 30 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 31 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 32 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 33 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 34 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 35 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 36 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 37 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 38 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 39 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 40 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 41 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 42 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 43 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 44 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 45 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 46 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 47 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 48 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 49 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 50 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 51 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 52 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 53 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 54 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 55 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 56 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 57 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 58 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 59 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 60 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 61 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 62 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 63 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 64 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 65 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 66 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 67 */
    {pISR(Undefined), (uint8_t)0, (OsInterruptNestingType)NOT_NESTED, 2},  /* Interrupt vector 68 */
};

/********************************************************************************************************************/
/* OsInterruptsConfig_core0 */
/********************************************************************************************************************/
OsInterruptConfigType OsInterruptsConfig_core0 = {
    69, /* OsNbrOfInterrupts */
    0x0ul, /* OsIntCat1LowestPrioLevel */
    0, /* OsInterruptNestingDepth */
    0, /* OsInterruptSavedPrioLevel */
    0, /* OsInterruptSavedGlobalMask */
    0, /* OsInterruptSuspendOsNestingCall */
    0, /* OsInterruptSuspendAllNestingCall */
    {0}, /* OsIntNestSavedStackPointer[OS_INTERRUPT_NESTING_DEPTH_LEVEL] */
    {0}, /* OsIntNestSavedPrioLevel[OS_INTERRUPT_NESTING_DEPTH_LEVEL] */
    (OsIntIsrLtType*)&OsIsrLookupTable_core0[0] /* OsIsrLookupTablePtr */
};

/********************************************************************************************************************/
/* osLcCfg_core0 */
/********************************************************************************************************************/
static Ocb_t osLcCfg_core0 = {
    (OsTcbType**)&OsTasksConfig_core0[0], /* pTcb */
    (OsAlarmConfigType**)&OsAlarmsConfig_core0[0], /* pAlarm */
    (OsResourceConfigType**)&OsResourcesConfig_core0[0], /* pRes */
    (OsSpinlockConfigType**)&OsSpinlocksConfig[0], /* pSpinlock */
    (OsInterruptConfigType*)&OsInterruptsConfig_core0, /* pInt */
    0, /* OsIsRunning */
    0, /* OsHighPrioReadyTaskId */
    OS_NUMBER_OF_TASKS_ON_CORE0, /* OsCurrentTaskId */
    0, /* OsSysTickCounter */
    0, /* OsIntCallDispatcher */
    0, /* OsLockDispatcher */
    0, /* OsCat2InterruptLevel */
    0, /* OsCurrentSystemStackPtr */
    {0}, /* OsCrossCoreBuffer[10] */
    0, /* OsCrossCoreBufferLock */
    0, /* OsCrossCoreBufferSyncFlag */
    {0}, /* OsHwSchedPrioReg */
    0, /* OsSpinlockNestingDepth */
    2, /* OsNumberOfTasks */
    2, /* OsNumberOfAlarms */
    1,  /* OsNumberOfResources */
    0, /* OsStartupHook */
    0, /* OsPreTaskHook */
    0, /* OsPostTaskHook */
    0, /* OsShutdownHook */
    0 /* OsErrorHook */
};

/********************************************************************************************************************/
/* OCB Configuration */
/********************************************************************************************************************/
volatile Ocb_t* OCB_Cfg[1] = {
    (Ocb_t*)&osLcCfg_core0,
};

/********************************************************************************************************************/
/* logical to physical core id mapping*/
/********************************************************************************************************************/
const uint8_t osLogicalToPhysicalCoreIdMapping[1] = {
    0, /* SiFive_E24_0 : SiFive - E24 */
};


