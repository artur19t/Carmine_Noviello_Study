#include "hw_init.h"

void GPIO_LED_UsrInit(void)
{
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);

    LL_GPIO_InitTypeDef GPIO_UsrStruct = {0};
    GPIO_UsrStruct.Mode = LL_GPIO_MODE_OUTPUT;
    GPIO_UsrStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_UsrStruct.Pin = LL_GPIO_PIN_13;
    GPIO_UsrStruct.Pull = LL_GPIO_PULL_NO;
    GPIO_UsrStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
    LL_GPIO_Init(GPIOC, &GPIO_UsrStruct);

    LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_13);
}

void GPIO_But_UsrInit(void)
{
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);

  LL_GPIO_InitTypeDef GPIO_UsrStruct = {0};
  GPIO_UsrStruct.Mode = LL_GPIO_MODE_INPUT;
  GPIO_UsrStruct.Pin = LL_GPIO_PIN_0;
  GPIO_UsrStruct.Pull = LL_GPIO_PULL_UP;
  GPIO_UsrStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;

  LL_GPIO_Init(GPIOA, &GPIO_UsrStruct);
}

void IT_But_init(void)
{
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
  
  LL_EXTI_InitTypeDef IT_UsrInit = {0};
  IT_UsrInit.LineCommand = ENABLE;
  IT_UsrInit.Line_0_31 = LL_EXTI_LINE_0;
  IT_UsrInit.Mode = LL_EXTI_MODE_IT;
  IT_UsrInit.Trigger = LL_EXTI_TRIGGER_FALLING;
  LL_EXTI_Init(&IT_UsrInit);

  LL_SYSCFG_SetEXTISource(LL_SYSCFG_EXTI_PORTA, LL_SYSCFG_EXTI_LINE0);
  
  LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_0);
  NVIC_SetPriority(EXTI0_IRQn, 0);
  NVIC_EnableIRQ(EXTI0_IRQn);
}

void SysTick_Init(void)
{
  SysTick->LOAD = (SystemCoreClock/1000) - 1;
  SysTick->VAL = 0;
  SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk |SysTick_CTRL_ENABLE_Msk;
}