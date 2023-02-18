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
    if (argc <= 1 || argc > 2)
    {
        printf("ERROR: Enter './no-vowels' and a word\n");
        return 1;
    }

    string word = argv[1];
    //printf("User word1: %s\n", word);

    printf("New word: %s\n", replace(word));
}

string replace(string word)
{
    int length = strlen(word);

    for (int i = 0; i < length; i++)
    {
        //printf("User word: %c\n", word[i]);

        switch (word[i])
        {
            case 1:
            if(word[i] == 'a')
            {
                word[i] = '6';
                printf("%c", word[i]);
            }

            break;

            default:
            printf("%c\n", word[i]);
        }
    }

    //printf("User word: %s\n", word);
    return word;
}
