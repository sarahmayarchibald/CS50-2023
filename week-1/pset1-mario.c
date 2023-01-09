#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for number between 1 and 8 only using a loop
    int number;
    do
    {
        number = get_int("Enter a number between 1 and 8: ");

    } while (number < 1 || number > 8);

    // Print the height entered by the user
    printf("Height: %i\n", number);

    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number - 1; j++)
        {
            printf(".");
            
        }
        printf("#\n");
        //number = number - 1;

    }

    //printf("\n");
}
