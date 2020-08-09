/*
inicializar lcd
    init lcd
    lcd clear
    lcd enviar "EITI          2020"

borrar display
    lcd clear 

escribir_fila
    cursor fila
    escribir

preparar_hora {struct}
    return "xx:yy:zz"

actualizar_hora
    cursor
    escribir

cambiar_escenario escenario
    switch escenario
        escribe pantalla
*/



#include "display_lcd.h"

extern hora_t hora_actual;

void inicializar_display(void){
    lcdInicializar();
}

void limpiar_display(void){
    lcdBorrar();
}

void escribir_fila(fila_display_t fila, char * cadena){
    lcdCursor(fila, 0);
    lcdEscribirCadena(cadena);
}

void preparar_hora(hora_t hora_actual, char * cadena){

}

void actualizar_hora(void){

}