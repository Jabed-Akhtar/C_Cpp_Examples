/********************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @author         : Jabed-Akhtar
  * @date           : 11.08.2022
  ******************************************************************************
  * Description:
  *     - Programm first ask for numbers to be added and get print the added result
  *       in terminal.
  *******************************************************************************/

/* Includes --------------------------------------------------------------------*/
#include <iostream>

/* Main - The application entry point ------------------------------------------*/
int main()
{
    int a, b;

    printf("------------------------ - \n");
    printf("Please enter the two numbers (with space in between) and press enter: ");

    scanf_s("%i %x", &a, &b); // don't use 'scanf' here ('scanf' -> error C4996)

    printf("------------------------ - \n");
    printf("Sum = %i\n", a + b);
    printf("------------------------ - \n");

    return 0;
}

/* ------------------------- END OF FILE ---------------------------------------*/