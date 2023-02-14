#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner depending on the score's result
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else if (score1 == score2)
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // Declare words' score starting at 0
    int wordScore = 0;

    // Loop over each letter
    for (int i = 0; i < strlen(word); i++)
    {
        // Declare the ASCII equivalent for each letter
        int ascii = word[i];
        // If uppercase, calculate lower case ASCII
        if (ascii >= 65 && ascii <= 90)
        {
            ascii = ascii + 32;
        }
        // For lower case ASCII, link ASCII number to index of the array and add points from index
        if (ascii >= 97 && ascii <= 122)
        {
            int letterScore = POINTS[ascii - 97];
            wordScore += letterScore;
        }
        // Don't add score for special characters of the ASCII
        else if (ascii < 65 || ascii > 90 || ascii < 97 || ascii > 123)
        {
            wordScore += 0;
        }
    }
    // Return variable to have the words' score
    return wordScore;
}
