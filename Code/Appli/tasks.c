

/*******************************************************************************************************************
** Includes
*******************************************************************************************************************/
#include"OsTcb.h"
#include"OsAPIs.h"
#include "BL602.h"

#define LED_TOGGLE()   glb->GPIO_CFGCTL32.bit.reg_gpio_3_o ^= 1ul;


//===============================================================================================================================
// OS TASK : T1
//===============================================================================================================================
TASK(T1)
{
  OsEventMaskType OsWaitEventMask = EVT_TOGGLE_LED;
  OsEventMaskType Events = 0;

  /* start the os alarm */
  (void)OS_SetRelAlarm(ALARM_TOGGLE_LED,0,1000);

  for(;;)
  {
    if(E_OK == OS_WaitEvent(OsWaitEventMask))
    {
      (void)OS_GetEvent((OsTaskType)T1, &Events);

      if((Events & EVT_TOGGLE_LED) == EVT_TOGGLE_LED)
      {
        OS_ClearEvent(EVT_TOGGLE_LED);
        LED_TOGGLE();

      }
    }
    else
    {
      OS_TerminateTask();
    }
  }
}

//===============================================================================================================================
// OS TASK : T2
//===============================================================================================================================
TASK(T2)
{
  static uint32_t T2AliveCounter  = 0;
  static uint32_t AlarmCycleValue = 0;
  OsEventMaskType OsWaitEventMask = EVT_TOGGLE_LED_CYCLE;
  OsEventMaskType Events = 0;
  (void)OS_SetRelAlarm(ALARM_TOGGLE_LED_WINDOW, 0, 10000);

  for(;;)
  {
    if(E_OK == OS_WaitEvent(OsWaitEventMask))
    {
      (void)OS_GetEvent((OsTaskType)T2, &Events);

      if((Events & EVT_TOGGLE_LED_CYCLE) == EVT_TOGGLE_LED_CYCLE)
      {
        OS_ClearEvent(EVT_TOGGLE_LED_CYCLE);
        T2AliveCounter++;
        
        if(T2AliveCounter % 2ul == 0ul)
        {
          AlarmCycleValue = 1000;
        }
        else
        {
          AlarmCycleValue = 250;
        }

        /* start the os alarm */
        OS_CancelAlarm(ALARM_TOGGLE_LED);
        OS_SetRelAlarm(ALARM_TOGGLE_LED, 0, AlarmCycleValue);
      }
    }
    else
    {
      OS_TerminateTask();
    }
  }
}

//===============================================================================================================================
// HOOKS
//===============================================================================================================================
#ifdef OS_STARTUPHOOK
void osStartupHook_core0(void){}
#endif

#ifdef OS_PRETASKHOOK
void osPreTaskHook_core0(void){}
#endif

#ifdef OS_POSTTASKHOOK
void osPostTaskHook_core0(void){}
#endif

#ifdef OS_SHUTDOWNHOOK
void osShutdownHook_core0(OsStatusType error){(void)error;}
#endif

#ifdef OS_ERRORHOOK
void osErrorHook_core0(OsStatusType error){(void)error;}
#endif
