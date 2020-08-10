#include "configuracion.h"


void ConfigurarPuertosPoncho(void) {

   /* Configuracion Teclas Poncho - Puerto Teclas 1 a 4 */
   Chip_SCU_PinMux(4, 8, SCU_MODE_ENT, SCU_MODE_FUNC4);
   Chip_SCU_PinMux(4, 9, SCU_MODE_ENT, SCU_MODE_FUNC4);
   Chip_SCU_PinMux(4, 10, SCU_MODE_ENT, SCU_MODE_FUNC4);
   Chip_SCU_PinMux(6, 7, SCU_MODE_ENT, SCU_MODE_FUNC4);

   /* Configuracion Teclas Poncho - Puerto Teclas Aceptar y Cancelar */
   Chip_SCU_PinMux(3, 1, SCU_MODE_ENT, SCU_MODE_FUNC4);
   Chip_SCU_PinMux(3, 2, SCU_MODE_ENT, SCU_MODE_FUNC4);

   /* Configuracion Teclas Poncho - Asignacion puerto GPIO Teclas */
   Chip_GPIO_SetDir(LPC_GPIO_PORT, SW_GPIO_PORT, SW_GPIO_MASK, false);

   /* Configuracion display LCD */
   lcdWriteEnable(0);

   /* Configuracion display LCD - Pines de datos  y control */
   Chip_SCU_PinMux(6, 4, SCU_MODE_SAL, SCU_MODE_FUNC0);
   Chip_SCU_PinMux(6, 5, SCU_MODE_SAL, SCU_MODE_FUNC0);
   Chip_SCU_PinMux(6, 9, SCU_MODE_SAL, SCU_MODE_FUNC0);
   Chip_SCU_PinMux(6, 10, SCU_MODE_SAL, SCU_MODE_FUNC0);
   Chip_SCU_PinMux(6, 11, SCU_MODE_SAL, SCU_MODE_FUNC0);
   Chip_SCU_PinMux(6, 12, SCU_MODE_SAL, SCU_MODE_FUNC0);   
   Chip_GPIO_SetDir(LPC_GPIO_PORT, 2, 0x100, 1);
   Chip_GPIO_SetDir(LPC_GPIO_PORT, 3, 0xF8, 1);

   lcdInicializar();

   /* Puerto Leds RGB */
   Chip_SCU_PinMux(1, 3, SCU_MODE_SAL, SCU_MODE_FUNC0);
   Chip_SCU_PinMux(1, 4, SCU_MODE_SAL, SCU_MODE_FUNC0);
   Chip_SCU_PinMux(1, 5, SCU_MODE_SAL, SCU_MODE_FUNC0);
   Chip_GPIO_ClearValue(LPC_GPIO_PORT, 0, (1 << 11) | (1 << 10) );
   Chip_GPIO_ClearValue(LPC_GPIO_PORT, 1, (1 << 8) );
   Chip_GPIO_SetDir(LPC_GPIO_PORT, 0, (1 << 11) | (1 << 10), 1);
   Chip_GPIO_SetDir(LPC_GPIO_PORT, 1, (1 << 8), 1);

   Chip_SCTPWM_Init(LPC_SCT);
   Chip_SCTPWM_SetRate(LPC_SCT, 10000);
   Chip_SCTPWM_SetOutPin(LPC_SCT, 1, 8);
   Chip_SCTPWM_SetOutPin(LPC_SCT, 2, 9);
   Chip_SCTPWM_SetOutPin(LPC_SCT, 3, 10);
   Chip_SCTPWM_Start(LPC_SCT);

}

void ConfigurarInterrupcion(void) {
   __asm__ volatile ("cpsid i");

   /* Activate SysTick */
   SystemCoreClockUpdate();
   SysTick_Config(SystemCoreClock/1000);

   /* Update priority set by SysTick_Config */
   NVIC_SetPriority(SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);

   __asm__ volatile ("cpsie i");
}