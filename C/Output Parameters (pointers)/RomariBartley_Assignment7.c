/*
Name        :   Romari Bartley
Assignment  :   7
Date        :   12/1/2020
Description :   1) Creating a user defined function that uses pointers as output parameters to find the the average and sum of 3 numbers
                2) Working with the string.h and ctype.h to find the first letter in a string and also check if the string is made up of letters in the alphabet
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE2 25
#define SIZE3 100

//function prototypes
void sum_n_avg (double n1, double n2, double n3, double *sum, double *avg);
char first_letter (char word[SIZE2]);

int main()
{
    printf("\t\t\tWELCOME\n\n\n");

    //QUESTION 1
    double num1, num2, num3, sum3, avg3; //declaring variables

    printf("\tSUM AND AVERAGE OF 3 NUMBERS (ex. 1 2 3)\n\n");

    printf("Please enter 3 numbers: "); //prompting the user for 3 numbers
    scanf("%lf%lf%lf",&num1,&num2,&num3); //accepting 3 numbers

    sum_n_avg(num1,num2,num3,&sum3,&avg3); //passing the 3 numbers entered as arguments

    //printing sum and average
    printf("\nThe sum of the three numbers is: %.0f\n",sum3);
    printf("The average of the three numbers is: %.2f\n",avg3);



    //QUESTION 2
    char full_word[SIZE2]; //declaring variables
    char f_letter;
    char list_words[SIZE3][SIZE2];
    char list_letters[SIZE3];
    int c=0;
    int length[SIZE3];
    printf("\n\n\n");

    printf("\tINPUT WORDS:\n");

    //loop to call function multiple times if necessary
    do{
        printf("Enter a word less than 25 letters: ");
        scanf("%s",full_word);

        f_letter=first_letter(full_word); //using the function to find the first letter

        if(f_letter!='#') //checking that word does not start with '#'
        {
            length[c]=strlen(full_word);

            for(int i=0;i<length[c];i++) //for loop to assign each word the right letters
            {
                list_words[c][i]=full_word[i]; //array to store all words entered

            }

            list_letters[c]=f_letter; //array used to store all first letters
            c++; //counter which enables the loop to switch from one word to another
        }

    } while (f_letter!='#'); //loop ends if word starts with '#'

    printf("\n\n");

    //printing results
    printf("\tRESULTS:\n");
    for(int i=0; i<c;i++) //outer loop to control the printing of each word
    {
        int check=1;
        for(int j=0; j<length[i];j++) //inner loop to control the printing of each letter for the current
        {

            if(!(isalpha(list_words[i][j]))) //checking if any letter in the word is not apart of the alphabet
            {
                check=0;
            }

            printf("%c",list_words[i][j]); //printing one of the words that was entered
        }
        printf("\t");
        if(check==1) //checking the value of check to decide whether isalpha is false or true
        {
            printf(" starts with the letter ");
            printf("%c\n",list_letters[i]); //printing the first letter
        }
        else
        {
            printf(" is not a word.\n"); //telling user that what was entered is not a word
        }

    }
    printf("\n\n\n\nPROGRAM HAS ENDED...\n\n");

    return 0;
}

//QUESTION 1
void sum_n_avg(double n1, double n2, double n3, double *sum, double *avg)
{
    //assigning values to arguments by using pointers
    *sum = n1+n2+n3;
    *avg = (n1+n2+n3)/3.0;
}


//QUESTION 2
char first_letter(char word[SIZE2])
{
    char letter1;

    //checking if letter is lowercase
    if(islower(word[0]))
    {
        letter1= toupper(word[0]); //changing first letter to uppercase before assigning it to the return value
    }
    else
    {
        letter1=word[0]; //assigning first letter to the return value
    }


    return letter1;


}
