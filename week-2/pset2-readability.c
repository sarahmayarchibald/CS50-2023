#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt user for some text and print the output
    string text = get_string("Text: ");

    // Recall the functions that counts number of letters, words and sentences
    int allLetters = count_letters(text);
    int allWords = count_words(text);
    int allSentences = count_sentences(text);

    // Calculate the index using float for a more precise result
    float L = (float) allLetters / (float) allWords * 100;
    float S = (float) allSentences / (float) allWords * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    //Round result to closest integer
    int roundedValue = round(index);

    // Print results
    if (roundedValue < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (roundedValue >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", roundedValue);
    }
}

int count_letters(string text)
{
    // Declare letter count
    int numberLetters = 0;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        // Exclude non-alphanumerical characters
        if (isalnum(text[i]) || isalpha(text[i]))
        {
            numberLetters++;
        }
        else
        {
            numberLetters += 0;
        }
    }
    return numberLetters;
}

int count_words(string text)
{
    // Declare word count starting at 1
    int word = 1;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        char letter = text[i];

        // Exclude sentences starting with a space
        if (text[0] == ' ')
        {
            word = 0;
        }
        else if (letter == ' ')
        {
            word ++;
        }
        else if ((letter == ',') || (letter == '.') || (letter == '!'))
        {
            word += 0;
        }
    }
    return word;
}

int count_sentences(string text)
{
    // Declare sentence count
    int sentences = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        char letter = text[i];
        // Count these characters as end of sentences
        if ((letter == '?') || (letter == '.') || (letter == '!'))
        {
            sentences ++;
        }
        // Exclude space as starting a sentence
        else if (text[0] == ' ')
        {
            sentences = 0;
        }
    }
    return sentences;
}
