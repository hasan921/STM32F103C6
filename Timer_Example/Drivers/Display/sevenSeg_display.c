/*
 * sevenSeg_display.c
 *
 *  Created on: 9 May 2021
 *      Author: WIN8
 */
#include "main.h"
#include "sevenSeg_display.h"

#define DISPLAY_LED_SAYISI (4)

/*****************************************************************************
 ***** Local Variable Declarations                                       *****
 *****************************************************************************/
// static unsigned int new_value ;
extern uint8_t saat ;
extern uint8_t dakika ;

/*****************************************************************************
 ***** Local Function Declarations                                       *****
 *****************************************************************************/

static void unit_digit(void);
static void tens_digit(void);
static void hundreds_digit(void);
static void thousands_digit(void);

/*****************************************************************************
 ***** Local Function Implementations                                    *****
 *****************************************************************************/

static void unit_digit(void)
{
   HAL_GPIO_WritePin(DISPLAY_1_GPIO_Port, DISPLAY_1_Pin, SET);
   HAL_GPIO_WritePin(DISPLAY_2_GPIO_Port, DISPLAY_2_Pin, RESET);
   HAL_GPIO_WritePin(DISPLAY_3_GPIO_Port, DISPLAY_3_Pin, RESET);
   HAL_GPIO_WritePin(DISPLAY_4_GPIO_Port, DISPLAY_4_Pin,RESET);


}

static void tens_digit(void)
{
    HAL_GPIO_WritePin(DISPLAY_2_GPIO_Port, DISPLAY_2_Pin,SET);
    HAL_GPIO_WritePin(DISPLAY_1_GPIO_Port, DISPLAY_1_Pin, RESET);
    HAL_GPIO_WritePin(DISPLAY_3_GPIO_Port, DISPLAY_3_Pin, RESET);
    HAL_GPIO_WritePin(DISPLAY_4_GPIO_Port, DISPLAY_4_Pin,RESET);


}
static void hundreds_digit(void)
{
    HAL_GPIO_WritePin(DISPLAY_3_GPIO_Port, DISPLAY_3_Pin,SET);
    HAL_GPIO_WritePin(DISPLAY_1_GPIO_Port, DISPLAY_1_Pin,RESET);
    HAL_GPIO_WritePin(DISPLAY_2_GPIO_Port, DISPLAY_2_Pin,RESET);
    HAL_GPIO_WritePin(DISPLAY_4_GPIO_Port, DISPLAY_4_Pin, RESET);



 }
static void thousands_digit(void)
{
    HAL_GPIO_WritePin(DISPLAY_4_GPIO_Port, DISPLAY_4_Pin,SET);
    HAL_GPIO_WritePin(DISPLAY_1_GPIO_Port, DISPLAY_1_Pin,RESET);
    HAL_GPIO_WritePin(DISPLAY_2_GPIO_Port, DISPLAY_2_Pin,RESET);
    HAL_GPIO_WritePin(DISPLAY_3_GPIO_Port, DISPLAY_3_Pin, RESET);

}

/*****************************************************************************
 ***** Public Function Implementations                                   *****
 *****************************************************************************/
void sevenSeg_interruptHandler(void)
{
    static unsigned int current_display = 4;
  // static unsigned int value_to_display ;

    if(current_display == DISPLAY_LED_SAYISI)
         {
             thousands_digit();
             sevenSeg_printDisplay(saat/10);
         }
         else if(3==current_display)
         {
             hundreds_digit();
             sevenSeg_printDisplay(saat%10);

         }
         else if(2==current_display)
         {
             tens_digit();
             sevenSeg_printDisplay(dakika/10);

         }
         else
         {
             unit_digit();
             sevenSeg_printDisplay(dakika%10);
         }
         current_display--;


         if (0 == current_display)
          {
              current_display = DISPLAY_LED_SAYISI ;
             //new_value++;
              //value_to_display = new_value;
          }
       /*
         if (new_value>9999)
         {
             new_value = 0 ;
         }
                            */


}

void sevenSeg_printDisplay(unsigned int a)
{
    switch(a)
      {
      case 0:
      {

          HAL_GPIO_WritePin(Pin_A_GPIO_Port, Pin_A_Pin, GPIO_PIN_RESET);
          HAL_GPIO_WritePin(Pin_B_GPIO_Port, Pin_B_Pin, GPIO_PIN_RESET);
          HAL_GPIO_WritePin(Pin_C_GPIO_Port, Pin_C_Pin, GPIO_PIN_RESET);
          HAL_GPIO_WritePin(Pin_D_GPIO_Port, Pin_D_Pin, GPIO_PIN_RESET);

          //HAL_Delay(2);
          break ;
      }
      case 1:
      {

          HAL_GPIO_WritePin(Pin_A_GPIO_Port, Pin_A_Pin, GPIO_PIN_SET);
          HAL_GPIO_WritePin(Pin_B_GPIO_Port, Pin_B_Pin, GPIO_PIN_RESET);
          HAL_GPIO_WritePin(Pin_C_GPIO_Port, Pin_C_Pin, GPIO_PIN_RESET);
          HAL_GPIO_WritePin(Pin_D_GPIO_Port, Pin_D_Pin, GPIO_PIN_RESET);

          //HAL_Delay(2);
          break;
      }
      case 2:
      {

          HAL_GPIO_WritePin(Pin_A_GPIO_Port, Pin_A_Pin, GPIO_PIN_RESET);
          HAL_GPIO_WritePin(Pin_B_GPIO_Port, Pin_B_Pin, GPIO_PIN_SET);
          HAL_GPIO_WritePin(Pin_C_GPIO_Port, Pin_C_Pin, GPIO_PIN_RESET);
          HAL_GPIO_WritePin(Pin_D_GPIO_Port, Pin_D_Pin, GPIO_PIN_RESET);

          //HAL_Delay(2);
          break;
      }
      case 3:
      {
          HAL_GPIO_WritePin(Pin_A_GPIO_Port, Pin_A_Pin, GPIO_PIN_SET);
          HAL_GPIO_WritePin(Pin_B_GPIO_Port, Pin_B_Pin, GPIO_PIN_SET);
          HAL_GPIO_WritePin(Pin_C_GPIO_Port, Pin_C_Pin, GPIO_PIN_RESET);
          HAL_GPIO_WritePin(Pin_D_GPIO_Port, Pin_D_Pin, GPIO_PIN_RESET);

          //HAL_Delay(2);
          break;
      }
      case 4:
      {

          HAL_GPIO_WritePin(Pin_A_GPIO_Port, Pin_A_Pin, GPIO_PIN_RESET);
          HAL_GPIO_WritePin(Pin_B_GPIO_Port, Pin_B_Pin, GPIO_PIN_RESET);
          HAL_GPIO_WritePin(Pin_C_GPIO_Port, Pin_C_Pin, GPIO_PIN_SET);
          HAL_GPIO_WritePin(Pin_D_GPIO_Port, Pin_D_Pin, GPIO_PIN_RESET);

          //HAL_Delay(2);
          break;
      }
      case 5:
      {

          HAL_GPIO_WritePin(Pin_A_GPIO_Port, Pin_A_Pin, GPIO_PIN_SET);
          HAL_GPIO_WritePin(Pin_B_GPIO_Port, Pin_B_Pin, GPIO_PIN_RESET);
          HAL_GPIO_WritePin(Pin_C_GPIO_Port, Pin_C_Pin, GPIO_PIN_SET);
          HAL_GPIO_WritePin(Pin_D_GPIO_Port, Pin_D_Pin, GPIO_PIN_RESET);

          //HAL_Delay(2);
          break;
      }
      case 6:
      {

          HAL_GPIO_WritePin(Pin_A_GPIO_Port, Pin_A_Pin, GPIO_PIN_RESET);
          HAL_GPIO_WritePin(Pin_B_GPIO_Port, Pin_B_Pin, GPIO_PIN_SET);
          HAL_GPIO_WritePin(Pin_C_GPIO_Port, Pin_C_Pin, GPIO_PIN_SET);
          HAL_GPIO_WritePin(Pin_D_GPIO_Port, Pin_D_Pin, GPIO_PIN_RESET);

          //HAL_Delay(2);
          break;
      }
      case 7:
      {

          HAL_GPIO_WritePin(Pin_A_GPIO_Port, Pin_A_Pin, GPIO_PIN_SET);
          HAL_GPIO_WritePin(Pin_B_GPIO_Port, Pin_B_Pin, GPIO_PIN_SET);
          HAL_GPIO_WritePin(Pin_C_GPIO_Port, Pin_C_Pin, GPIO_PIN_SET);
          HAL_GPIO_WritePin(Pin_D_GPIO_Port, Pin_D_Pin, GPIO_PIN_RESET);

          //HAL_Delay(2);
          break;
      }
      case 8:
      {

          HAL_GPIO_WritePin(Pin_A_GPIO_Port, Pin_A_Pin, GPIO_PIN_RESET);
          HAL_GPIO_WritePin(Pin_B_GPIO_Port, Pin_B_Pin, GPIO_PIN_RESET);
          HAL_GPIO_WritePin(Pin_C_GPIO_Port, Pin_C_Pin, GPIO_PIN_RESET);
          HAL_GPIO_WritePin(Pin_D_GPIO_Port, Pin_D_Pin, GPIO_PIN_SET);

          //HAL_Delay(2);
          break;
      }
      case 9:
      {
          HAL_GPIO_WritePin(Pin_A_GPIO_Port, Pin_A_Pin, GPIO_PIN_SET);
          HAL_GPIO_WritePin(Pin_B_GPIO_Port, Pin_B_Pin, GPIO_PIN_RESET);
          HAL_GPIO_WritePin(Pin_C_GPIO_Port, Pin_C_Pin, GPIO_PIN_RESET);
          HAL_GPIO_WritePin(Pin_D_GPIO_Port, Pin_D_Pin, GPIO_PIN_SET);

         // HAL_Delay(2);
          break;
      }

      }
}
