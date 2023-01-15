#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for number between 1 and 8 only using a loop
    int number;
    do
    {
        number = get_int("Enter a number between 1 and 8: ");

    } 
    while (number < 1 || number > 8);

    //Building the pyramid
    for (int i = 0; i < number; i++)
    {
        //Printing spaces
        for (int j = number - i; j > 1; j--)
        {
            printf(" ");
        }
        //Printing "#"
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        //Going to the next line
        printf("\n");
    }
}
