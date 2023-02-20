// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    // Declare variable for each criteria
    char uppercase, lowercase, digit, symbol;

    // Iterate over password
    for (int i = 0, length = strlen(password); i < length; i++)
    {
        // Declare a variable for the letter
        char letter = password[i];
        // Declare a variable for ASCII equivalent of symbols
        int index;

        if (isupper(letter))
        {
            uppercase = letter;
        }
        else if (islower(letter))
        {
            lowercase = letter;
        }
        else if (isdigit(letter))
        {
            digit = letter;
        }
        else
        {
            // Find the ASCII equivalent of the symbol
            index = letter;
            if ((index >= 33 && index <= 47) || (index >= 58 && (index <= 64)))
            {
                symbol = letter;
            }
        }
    }

    // If all criteria are met, the password is valid
    if (uppercase && lowercase && digit && symbol)
    {
        return true;
    }

    // Return false if not all of the criteria are met
    return false;
}
