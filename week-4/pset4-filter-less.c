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
    RGBTRIPLE temp[1][1];
    int pxEnd = width;
    int pxStart = 0;

    for (int i = 0; i < height; i++)
    {
        pxEnd = width - 1;
        pxStart = 0;
        int halfWidth = width / 2;

        for (int j = 0; j < halfWidth; j++)
        {
            // Using a placeholder
            temp[0][0] = image[i][pxStart];
            image[i][pxStart] = image[i][pxEnd];
            image[i][pxEnd] = temp[0][0];

            pxEnd--;
            pxStart++;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sumBlue = 0;
            float sumGreen = 0;
            float sumRed = 0;
            float counter = 0;

            for (int row = -1; row < 2; row++)
            {
                for (int col = -1; col < 2; col++)
                {
                    if (i + row < 0 || i + row > height - 1)
                    {
                        continue;
                    }

                    if (j + col < 0 || j + col > width - 1)
                    {
                        continue;
                    }

                    sumBlue += image[i + row][j + col].rgbtBlue;
                    sumGreen += image[i + row][j + col].rgbtGreen;
                    sumRed += image[i + row][j + col].rgbtRed;
                    counter++;
                }
            }

            copy[i][j].rgbtBlue = round(sumBlue / counter);
            copy[i][j].rgbtGreen = round(sumGreen / counter);
            copy[i][j].rgbtRed = round(sumRed / counter);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
        }

    }
    return;
}
