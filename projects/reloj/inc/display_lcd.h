#include <stdint.h>
#include "lcd.h"

typedef enum fila_display_s {
    SUPERIOR = 0,
    INFERIOR = 1,
} fila_display_t;

void limpiar_display(void);

void escribir_fila(fila_display_t fila, char * cadena);

void preparar_hora(uint8_t * hora, uint8_t * minuto, uint8_t * segundo, char * cadena);

void actualizar_hora(void);

void actualizar_pantalla(void);