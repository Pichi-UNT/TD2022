/* Copyright 2016, Laboratorio de Microprocesadores 
 * Facultad de Ciencias Exactas y Tecnología 
 * Universidad Nacional de Tucuman
 * http://www.microprocesadores.unt.edu.ar/
 * Copyright 2016, Esteban Volentini <evolentini@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/** \brief Manejo de pantallas alfanumericas
 **
 ** Manejo de pantallas alfanumericas de texto basadas en el controlador HD44780. La libreria
 ** soporta el manejo del display con 4 u 8 lineas de datos y sin la linea READ.
 **
 ** \addtogroup lcd Pantalla LCD
 ** \brief Manejo de pantallas LCD alfanumericas
 ** @{ */

/* === Inclusiones de cabeceras ================================================================ */

#include "lcd.h"

/* === Definicion y Macros ===================================================================== */

#define DELAY_ESTABILIZACION  1
#define DELAY_COMANDO      5

#define LCD_DATA_BITS		4

#define lcdWriteEnable(valor)			   Chip_GPIO_SetPinState(LPC_GPIO_PORT, 2, 8, valor)
#define lcdRegisterSelect(valor)		   Chip_GPIO_SetPinState(LPC_GPIO_PORT, 3, 3, valor)
#define lcdWriteDataBits(valor)			Chip_GPIO_ClearValue(LPC_GPIO_PORT, 3, 0xF0);			\
										         Chip_GPIO_SetValue(LPC_GPIO_PORT, 3, valor  & 0xF0);

/* === Declaraciones de tipos de datos internos ================================================ */

/* === Declaraciones de funciones internas ===================================================== */

/* === Definiciones de variables externas ====================================================== */

/* === Definiciones de funciones internas =====================================================- */
void __attribute__((optimize("O0"))) delayNs(int value) {
   int index;
   for(index = 1; index < value; index++);
}

void delayUs(int value) {
   int index;
   for(index = 1; index < value; index++) {
      delayNs(1000);
   }
}

/* === Definiciones de funciones externas ====================================================== */
void lcdEscribirDatos(lcd_registro_t destination, uint8_t data) {

   lcdRegisterSelect(destination);
   lcdWriteEnable(1);

#if (LCD_DATA_BITS == 4)
   lcdWriteDataBits(data & 0xF0);
   
   delayNs(DELAY_ESTABILIZACION);
   lcdWriteEnable(0);
   delayNs(DELAY_ESTABILIZACION);
   
   lcdWriteEnable(1);
   lcdWriteDataBits(data << 4);
#else
   lcdWriteDataBits(data);
#endif
   delayNs(DELAY_ESTABILIZACION);
   lcdWriteEnable(0);
   delayNs(DELAY_ESTABILIZACION);
   delayUs(DELAY_COMANDO);
}

void lcdInicializar(void) {
   lcdRegisterSelect(LCD_CMD_REG);
   lcdWriteEnable(1);
   lcdWriteDataBits(0x20);
   delayNs(DELAY_ESTABILIZACION);
   lcdWriteEnable(0);
   delayNs(DELAY_ESTABILIZACION);

   delayUs(DELAY_COMANDO);

   lcdEscribirDatos(LCD_CMD_REG, 0x22);     // 4 Bits de Datos, 2 Lineas, Caracteres de 5x7
   lcdEscribirDatos(LCD_CMD_REG, 0x28);     // 4 Bits de Datos, 2 Lineas, Caracteres de 5x7
   lcdEscribirDatos(LCD_CMD_REG, 0x0C);      // Mostrar Display, Ocultar Cursor, Sin Intermitente
   lcdEscribirDatos(LCD_CMD_REG, 0x06);      // Incrementar Direccion, Desplazar Cursor
   lcdBorrar();
}

void lcdCursor(uint8_t row, uint8_t col) {
   const static uint8_t firstCol[4] = {0x80, 0xC0, 0x94, 0xD4};
   lcdEscribirDatos(LCD_CMD_REG, firstCol[row] + col);
   delayUs(2);
}

void lcdBorrar(void) {
   lcdEscribirDatos(LCD_CMD_REG, 0x01);     
   delayUs(500);
}


void lcdEscribirCadena(const char * text) {
   while(*text != 0) {
      lcdEscribirDatos(LCD_DATA_REG, *text);
      text++;
   }
}
/* === Ciere de documentacion ================================================================== */

/** @} Final de la definición del modulo para doxygen */

