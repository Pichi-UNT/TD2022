

#include "reloj.h"
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

#define LCD_HORAS_DECENA    0
#define LCD_HORAS_UNIDAD    (LCD_HORAS_DECENA+1)
#define LCD_MINUTOS_DECENA  (LCD_HORAS_UNIDAD+2)
#define LCD_MINUTOS_UNIDAD  (LCD_MINUTOS_DECENA+1)
#define LCD_SEGUNDOS_DECENA (LCD_MINUTOS_UNIDAD+2)
#define LCD_SEGUNDOS_UNIDAD (LCD_SEGUNDOS_DECENA+1)



static uint8_t cuenta = 0;
static uint8_t cambios = 1;
static char cadena[9] = "00:00:00";
   
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

void SysTick_Handler(void) {
   static int contador = 0;

   contador++;
   if (contador%100 == 0) {
      Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, 0, 14);
   }
   if (contador%1000 == 0){
       cambios = 1;
       cuenta = (cuenta +1)%10;
       if(cadena[LCD_SEGUNDOS_UNIDAD] == 57){
             cadena[LCD_SEGUNDOS_UNIDAD] = (char)48;
         }else{
             cadena[LCD_SEGUNDOS_UNIDAD]++;
         }
   }
   if(contador >= 1000){
       contador = 0;
   }
}


int main(void)
{
   ConfigurarPuertosPoncho();
   ConfigurarInterrupcion();

   Chip_GPIO_SetPinState(LPC_GPIO_PORT, 1, 8, 1);
   Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 10, 1);
   Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 11, 1);

   static uint8_t anterior = 0;
   uint8_t actual;
   
   lcdEscribirCadena("     EMBOLE DE    ");
   lcdCursor(1,0);
   lcdEscribirCadena("      LAUTARO     ");

   while (1) {
      actual = Leer_Teclas();
      if (actual != anterior) {
         switch(actual) {
            case TECLA_F1:
               Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, 1, 8);
               break;
            case TECLA_F2:
               Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, 0, 10);
               break;
            case TECLA_F3:
               Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, 0, 11);
               break;
            case TECLA_F4:
               Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, 1, 8);
               Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, 0, 10);
               Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, 0, 11);
               break;
            default:
               break;
         }
         anterior = actual;
      }
     if(cambios){
         lcdCursor(1,0);
         
         lcdEscribirCadena(cadena);         
         cambios = 0;
     }
   }
}
