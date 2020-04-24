/**
  UART3 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    uart3.c

  @Summary
    This is the generated driver implementation file for the UART3 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for UART3.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.0
        Device            :  PIC18F57Q43
        Driver Version    :  2.4.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB             :  MPLAB X 5.35
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

/**
  Section: Included Files
*/
#include <xc.h>
#include "uart3.h"

static volatile uart3_status_t uart3RxLastError;

/**
  Section: UART3 APIs
*/
void (*UART3_FramingErrorHandler)(void);
void (*UART3_OverrunErrorHandler)(void);
void (*UART3_ErrorHandler)(void);

void UART3_DefaultFramingErrorHandler(void);
void UART3_DefaultOverrunErrorHandler(void);
void UART3_DefaultErrorHandler(void);

void UART3_Initialize(void)
{
    // Disable interrupts before changing states

    // Set the UART3 module to the options selected in the user interface.

    // P1L 0; 
    U3P1L = 0x00;

    // P2L 0; 
    U3P2L = 0x00;

    // P3L 0; 
    U3P3L = 0x00;

    // BRGS high speed; MODE Asynchronous 8-bit mode; RXEN enabled; TXEN enabled; ABDEN disabled; 
    U3CON0 = 0xB0;

    // RXBIMD Set RXBKIF on rising RX input; BRKOVR disabled; WUE disabled; SENDB disabled; ON enabled; 
    U3CON1 = 0x80;

    // TXPOL not inverted; FLO off; RXPOL not inverted; RUNOVF RX input shifter stops all activity; STP Transmit 1Stop bit, receiver verifies first Stop bit; 
    U3CON2 = 0x00;

    // BRGL 25; 
    U3BRGL = 0x19;

    // BRGH 0; 
    U3BRGH = 0x00;

    // STPMD in middle of first Stop bit; TXWRE No error; 
    U3FIFO = 0x00;

    // ABDIF Auto-baud not enabled or not complete; WUIF WUE not enabled by software; ABDIE disabled; 
    U3UIR = 0x00;

    // ABDOVF Not overflowed; TXCIF 0; RXBKIF No Break detected; RXFOIF not overflowed; CERIF No Checksum error; 
    U3ERRIR = 0x00;

    // TXCIE disabled; FERIE disabled; TXMTIE disabled; ABDOVE disabled; CERIE disabled; RXFOIE disabled; PERIE disabled; RXBKIE disabled; 
    U3ERRIE = 0x00;


    UART3_SetFramingErrorHandler(UART3_DefaultFramingErrorHandler);
    UART3_SetOverrunErrorHandler(UART3_DefaultOverrunErrorHandler);
    UART3_SetErrorHandler(UART3_DefaultErrorHandler);

    uart3RxLastError.status = 0;

}

bool UART3_is_rx_ready(void)
{
    return (bool)(PIR9bits.U3RXIF);
}

bool UART3_is_tx_ready(void)
{
    return (bool)(PIR9bits.U3TXIF && U3CON0bits.TXEN);
}

bool UART3_is_tx_done(void)
{
    return U3ERRIRbits.TXMTIF;
}

uart3_status_t UART3_get_last_status(void){
    return uart3RxLastError;
}

uint8_t UART3_Read(void)
{
    while(!PIR9bits.U3RXIF)
    {
    }

    uart3RxLastError.status = 0;

    if(U3ERRIRbits.FERIF){
        uart3RxLastError.ferr = 1;
        UART3_FramingErrorHandler();
    }

    if(U3ERRIRbits.RXFOIF){
        uart3RxLastError.oerr = 1;
        UART3_OverrunErrorHandler();
    }

    if(uart3RxLastError.status){
        UART3_ErrorHandler();
    }

    return U3RXB;
}

void UART3_Write(uint8_t txData)
{
    while(0 == PIR9bits.U3TXIF)
    {
    }

    U3TXB = txData;    // Write the data byte to the USART.
}





void UART3_DefaultFramingErrorHandler(void){}

void UART3_DefaultOverrunErrorHandler(void){}

void UART3_DefaultErrorHandler(void){
}

void UART3_SetFramingErrorHandler(void (* interruptHandler)(void)){
    UART3_FramingErrorHandler = interruptHandler;
}

void UART3_SetOverrunErrorHandler(void (* interruptHandler)(void)){
    UART3_OverrunErrorHandler = interruptHandler;
}

void UART3_SetErrorHandler(void (* interruptHandler)(void)){
    UART3_ErrorHandler = interruptHandler;
}






/**
  End of File
*/
