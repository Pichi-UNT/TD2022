#include "lcd.h"

#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif

#define TECLA_F1  1
#define TECLA_F2  2
#define TECLA_F3  3
#define TECLA_F4  4
#define TECLA_SI  5
#define TECLA_NO  6

#define SCU_MODE_SAL (SCU_MODE_INACT | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS)
#define SCU_MODE_ENT (SCU_MODE_PULLUP | SCU_MODE_INBUFF_EN)
#define SW_GPIO_PORT    5
#define SW1_GPIO_PIN    15
#define SW1_GPIO_MASK   (1UL << SW1_GPIO_PIN)
#define SW2_GPIO_PIN    14
#define SW2_GPIO_MASK   (1UL << SW2_GPIO_PIN)
#define SW3_GPIO_PIN    13
#define SW3_GPIO_MASK   (1UL << SW3_GPIO_PIN)
#define SW4_GPIO_PIN    12
#define SW4_GPIO_MASK   (1UL << SW4_GPIO_PIN)
#define FUN_GPIO_MASK   (SW1_GPIO_MASK | SW2_GPIO_MASK | SW3_GPIO_MASK | SW4_GPIO_MASK)

#define SW5_GPIO_PIN    8
#define SW5_GPIO_MASK   (1UL << SW5_GPIO_PIN)
#define SW6_GPIO_PIN    9
#define SW6_GPIO_MASK   (1UL << SW6_GPIO_PIN)
#define SW_GPIO_MASK    (FUN_GPIO_MASK | SW5_GPIO_MASK | SW6_GPIO_MASK)



void ConfigurarPuertosPoncho(void);

void ConfigurarInterrupcion(void);