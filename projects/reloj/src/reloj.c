#include "reloj.h"
#include <string.h>

static uint8_t cuenta = 0;
static uint8_t cambios = 1;
static char cadena[9] = "00:00:00";

struct hora_s{
    uint8_t hora;
    uint8_t minuto;
    uint8_t segundo;
};
static struct hora_s hora_actual = {0};


void contar_tiempo(void){
    if (hora_actual.segundo < 59){
        hora_actual.segundo++;
    }else if (hora_actual.minuto < 59){
        hora_actual.segundo = 0;
        hora_actual.minuto++;
    }else if (hora_actual.hora < 23){
        hora_actual.segundo = 0;
        hora_actual.minuto = 0;
        hora_actual.hora++;
    }else{
        hora_actual.segundo = 0;
        hora_actual.minuto = 0;
        hora_actual.hora = 0;
    }
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
       contar_tiempo();
       preparar_hora(&(hora_actual.hora), &(hora_actual.minuto), &hora_actual.segundo, cadena);
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
   
   hora_actual.hora = 23;
   hora_actual.minuto = 59;
   hora_actual.segundo = 50;
   strcpy(cadena, "23:59:50");
   
   escribir_fila(0,"EITI          2020");
   escribir_fila(1,"             RELOJ");

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
         escribir_fila(INFERIOR,cadena);     
         cambios = 0;
     }
   }
}
