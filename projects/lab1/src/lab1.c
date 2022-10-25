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

void SysTick_Handler(void)
{
    static int contador = 0;

    contador++;
    if (contador % 500 == 0)
    {
        Led_Toggle(RED_LED);
    }
    if (contador % 1000 == 0)
    {
        contador = 0;
        actualizar = 1;
    }
}
/*
void ConfigurarUART(LPC_USART_T *pUART)
{

    Chip_UART_Init(pUART);

    pUART->LCR |= 1 << 7;

    //clock (204000000 / (16 * 9600))
    pUART->DLL = 0x30;
    pUART->DLM = 0x05;

    //Deshabilito DLAB
    pUART->LCR &= 0 << 7;

    pUART->LCR = 0b000011011;

    //Habilito Tx
    pUART->TER2 = (1 << 0);
}
*/
void ConfigurarUART(LPC_USART_T *pUART)
{
    Chip_UART_Init(pUART);

    pUART->LCR |= 1 << 7;

    //clock (204000000 / (16 * 9600))
    pUART->DLL = 0x30;
    pUART->DLM = 0x05;

    //Deshabilito DLAB
    pUART->LCR &= 0 << 7;

    pUART->LCR = 0b000011011;

    //Habilito Tx
    pUART->TER2 = (1 << 0);
}

uint8_t UARTDisponible(LPC_USART_T *pUART)
{
    return ((pUART->LSR & UART_LSR_THRE) != 0);
}

uint8_t UARTLeerByte(LPC_USART_T *pUART, uint8_t *data, uint8_t *error)
{
    uint8_t contenidoLSR=pUART->LSR;
    uint8_t datoRecibido=(contenidoLSR & UART_LSR_RDR);
    uint8_t errores=(contenidoLSR & (UART_LSR_OE | UART_LSR_PE | UART_LSR_FE | UART_LSR_BI));

    //Si recibi un dato
    if (datoRecibido == 1)
    {
        //checkeo errores
        if (errores>0)
        {
            *error = (pUART->LSR & (UART_LSR_OE | UART_LSR_PE | UART_LSR_FE | UART_LSR_BI)); 
            *data = '1'; //->en caso de error se guarda -1
        }
        else
        {
            *data = (pUART->RBR & UART_RBR_MASKBIT);
        }
    }

    return datoRecibido;
}

int main(void)
{

    ConfigurarPuertosLaboratorio();
    ConfigurarInterrupcion();
    ConfigurarUART(USB_UART);
    uint8_t data;
    uint8_t error;
    int contador = 10;
    int cantEnvios = 0;

    while (1)
    {
        if (actualizar)
        {
            actualizar = 0;
            Led_On(GREEN_LED);
            if (UARTDisponible(USB_UART))
            {
                //
                Chip_UART_SendByte(USB_UART, (char)((contador / 10) + 48));
                Chip_UART_SendByte(USB_UART, (char)((contador % 10) + 48));
                Chip_UART_SendByte(USB_UART, '\n');
                Chip_UART_SendByte(USB_UART, '\r');
            }

            Led_Off(GREEN_LED);
        }

        if (UARTLeerByte(USB_UART, &data, &error))
        {
            
            if (error>0)
            {
                //SI hay errores prendo leds
                Led_On(YELLOW_LED);

                if (error & UART_LSR_OE)
                {
                    if (UARTDisponible(USB_UART))
                    {
                        Chip_UART_SendByte(USB_UART, 'O');
                        Chip_UART_SendByte(USB_UART, 'E');
                        Chip_UART_SendByte(USB_UART, '\n');
                        Chip_UART_SendByte(USB_UART, '\r');
                    }
                }
                else if (error & UART_LSR_FE)
                {
                    if (UARTDisponible(USB_UART))
                    {
                        Chip_UART_SendByte(USB_UART, 'F');
                        Chip_UART_SendByte(USB_UART, 'E');
                        Chip_UART_SendByte(USB_UART, '\n');
                        Chip_UART_SendByte(USB_UART, '\r');
                    }
                }
                else if (error & UART_LSR_BI)
                {
                    if (UARTDisponible(USB_UART))
                    {
                        Chip_UART_SendByte(USB_UART, 'B');
                        Chip_UART_SendByte(USB_UART, 'I');
                        Chip_UART_SendByte(USB_UART, '\n');
                        Chip_UART_SendByte(USB_UART, '\r');
                    }
                }
                else if (error & UART_LSR_PE)
                {
                    if (UARTDisponible(USB_UART))
                    {
                        Chip_UART_SendByte(USB_UART, 'P');
                        Chip_UART_SendByte(USB_UART, 'E');
                        Chip_UART_SendByte(USB_UART, '\n');
                        Chip_UART_SendByte(USB_UART, '\r');
                    }
                }
                error = 0;
            }
            else
            {
                switch (data)
                {
                case 'q':
                    contador++;
                    if (contador == 99)
                    {
                        contador = 0;
                    }
                    break;
                case 'w':
                    contador--;
                    if (contador < 0)
                        contador = 99;
                    break;
                case 'e':
                    contador = 0;
                    break;
                default:
                    break;
                }
            }
        }
    }

}