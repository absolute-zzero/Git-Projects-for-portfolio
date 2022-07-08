/*
Name        :   Romari Bartley
Assignment  :   6
Date        :   11/15/2020
Description :   1) Using pointers and arrays together to simple problems
                2) Using arrays and loops to find averages and print tables
*/


#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
#define SIZE2 10

void apps();
void table(int num1, int num2, int num3, int num4, int num5, int num6, int num7, int num8, int num9, int num10);

int main()
{
    printf("\t\t\t\tWELCOME\n\n");

    //QUESTION 1
    apps();

    //QUESTION 3
    table(8,12,18,25,24,30,28,22,23,10);

    printf("\n\n");
    return 0;
}


void apps()
{
    //QUESTION 1

    //question a
    int apples[SIZE]={2,4,6,8,10}; //defining and initializing array

    //question b
    int *aPtr; //defining pointer for int

    //question c
    printf("\t   USING INDEX NOTATION\n");
    printf("\t   Elements of array apples\n");
    for(int i=0; i<SIZE; i++) //loop to print all elements of array
    {
        printf("\t\tElement %d: %d\n",i+1,apples[i]);
    }

    printf("\n");
    //question d and e
    aPtr = apples; //assigning the starting address to pointer
    printf("\tAddress that aPtr currently points to: %p\n",aPtr);
    aPtr = &apples[0]; //assigning the starting address to pointer
    printf("\tAddress that aPtr currently points to: %p\n\n",aPtr);

    //question f
    printf("\t   USING POINTER/OFFSET NOTATION\n");
    printf("\t   Elements of array apples\n");
    for(int i=0; i<SIZE; i++) //printing elements of array using pointer/offset notation
    {
        printf("\t\tElement %d: %d\n",i+1 ,*(aPtr+i));
    }

    printf("\n");
    //question g
    printf("\tIn address %p, %d is stored\n\n", aPtr+3, *(aPtr+3)); //displaying the address and value of aPtr +3

    //question h
    printf("\tIf aPtr points to apples[4], then aPtr -= 4 would point to: %p\n\n\n\n",aPtr);
    //printing address of aPtr -=4 assuming that aPtr points to apples[4]
}


void table(int num1, int num2, int num3, int num4, int num5, int num6, int num7, int num8, int num9, int num10)
{
    //QUESTION 3

    //initializing variables
    int list10[SIZE2]={num1, num2, num3, num4, num5, num6, num7, num8, num9, num10,};
    double percentages[10];
    int sum =0;

    //for loop calculating sum
    for(int i=0; i<SIZE2; i++)
    {
        sum+=list10[i];
    }

    //for loop calculating percentages for each element
    for(int i=0; i<SIZE2; i++)
    {
        percentages[i] = (list10[i]/(double)sum)*100;
    }

    //for loop printing table
    printf("\t\t\t TABLE\n\n");
    printf("\t Index \t\t Value \t\t %% of total \n");
    for(int i=0; i<SIZE2; i++)
    {
        printf("%14d %15d %20.2f\n",i,list10[i],percentages[i]);
    }
}


