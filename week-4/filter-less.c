#include "helpers.h"
#include <stdio.h>
#include <math.h>

//image[0][0].rgbtRed = 0;

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
