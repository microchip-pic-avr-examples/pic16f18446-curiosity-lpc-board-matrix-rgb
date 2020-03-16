/*
 * File:   matrixrgb_hal.c
 * Author: M19219
 *
 * Created on February 7, 2018, 6:00 PM
 */

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/device_config.h"

#include "matrixrgb_hal.h"

#define SPI1_DUMMY_DATA 0x0

void Delay_ms(uint16_t ms) {
    while(ms--) {
        __delay_ms(1);
    }
}


void matrixrgb_hal_cs_high()
{
    CS_SetHigh();
}

void matrixrgb_hal_cs_low()
{
    CS_SetLow();
}


void matrixrgb_hal_init()
{
    matrixrgb_hal_cs_high();
}



void matrixrgb_hal_write(uint8_t *buffer, uint16_t count)
{
    uint16_t i;

    while (RDY_PORT == 0)
    {
        ;
    } //Wait till slave is ready
    //__delay_ms(50);

    CS_SetLow();
    //__delay_us(10);

    for (i = 0; i < count; i++)
    {
        SPI1_Open(SPI1_DEFAULT);
        SPI1_ExchangeByte(buffer[i]);
        SPI1_Close();
    }

    CS_SetHigh();
    //__delay_us(10);
}


void matrixrgb_hal_read(uint8_t *buffer, uint16_t count)
{
    uint16_t i;

    for (i = 0; i < count; i++)
    {
        SPI1_Open(SPI1_DEFAULT);
        buffer[i] = SPI1_ExchangeByte(SPI1_DUMMY_DATA);
        SPI1_Close();
    }
}