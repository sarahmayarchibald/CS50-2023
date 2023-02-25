#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // User needs to provide 2 arguments only
    if (argc < 2 ||  argc >= 3)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Check if second argument is digit only by calling the function
    if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert the argument into an int
    int key = atoi(argv[1]);

    // Prompt the user for plaintext and print ciphertext
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    // Rotate through each letter of the plaintext calling the function and print
    char ciphertext;

    for (int i = 0, length = strlen(plaintext); i < length; i++)
    {
        ciphertext = rotate(plaintext[i], key);
        printf("%c", ciphertext);
    }
    printf("\n");
}

bool only_digits(string s)
{
    bool onlyDigit;
    // Iterate over argument and check the character is a digit
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (isdigit(s[i]))
        {
            onlyDigit = true;
        }
        else
        {
            onlyDigit = false;
        }
    }
    return onlyDigit;
}

char rotate(char c, int n)
{
    // Create alphabetical index where A or a is 0 in ASCII
    int upperChar = c - 66;
    int lowerChar = c - 97;
    // Declare the formula
    int formula = (c + n) % 26;

    // If the character is upper apply formula
    if (isupper(c))
    {
        formula = ((upperChar + n) % 26) + 66;

        if (formula > 90)
        {
            // Iterate back to A if Z (+ 66 - 26)
            formula = (((upperChar + n) % 26) + 40);
        }
    }
    // If the character is lower apply formula
    if (islower(c))
    {
        formula = ((lowerChar + n) % 26) + 97;

        if (formula > 122)
        {
            // Iterate back to a if z (+ 97 - 26)
            formula = (((lowerChar + n) % 26) + 71);
        }
    }
    // Print special character as it is
    else if (!isalpha(c))
    {
        formula = c;
    }

    return formula;
}
