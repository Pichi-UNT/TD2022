#include "display_lcd.h"


void limpiar_display(void){
    lcdBorrar();
}

void escribir_fila(fila_display_t fila, char * cadena){
    lcdCursor(fila, 0);
    lcdEscribirCadena(cadena);
}

void preparar_hora(uint8_t * hora, uint8_t * minuto, uint8_t * segundo, char * cadena){
    cadena[0] = *hora/10 + '0';
    cadena[1] = *hora%10 + '0';
    cadena[2] = ':';
    cadena[3] = *minuto/10 + '0';
    cadena[4] = *minuto%10 + '0';
    cadena[5] = ':';
    cadena[6] = *segundo/10 + '0';
    cadena[7] = *segundo%10 + '0';
}

void actualizar_hora(void){

}