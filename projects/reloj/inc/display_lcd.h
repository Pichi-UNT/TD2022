
#include "lcd.h"

typedef struct hora_s * hora_t;
typedef enum fila_display_s {
    SUPERIOR = 0,
    INFERIOR = 1,
} fila_display_t;

void inicializar_display(void);

void limpiar_display(void);

void escribir_fila(fila_display_t fila, char * cadena);

void preparar_hora(hora_t hora_actual, char * cadena);

void actualizar_hora(void);

void actualizar_pantalla(void);