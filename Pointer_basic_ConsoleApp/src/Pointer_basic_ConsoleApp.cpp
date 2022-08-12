/********************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @author         : Jabed-Akhtar
  * @date           : 12.08.2022
  ******************************************************************************
  * Description:
  *     - A simple (simplest) Pointer Project.
  *******************************************************************************/

/* Includes --------------------------------------------------------------------*/
#include <iostream>

using namespace std;

/* Main - The application entry point ------------------------------------------*/
int main()
{
    // initialising variables
    int val1, val2;
    int* ptr;

    val1 = 10;
    ptr = &val2; // saving address of val2 to pointer ptr
    *ptr = 20; // setting value to pointer adress -> val2 = 10

    // Printing val1 and val2
    cout << "-------------------------\n";
    cout << "Frist value: " << val1 << '\n';
    cout << "Second value: " << val2 << '\n';
    cout << "-------------------------\n";
    
    // saving values to a variable through pointer
    int arrVal[5];
    int* ptrArr;
    ptrArr = arrVal; *ptrArr = 10;
    ptrArr++; *ptrArr = 20;
    ptrArr = &arrVal[2];  *ptrArr = 30;
    ptrArr = arrVal + 3;  *ptrArr = 40;
    ptrArr = arrVal;  *(ptrArr + 4) = 50;

    // printing variable arrVal
    for (int n = 0; n < 5; n++) {
        cout << arrVal[n] << ",";
    }
    // printing pointer addresses
    cout << "\n";
    cout << "Frist value: " << arrVal << '\n'; // pointer value
    cout << "Frist value: " << ptrArr << '\n'; // pointer value
    cout << "Frist value: " << &arrVal << '\n'; // -> pointer value same as arrVal
    cout << "Frist value: " << &ptrArr << '\n'; // pointer value
    cout << "-------------------------\n";

    return 0;
}

/* ------------------------- END OF FILE ---------------------------------------*/