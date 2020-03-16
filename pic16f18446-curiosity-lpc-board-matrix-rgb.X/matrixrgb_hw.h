/****************************************************************************
* Title                 :   Matrix RGB CLICK
* Filename              :   matrixrgb_hw.h
* Author                :   CAL
* Origin Date           :   05/23/2016
* Notes                 :   Hardware layer
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*     Date    Software Version    Initials       Description
*  05/23/2016       .1              CAL       Interface Created.
*
*****************************************************************************/
/**
 * @file matrixrgb_hw.h
 * @brief <h3> Hardware Layer </h3>
 *
 * @par
 * Low level functions for
 * <a href="http://www.mikroe.com">MikroElektronika's</a> Matrix RGB click
 * board.
 */

/**
 * @page LIB_INFO Library Info
 * @date 25 May 2016
 * @author Corey Lakey
 * @copyright GNU Public License
 * @version 1.0.0 - Initial testing and verification
 */

/**
 * @page TEST_CFG Test Configurations
 *
 * ### Test configuration STM : ###
 * @par
 * -<b> MCU           </b> :      STM32F107VC
 * -<b> Dev. Board    </b> :      EasyMx Pro v7
 * -<b> Oscillator    </b> :      72 Mhz internal
 * -<b> Ext. Modules  </b> :      CLICKNAME Click
 * -<b> SW            </b> :      MikroC PRO for ARM 4.7.1
 *
 * ### Test configuration PIC32 : ###
 * @par
 * -<b> MCU           </b> :      PIC32MX795F512L
 * -<b> Dev. Board    </b> :      EasyPIC Fusion v7
 * -<b> Oscillator    </b> :      80 Mhz internal
 * -<b> Ext. Modules  </b> :      CLICKNAME Click
 * -<b> SW            </b> :      MikroC PRO for PIC 3.6.0
 *
 * ### Test configuration FT90x : ###
 * @par
 * -<b> MCU           </b> :      FT900Q
 * -<b> Dev. Board    </b> :      EasyFT90x v7
 * -<b> Oscillator    </b> :      100 Mhz internal
 * -<b> Ext. Modules  </b> :      CLICKNAME Click
 * -<b> SW            </b> :      MikroC PRO for FT90x 1.2.1
 *
 * ### Test configuration PIC : ###
 * @par
 * -<b> MCU           </b> :      PIC18F87K22
 * -<b> Dev. Board    </b> :      EasyPIC Pro v7
 * -<b> Oscillator    </b> :      16 Mhz external
 * -<b> Ext. Modules  </b> :      CLICKNAME Click
 * -<b> SW            </b> :      MikroC PRO for PIC 6.6.3
 *
 * ### Test configuration dsPIC : ###
 * @par
 * -<b> MCU           </b> :      dsPIC33EJ256GP710A
 * -<b> Dev. Board    </b> :      EasyPIC Fusion v7
 * -<b> Oscillator    </b> :      8 Mhz internal
 * -<b> Ext. Modules  </b> :      CLICKNAME Click
 * -<b> SW            </b> :      MikroC PRO for dsPIC 6.2.1
 *
 * ### Test configuration AVR : ###
 * @par
 * -<b> MCU           </b> :      ATMEGA32
 * -<b> Dev. Board    </b> :      EasyAVR v7
 * -<b> Oscillator    </b> :      8 Mhz external
 * -<b> Ext. Modules  </b> :      CLICKNAME Click
 * -<b> SW            </b> :      MikroC PRO for FT90x 6.1.1
 */

/**
 * @mainpage
 * <h3> General Description </h3>
 * @par
 *
 *
 * <h3> Features </h3>
 * @par
 *
 *
 */
#ifndef MATRIXRGB_HW_H
#define MATRIXRGB_HW_H
/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/
typedef struct
{
    uint8_t red;                  /**< Red Color ( 0 or 1 ) */
    uint8_t green;                /**< Green Color ( 0 or 1 ) */
    uint8_t blue;                 /**< Blue Color ( 0 or 1 ) */
}color_t;

typedef enum 
{
    BIG_PANEL   = 0,
    SMALL_PANEL = 1
} panel_size_t;

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief <h3> MatrixRGB Initialize </h3>
 *
 * @par
 *  Initializes width / height in panels of Matrix
 *
 * @note Do not send width and height in pixels, instead send the width and height in ( 16 x 32 ) 
 *  panels.
 *
 * @param[in] width         -        Width in panels
 * @param[in] height        -        Height in panels
 */
void matrixrgb_init( uint8_t width, uint8_t height, panel_size_t panel_size );

void matrixrgb_write_text( char *text, color_t color, uint8_t text_size, uint16_t start_row, uint16_t start_col );

/**
 * @brief <h3> MatrixRGB Image Load </h3>
 *
 * @par
 *  Loads a bitmap image to your display. 
 *
 * @note Works only with 565 format bitmaps, seperated in 2 8-bit values.
 * Each pixel : { RRRRRGGG, GGGBBBBB } <- 1 pixel
 *
 * @param[in] *bmp                -        Bitmap
 * @param[in] width         -        Width in pixels
 * @param[in] height        -        Height in pixels
 */
void matrixrgb_image_load( uint8_t *bmp, uint16_t width, uint16_t height );

/**
 * @brief <h3> MatrixRGB Scroll Image Left </h3>
 *
 * @par
 *  Takes a bitmap image ( see documentation of matrixrgb_image_load for desc. ) 
 * and scrolls it onto your display from right to left, stopping at the edge.
 *
 * @note To scroll all the way through your display, use matrixrgb_scroll_off_scrn_left
 *
 * @param[in] *bmp                 -   Bitmap
 * @param[in] width         -        Width in pixels
 * @param[in] height        -        Height in pixels
 * @param[in] speed         -        Speed to scroll, (lower the number, faster the scroll)
 */
void matrixrgb_scroll_img_left( uint8_t *bmp, uint16_t width, uint16_t height, uint8_t speed );

/**
 * @brief <h3> MatrixRGB Scroll Image Right </h3>
 *
 * @par
 *  Takes a bitmap image ( see documentation of matrixrgb_image_load for desc. ) 
 * and scrolls it onto your display from left to right, stopping at the edge.
 *
 * @note To scroll all the way through your display, use matrixrgb_scroll_off_scrn_right
 *
 * @param[in] *bmp                 -   Bitmap
 * @param[in] width         -        Width in pixels
 * @param[in] height        -        Height in pixels
 * @param[in] speed         -        Speed to scroll, (lower the number, faster the scroll)
 */
void matrixrgb_scroll_img_right( uint8_t *bmp, uint16_t width, uint16_t height, uint8_t speed );

/**
 * @brief <h3> MatrixRGB Write Pixel </h3>
 *
 * @par
 *  Writes a single pixel to your display.
 *
 * @param[in] row                -   Row of display
 * @param[in] column         -        Column of display
 * @param[in] red                -        Red pixel ( 0 or 1 )
 * @param[in] green         -        Green pixel ( 0 or 1 )
 * @param[in] blue                -        Blue pixel ( 0 or 1 )
 */
void matrixrgb_write_pixel( uint16_t row, uint16_t column, char red, char green, char blue );

/**
 * @brief <h3> MatrixRGB Write Pixel Image </h3>
 *
 * @par
 *  Writes a single pixel to your display.
 *
 * @note 
 *  Same as write_pixel except it takes color in 565 format.. ( colors are shifted to the lower bits ) 
 *
 * @param[in] row                -   Row of display
 * @param[in] column         -        Column of display
 * @param[in] red                -        Red pixel ( 5 bit resolution but display only uses 1 or 0 )
 * @param[in] green         -        Green pixel ( 6 bit resolution but display only uses 1 or 0 )
 * @param[in] blue                -        Blue pixel ( 5 bit resolution but display only uses 1 or 0 )
 */
void matrixrgb_write_pixel_img( uint16_t row, uint16_t column, char red, char green, char blue );

/**
 * @brief <h3> MatrixRGB Erase Pixel </h3>
 *
 * @par
 *  Erases a single pixel from your display.
 *
 * @param[in] row                -   Row of display
 * @param[in] column         -        Column of display
 */
void matrixrgb_erase_pixel( uint16_t row, uint16_t column );

/**
 * @brief <h3> MatrixRGB Scroll Text Right </h3>
 *
 * @par
 *  Scrolls text provided from left to right
 *
 * @param[in] *text                -   String of text
 * @param[in] color         -        color_t struct to use
 * @param[in] speed                -        Speed to scroll, (lower the number, faster the scroll)
 * @param[in] text_size -        Size of text in characters
 */
void matrixrgb_scroll_text_right( char *text, color_t color, uint8_t speed , uint8_t text_size );

/**
 * @brief <h3> MatrixRGB Scroll Text Left </h3>
 *
 * @par
 *  Scrolls text provided from right to left
 *
 * @param[in] *text                -   String of text
 * @param[in] color         -        color_t struct to use
 * @param[in] speed                -        Speed to scroll, (lower the number, faster the scroll)
 * @param[in] text_size -        Size of text in characters
 */
void matrixrgb_scroll_text_left( char *text, color_t color, uint8_t speed , uint8_t text_size );

/**
 * @brief <h3> MatrixRGB Shift Up </h3>
 *
 * @par
 *  Shifts the entire display up one row, last row becoming blank.
 *
 */
void matrixrgb_shift_up( void );

/**
 * @brief <h3> MatrixRGB Shift Down </h3>
 *
 * @par
 *  Shifts the entire display down one row, last row becoming blank.
 *
 */
void matrixrgb_shift_down( void );

/**
 * @brief <h3> MatrixRGB Shift Right </h3>
 *
 * @par
 *  Shifts the entire display right one row, last row becoming blank.
 *
 */
void matrixrgb_shift_right( void );

/**
 * @brief <h3> MatrixRGB Shift Left </h3>
 *
 * @par
 *  Shifts the entire display left one row, last row becoming blank.
 *
 */
void matrixrgb_shift_left( void );

/**
 * @brief <h3> MatrixRGB Scroll Off Screen Up </h3>
 *
 * @par
 *  Scrolls the entire screen off the screen, upwards.
 *
 * @param[in] speed         -        Speed to scroll, (lower the number, faster the scroll)        
 */
void matrixrgb_scroll_off_scrn_up( uint8_t speed );

/**
 * @brief <h3> MatrixRGB Scroll Off Screen Down </h3>
 *
 * @par
 *  Scrolls the entire screen off the screen, downwards.
 *
 * @param[in] speed         -        Speed to scroll, (lower the number, faster the scroll)        
 */
void matrixrgb_scroll_off_scrn_down( uint8_t speed );

/**
 * @brief <h3> MatrixRGB Scroll Off Screen Left </h3>
 *
 * @par
 *  Scrolls the entire screen off the screen, left.
 *
 * @param[in] speed         -        Speed to scroll, (lower the number, faster the scroll)        
 */
void matrixrgb_scroll_off_scrn_left( uint8_t speed );

/**
 * @brief <h3> MatrixRGB Scroll Off Screen Right </h3>
 *
 * @par
 *  Scrolls the entire screen off the screen, right.
 *
 * @param[in] speed         -        Speed to scroll, (lower the number, faster the scroll)        
 */
void matrixrgb_scroll_off_scrn_right( uint8_t speed );

/**
 * @brief <h3> MatrixRGB Refresh </h3>
 *
 * @par
 *  Refreshes the current state of the frame buffer to the actual display. 
 *
 * @note
 *  Should be used while in idle as much as possible to avoid flickering. Firmware
 * does its' own refreshing to keep the display lit while it is scrolling, but must be
 * done by the user while not scrolling to be able to see the display.
 *
 */
void matrixrgb_refresh( void );

/**
 * @brief <h3> MatrixRGB Clear Screen </h3>
 *
 * @par
 *  Clears the frame buffer, so that the next refresh shows a blank display.
 *
 */
void matrixrgb_clear_screen( void );

/**
 * @brief <h3> MatrixRGB Set Color </h3>
 *
 * @par
 *  Changes the color properties of your color_t struct for future usage. 
 *
 * @note
 *  Can also be done manually of course: my_color.red = 1;
 *        
 */
void matrixrgb_set_color( color_t *color, uint8_t red_color, uint8_t green_color, uint8_t blue_color );

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* MATRIXRGB_HW_H */
/*** End of File **************************************************************/