/* Copyright 2014, 2015 Mariano Cerdeiro
 * Copyright 2014, Pablo Ridolfi
 * Copyright 2014, Juan Cecconi
 * Copyright 2014, Gustavo Muro
 * All rights reserved.
 *
 * This file is part of CIAA Firmware.
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
 *
 */

/** \brief Bare Metal example source file
 **
 ** This is a mini example of the CIAA Firmware.
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */
/** \addtogroup Examples CIAA Firmware Examples
 ** @{ */
/** \addtogroup Baremetal Bare Metal example source file
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 *
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
 */

/*==================[inclusions]=============================================*/
#include "ejemplo.h"       /* <= own header */

#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/
void configurarPuertos(void);

void ConfigurarInterrupcion(void);

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/
void ConfigurarPuertos(void) {

   #define SCU_MODE_SAL (SCU_MODE_INACT | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS)
   #define SCU_MODE_ENT (SCU_MODE_PULLUP | SCU_MODE_INBUFF_EN)

   /* Puerto Led RGB */
   /* Chip_SCU_PinMux(port, pin, options, function); */
   Chip_SCU_PinMux(2, 0, SCU_MODE_SAL, SCU_MODE_FUNC4);
   Chip_SCU_PinMux(2, 1, SCU_MODE_SAL, SCU_MODE_FUNC4);
   Chip_SCU_PinMux(2, 2, SCU_MODE_SAL, SCU_MODE_FUNC4);
   /* Chip_GPIO_ClearValue(LPC_GPIO_PORT, port, mask); */
   Chip_GPIO_ClearValue(LPC_GPIO_PORT, 5, (1 << 0) | (1 << 1) | (1 << 2));
   /* Chip_GPIO_SetDir(LPC_GPIO_PORT, port, mask, output); */
   Chip_GPIO_SetDir(LPC_GPIO_PORT, 5, (1 << 0) | (1 << 1) | (1 << 2), 1);

   /* Puerto Leds 1 a 3 */
   Chip_SCU_PinMux(2, 10, SCU_MODE_SAL, SCU_MODE_FUNC0);
   Chip_SCU_PinMux(2, 11, SCU_MODE_SAL, SCU_MODE_FUNC0);
   Chip_SCU_PinMux(2, 12, SCU_MODE_SAL, SCU_MODE_FUNC0);
   Chip_GPIO_ClearValue(LPC_GPIO_PORT, 0, (1 << 14));
   Chip_GPIO_ClearValue(LPC_GPIO_PORT, 1, (1 << 11) | (1 << 12));
   Chip_GPIO_SetDir(LPC_GPIO_PORT, 0, (1 << 14), true);
   Chip_GPIO_SetDir(LPC_GPIO_PORT, 1, (1 << 11) | (1 << 12), true);

   /* Puerto Teclas 1 a 4 */
   Chip_SCU_PinMux(1, 0, SCU_MODE_ENT, SCU_MODE_FUNC0);
   Chip_SCU_PinMux(1, 1, SCU_MODE_ENT, SCU_MODE_FUNC0);
   Chip_SCU_PinMux(1, 2, SCU_MODE_ENT, SCU_MODE_FUNC0);
   Chip_SCU_PinMux(1, 6, SCU_MODE_ENT, SCU_MODE_FUNC0);
   Chip_GPIO_SetDir(LPC_GPIO_PORT, 0, (1 << 4) | (1 << 8) | (1 << 9), false);
   Chip_GPIO_SetDir(LPC_GPIO_PORT, 1, (1 << 9), false);

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

/*==================[external functions definition]==========================*/
/**
 * @brief Funcion periodica que se ejecuta con el SysTick
 */
void SysTick_Handler(void) {
   static int contador = 0;

   contador++;
   if (contador > 100) {
      contador = 0;
      Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, 0, 14);
   }
}

/** 
 * @brief Main function
 *
 * This is the main entry point of the software.
 *
 * @returns 0
 *
 * @remarks This function never returns. Return value is only to avoid compiler
 *          warnings or errors.
 */
int main(void)
{
   int contador;
   int espera;
   int estado;
   int teclas;
   int anterior;

   /* perform the needed initialization here */
   ConfigurarPuertos();
   ConfigurarInterrupcion();
   
   estado = 0;
   anterior = 0;
   espera = 5;
   while(1) {      
      /* add your code here */
      for(contador = 0; contador < espera * 100000; contador++) {
         teclas = (~Chip_GPIO_GetPortValue(LPC_GPIO_PORT, 0) & ((1 << 9) | (1 << 8))) >> 7;
         teclas |= (~Chip_GPIO_GetPortValue(LPC_GPIO_PORT, 0) & (1 << 4)) >> 4;
         teclas |= (~Chip_GPIO_GetPortValue(LPC_GPIO_PORT, 1) & (1 << 9)) >> 6;
         
         Chip_GPIO_SetPinState(LPC_GPIO_PORT, 1, 11, teclas & (1 << 2));
         Chip_GPIO_SetPinState(LPC_GPIO_PORT, 1, 12, teclas & (1 << 3));

         if ((teclas & (1 << 0)) && (~anterior & (1 << 0))) {
            if (espera < 9) espera++;
         } else if ((teclas & (1 << 1)) && (~anterior & (1 << 1))) {
            if (espera > 1) espera--;
         }

         anterior = teclas;
      }

      estado++;
      switch (estado) {
         case 1:
            /* Chip_GPIO_SetPinState(LPC_GPIO_PORT, port, pin, value); */
            Chip_GPIO_SetPinState(LPC_GPIO_PORT, 5, 0, 1);
            Chip_GPIO_SetPinState(LPC_GPIO_PORT, 5, 1, 0);
            Chip_GPIO_SetPinState(LPC_GPIO_PORT, 5, 2, 0);
            break;
         case 2:
            /* Chip_GPIO_SetPinState(LPC_GPIO_PORT, port, pin, value); */
            Chip_GPIO_SetPinState(LPC_GPIO_PORT, 5, 0, 0);
            Chip_GPIO_SetPinState(LPC_GPIO_PORT, 5, 1, 1);
            Chip_GPIO_SetPinState(LPC_GPIO_PORT, 5, 2, 0);
            break;
         default:
            estado = 0;
            /* Chip_GPIO_SetPinState(LPC_GPIO_PORT, port, pin, value); */
            Chip_GPIO_SetPinState(LPC_GPIO_PORT, 5, 0, 0);
            Chip_GPIO_SetPinState(LPC_GPIO_PORT, 5, 1, 0);
            Chip_GPIO_SetPinState(LPC_GPIO_PORT, 5, 2, 1);
      }

   }
   return 0;
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

