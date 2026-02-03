#include "hw_init.h"

void GPIO_LED_UsrInit(void)
{
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
    LL_GPIO_InitTypeDef GPIO_Init_Struct = {0};
    GPIO_Init_Struct.Mode = LL_GPIO_MODE_OUTPUT;
    GPIO_Init_Struct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_Init_Struct.Pin = LL_GPIO_PIN_13;
    GPIO_Init_Struct.Pull = LL_GPIO_PULL_NO;
    GPIO_Init_Struct.Speed = LL_GPIO_SPEED_FREQ_LOW;
    LL_GPIO_Init(GPIOC, &GPIO_Init_Struct);
  
    LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_13);
}