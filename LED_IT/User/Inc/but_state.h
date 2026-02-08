#ifndef _BUT_STATE
#define _BUT_STATE

#include "main.h"
#define DEBOUNCE_TIME 100;

typedef enum 
{
  RELEASED,
  PRESSED,
  WAIT_RELEASED
}but_user_state;

void EXTI0_IRQHandler (void);
void debouncing (void);

#endif