// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string word);

int main(int argc, string argv[])
{
    // Prompt for 1 argument count only
    if (argc <= 1 || argc > 2)
    {
        printf("ERROR: Enter './no-vowels' and a word\n");
        return 1;
    }
    // Assign word prompted to the argc
    string word = argv[1];

    // Print the changed word
    printf("%s\n", replace(word));
}

string replace(string word)
{
    // Check the length of the word prompted
    int length = strlen(word);

    // Iterate over each letter to check if a, e, o, i or u
    for (int i = 0; i < length; i++)
    {
        char letter = word[i];

        // Switch a to 6, e to 3, i to 1, o to 0 and maintain u
        switch (letter)
        {
            case 'a':
                word[i] = '6';
                break;

            case 'e':
                word[i] = '3';
                break;

            case 'i':
                word[i] = '1';
                break;

            case 'o':
                word[i] = '0';
                break;

            default:
                letter = word[i];
        }
    }

    // Return the new word if any vowels except u
    return word;
}
