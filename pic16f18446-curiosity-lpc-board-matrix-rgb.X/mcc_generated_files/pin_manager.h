/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.79.0
        Device            :  PIC16F18446
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.30	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RDY aliases
#define RDY_TRIS                 TRISAbits.TRISA2
#define RDY_LAT                  LATAbits.LATA2
#define RDY_PORT                 PORTAbits.RA2
#define RDY_WPU                  WPUAbits.WPUA2
#define RDY_OD                   ODCONAbits.ODCA2
#define RDY_ANS                  ANSELAbits.ANSA2
#define RDY_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RDY_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RDY_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RDY_GetValue()           PORTAbits.RA2
#define RDY_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RDY_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RDY_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define RDY_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define RDY_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define RDY_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define RDY_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define RDY_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set RST aliases
#define RST_TRIS                 TRISAbits.TRISA4
#define RST_LAT                  LATAbits.LATA4
#define RST_PORT                 PORTAbits.RA4
#define RST_WPU                  WPUAbits.WPUA4
#define RST_OD                   ODCONAbits.ODCA4
#define RST_ANS                  ANSELAbits.ANSA4
#define RST_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RST_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RST_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RST_GetValue()           PORTAbits.RA4
#define RST_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RST_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RST_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define RST_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define RST_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define RST_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define RST_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define RST_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RB6 procedures
#define RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RB6_GetValue()              PORTBbits.RB6
#define RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define RB6_SetPullup()             do { WPUBbits.WPUB6 = 1; } while(0)
#define RB6_ResetPullup()           do { WPUBbits.WPUB6 = 0; } while(0)
#define RB6_SetAnalogMode()         do { ANSELBbits.ANSB6 = 1; } while(0)
#define RB6_SetDigitalMode()        do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode()         do { ANSELCbits.ANSC0 = 1; } while(0)
#define RC0_SetDigitalMode()        do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set SLP aliases
#define SLP_TRIS                 TRISCbits.TRISC5
#define SLP_LAT                  LATCbits.LATC5
#define SLP_PORT                 PORTCbits.RC5
#define SLP_WPU                  WPUCbits.WPUC5
#define SLP_OD                   ODCONCbits.ODCC5
#define SLP_ANS                  ANSELCbits.ANSC5
#define SLP_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SLP_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SLP_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SLP_GetValue()           PORTCbits.RC5
#define SLP_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SLP_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define SLP_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define SLP_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define SLP_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define SLP_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define SLP_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define SLP_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set CS aliases
#define CS_TRIS                 TRISCbits.TRISC6
#define CS_LAT                  LATCbits.LATC6
#define CS_PORT                 PORTCbits.RC6
#define CS_WPU                  WPUCbits.WPUC6
#define CS_OD                   ODCONCbits.ODCC6
#define CS_ANS                  ANSELCbits.ANSC6
#define CS_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define CS_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define CS_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define CS_GetValue()           PORTCbits.RC6
#define CS_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define CS_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define CS_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define CS_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define CS_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define CS_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define CS_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define CS_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/