/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.79.0
        Device            :  PIC16F18446
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/device_config.h"
#include "matrixrgb_hw.h"

void main(void)
{
    int16_t x, y, i, j;
    color_t my_color;
    uint8_t c;
    uint8_t text[64] = "Welcome to Microchip !";
    uint8_t textSize;

    // initialize the device
    SYSTEM_Initialize();

    SLP_SetHigh(); // don't care

    //__delay_ms(50);
    RST_SetLow();
    __delay_ms(20);
    RST_SetHigh();
    __delay_ms(200);

    CS_SetHigh(); // hal init

    __delay_ms(20);

    matrixrgb_init(1, 1, 0);

    __delay_ms(110); // firmware needs 100ms

    matrixrgb_clear_screen();
    matrixrgb_refresh();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    for (i = 0; text[i] != 0; i++)
    {
        ;
    }
    textSize = i;

    i = 0;

    while (1)
    {
        while (eusart1RxCount > 0)
        {
            c = EUSART1_Read();
            EUSART1_Write(c);
            if (c == '\n')
            {
                text[i] = 0;
                textSize = i;
                i = 0;
            }
            else
            {
                text[i++] = c;
            }
        }

        for (i = 0; i < textSize; i++)
        {
            switch (i % 6)
            {
                case 0:
                    matrixrgb_set_color(&my_color, 1, 0, 0);
                    break;
                case 1:
                    matrixrgb_set_color(&my_color, 0, 1, 0);
                    break;
                case 2:
                    matrixrgb_set_color(&my_color, 0, 0, 1);
                    break;
                case 3:
                    matrixrgb_set_color(&my_color, 0, 1, 1);
                    break;
                case 4:
                    matrixrgb_set_color(&my_color, 1, 1, 0);
                    break;
                case 5:
                    matrixrgb_set_color(&my_color, 1, 0, 1);
                    break;

                default:
                    break;
            }

            matrixrgb_scroll_text_left(&(text[i]), my_color, 33, 1);

        }

        matrixrgb_scroll_text_left("    ", my_color, 33, 4);

        i = 0;
    }
}

/**
 End of File
 */