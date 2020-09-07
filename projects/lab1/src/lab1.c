#include "stdlib.h"
#include "stdint.h"
#include "configuracion.h"
#include "led.h"
#include <string.h>

#define USB_UART LPC_USART2
#define OVERRUN "ERROR OVERRUN\r\n"
#define PARITY "ERROR PARITY\r\n"
#define FRAMING "ERROR FRAMING\r\n"
#define BREAK "ERROR BREAK\r\n"
#define UNKNOWN "ERROR UNKNOWN\r\n"

static uint8_t actualizar = 0;

void SysTick_Handler(void) {
   static int contador = 0;

   contador++;
   if (contador%500 == 0) {
      Led_Toggle(RED_LED);
   }
   if(contador %1000 == 0) {
       contador = 0;
       actualizar = 1;
   }
}

void ConfigurarUART(LPC_USART_T *pUART){
    Chip_UART_Init(pUART);

    pUART->LCR |= 1<<7;

    //clock (204000000 / (16 * 9600))
    pUART->DLL = 0x30;
    pUART->DLM = 0x05;

    //Deshabilito DLAB
    pUART->LCR &= 0<<7;
	
    pUART->LCR = 0b000011011;

	//Habilito Tx
    pUART->TER2 = (1<<0);
}

uint8_t UARTDisponible(LPC_USART_T *pUART){
    return ((pUART->LSR & UART_LSR_THRE) != 0 );
}

uint8_t UARTLeerByte(LPC_USART_T *pUART, uint8_t* data, uint8_t* error){
    uint8_t resultado = 0;
    uint8_t status = pUART->LSR;
    if (status & (1<<0)){
        resultado = 1;
        if (status & ((1<<1)|(1<<2)|(1<<3)|(1<<4))){
            /*ERROR*/
            *error = status & (0x1E);
        } else {
            *data = (pUART->RBR & (0xFF));
        }
    }
    return resultado;
}


int main(void)
{
   uint8_t readData = 0;
   uint8_t readError = 0;
   uint8_t buffer[20] = "";
   uint8_t *ptrBuffer = buffer;
   uint8_t contador = 0;

   ConfigurarPuertosLaboratorio();
   ConfigurarInterrupcion();
   ConfigurarUART(USB_UART);
   
   while (1) {
       if(actualizar){
           actualizar = 0;
           Led_On(GREEN_LED);
           while (*ptrBuffer != '\0'){
               while(!UARTDisponible(USB_UART)){};
               USB_UART->THR = *ptrBuffer;
               ptrBuffer++;
           }
           ptrBuffer = buffer;
           buffer[0] = '\0';
           Led_Off(GREEN_LED);
       }
       if(UARTLeerByte(USB_UART, &readData, &readError)){
           if(readError){
               Led_Toggle(YELLOW_LED);
               if(readError & (1<<1)){
                   strcpy(buffer, OVERRUN);
               } else if(readError & (1<<2)){
                   strcpy(buffer, PARITY);
               } else if(readError & (1<<3)){
                   strcpy(buffer, FRAMING);
               } else if(readError & (1<<4)){
                   strcpy(buffer, BREAK);
               } else{
                   strcpy(buffer, UNKNOWN);
               }
               readError = 0;
           }else{
               Led_Toggle(RGB_B_LED);
               if(readData == 'q'){
                   if(contador == 99){
                       contador = 0;
                   }else{
                       contador++;
                   }
               }else if(readData == 'w'){
                   if(contador == 0){
                       contador = 99;
                   }else{
                       contador--;
                   }
               }else if(readData == 'e'){
                   contador = 0;
               }
               buffer[0] = (char)((contador/10)+48);
               buffer[1] = (char)((contador%10)+48);
               buffer[2] = '\r';
               buffer[3] = '\n';
               buffer[4] = '\0';
           }
       }else{
            buffer[0] = (char)((contador/10)+48);
            buffer[1] = (char)((contador%10)+48);
            buffer[2] = '\r';
            buffer[3] = '\n';
            buffer[4] = '\0';
       }
   }
}


