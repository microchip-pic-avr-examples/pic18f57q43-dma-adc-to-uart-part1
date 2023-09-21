/**
 * UART3 Generated Driver API Header File
 * 
 * @file uart3.h
 * 
 * @defgroup uart3 UART3
 * 
 * @brief This file contains API prototypes and other datatypes for UART3 module.
 *
 * @version UART3 Driver Version 3.0.4
*/
/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef UART3_H
#define UART3_H

/**
  Section: Included Files
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "../system/system.h"
#include "uart_drv_interface.h"

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

#define UART3_interface UART3


#define UART3_Initialize     UART3_Initialize
#define UART3_Deinitialize   UART3_Deinitialize
#define UART3_Write          UART3_Write
#define UART3_Read           UART3_Read
#define UART3__IsRxReady     UART3_IsRxReady
#define UART3_IsTxReady      UART3_IsTxReady
#define UART3_IsTxDone       UART3_IsTxDone

#define UART3_TransmitEnable       UART3_TransmitEnable
#define UART3_TransmitDisable      UART3_TransmitDisable
#define UART3_AutoBaudSet          UART3_AutoBaudSet
#define UART3_AutoBaudQuery        UART3_AutoBaudQuery
#define UART3_BRGCountSet               (NULL)
#define UART3_BRGCountGet               (NULL)
#define UART3_BaudRateSet               (NULL)
#define UART3_BaudRateGet               (NULL)
#define UART3__AutoBaudEventEnableGet   (NULL)
#define UART3_ErrorGet             UART3_ErrorGet

#define UART3_TxCompleteCallbackRegister     (NULL)
#define UART3_RxCompleteCallbackRegister      (NULL)
#define UART3_TxCollisionCallbackRegister  (NULL)
#define UART3_FramingErrorCallbackRegister UART3_FramingErrorCallbackRegister
#define UART3_OverrunErrorCallbackRegister UART3_OverrunErrorCallbackRegister
#define UART3_ParityErrorCallbackRegister  UART3_ParityErrorCallbackRegister
#define UART3_EventCallbackRegister        (NULL)

/**
 @ingroup uart3
 @struct uart3_status_t
 @breif This is an instance of UART3_STATUS for UART3 module
 */
typedef union {
    struct {
        uint8_t perr : 1;     /**<This is a bit field for Parity Error status*/
        uint8_t ferr : 1;     /**<This is a bit field for Framing Error status*/
        uint8_t oerr : 1;     /**<This is a bit field for Overfrun Error status*/
        uint8_t reserved : 5; /**<Reserved*/
    };
    size_t status;            /**<Group byte for status errors*/
}uart3_status_t;

/**
 Section: Data Type Definitions
 */

/**
 * @ingroup uart3
 * @brief External object for uart_drv_interface.
 */
extern const uart_drv_interface_t UART3;

/**
 * @ingroup uart3
 * @brief This API initializes the UART3 driver.
 *        This routine initializes the UART3 module.
 *        This routine must be called before any other UART3 routine is called.
 *        This routine should only be called once during system initialization.
 * @param None.
 * @return None.
 */
void UART3_Initialize(void);

/**
 * @ingroup uart3
 * @brief This API Deinitializes the UART3 driver.
 *        This routine disables the UART3 module.
 * @param None.
 * @return None.
 */
void UART3_Deinitialize(void);

/**
 * @ingroup uart3
 * @brief This API enables the UART3 module.     
 * @param None.
 * @return None.
 */
inline void UART3_Enable(void);

/**
 * @ingroup uart3
 * @brief This API disables the UART3 module.
 * @param None.
 * @return None.
 */
inline void UART3_Disable(void);

/**
 * @ingroup uart3
 * @brief This API enables the UART3 transmitter.
 *        UART3 should also be enable to send bytes over TX pin.
 * @param None.
 * @return None.
 */
inline void UART3_TransmitEnable(void);

/**
 * @ingroup uart3
 * @brief This API disables the UART3 transmitter.
 * @param None.
 * @return None.
 */
inline void UART3_TransmitDisable(void);

/**
 * @ingroup uart3
 * @brief This API enables the UART3 Receiver.
 *        UART3 should also be enable to receive bytes over RX pin.
 * @param None.
 * @return None.
 */
inline void UART3_ReceiveEnable(void);

/**
 * @ingroup uart3
 * @brief This API disables the UART3 Receiver.
 * @param None.
 * @return None.
 */
inline void UART3_ReceiveDisable(void);

/**
 * @ingroup uart3
 * @brief This API enables the UART3 send break control.
 * @param None.
 * @return None.
 */
inline void UART3_SendBreakControlEnable(void);

/**
 * @ingroup uart3
 * @brief This API disables the UART3 send break control.
 * @param None.
 * @return None.
 */
inline void UART3_SendBreakControlDisable(void);

/**
 * @ingroup uart3
 * @brief This API enables the UART3 AutoBaud Detection.
 * @param bool enable.
 * @return None.
 */
inline void UART3_AutoBaudSet(bool enable);


/**
 * @ingroup uart3
 * @brief This API reads the UART3 AutoBaud Detection Complete bit.
 * @param None.
 * @return None.
 */
inline bool UART3_AutoBaudQuery(void);

/**
 * @ingroup uart3
 * @brief This API Reset the UART3 AutoBaud Detection Complete bit.
 * @param None.
 * @return None.
 */
inline void UART3_AutoBaudDetectCompleteReset(void);

/**
 * @ingroup uart3
 * @brief This API reads the UART3 AutoBaud Detection overflow bit.
 * @param None.
 * @return None.
 */
inline bool UART3_IsAutoBaudDetectOverflow(void);

/**
 * @ingroup uart3
 * @brief This API Reset the UART3 AutoBaud Detection Overflow bit.
 * @param None.
 * @return None.
 */
inline void UART3_AutoBaudDetectOverflowReset(void);

/**
 * @ingroup uart3
 * @brief This API checks if UART3 receiver has received data and ready to be read.
 * @param None.
 * @retval true if UART3 receiver FIFO has a data
 * @retval false UART3 receiver FIFO is empty
 */
bool UART3_IsRxReady(void);

/**
 * @ingroup uart3
 * @brief This function checks if UART3 transmitter is ready to accept a data byte.
 * @param None.
 * @retval true if UART3 transmitter FIFO has atleast 1 byte space
 * @retval false if UART3 transmitter FIFO is full
 */
bool UART3_IsTxReady(void);

/**
 * @ingroup uart3
 * @brief This function return the status of transmit shift register (TSR).
 * @param None.
 * @retval true if Data completely shifted out from the TSR
 * @retval false if Data is present in Transmit FIFO and/or in TSR
 */
bool UART3_IsTxDone(void);

/**
 * @ingroup uart3
 * @brief This function gets the error status of the last read byte.
 *        This function should be called before UART3_Read().
 * @pre RX should be enable by calling UART3_RxEnable() before calling this API.
 * @param None.
 * @return Status of the last read byte. See uart3_status_t struct for more details.
 */
size_t UART3_ErrorGet(void);

/**
 * @ingroup uart3
 * @brief This function reads the 8 bits from receiver FIFO register.
 * @pre The transfer status should be checked to see if the receiver is not empty
 *      before calling this function. UART3_IsRxReady() should be checked in if () before calling this API.
 * @param None.
 * @return 8-bit data from RX FIFO register.
 */
uint8_t UART3_Read(void);

/**
 * @ingroup uart3
 * @brief This function writes a byte of data to the transmitter FIFO register.
 * @pre The transfer status should be checked to see if the transmitter is ready to accept a byte
 *      before calling this function. UART3_IsTxReady() should be checked in if() before calling this API.
 * @param txData  - Data byte to write to the TX FIFO.
 * @return None.
 */
void UART3_Write(uint8_t txData);

/**
 * @ingroup uart3
 * @brief This API registers the function to be called upon UART3 framing error.
 * @param callbackHandler - a function pointer which will be called upon framing error condition.
 * @return None.
 */
void UART3_FramingErrorCallbackRegister(void (* callbackHandler)(void));

/**
 * @ingroup uart3
 * @brief This API registers the function to be called upon UART3 overrun error.
 * @param callbackHandler - a function pointer which will be called upon overrun error condition.
 * @return None.
 */
void UART3_OverrunErrorCallbackRegister(void (* callbackHandler)(void));

/**
 * @ingroup uart3
 * @brief This API registers the function to be called upon UART3 Parity error.
 * @param callbackHandler - a function pointer which will be called upon Parity error condition.
 * @return None.
 */
void UART3_ParityErrorCallbackRegister(void (* callbackHandler)(void));

#ifdef __cplusplus  // Provide C++ Compatibility


    }

#endif

#endif  // UART3_H
