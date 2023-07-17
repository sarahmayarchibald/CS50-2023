#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Find average and round to nearest int
            float avg = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            int rounded = round(avg);
            // Apply average to RGB
            image[i][j].rgbtRed = rounded;
            image[i][j].rgbtGreen = rounded;
            image[i][j].rgbtBlue = rounded;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Define original colors
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            // Sepia algorithm - Use original color and apply algorithm
            float sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            float sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            float sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;

            // Round numbers to closest int
            int roundSepRed = round(sepiaRed);
            int roundSepGreen = round(sepiaGreen);
            int roundSepBlue = round(sepiaBlue);

            // if number > 255, cap at 255
            if (roundSepRed > 255)
            {
                roundSepRed = 255;

            }
            if (roundSepGreen > 255)
            {
                roundSepGreen  = 255;
            }
            else if (roundSepBlue > 255)
            {
                roundSepBlue = 255;
            }

            image[i][j].rgbtRed = roundSepRed;
            image[i][j].rgbtGreen = roundSepGreen;
            image[i][j].rgbtBlue = roundSepBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
