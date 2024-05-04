#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate pixels in rows
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate average value of pixel colors
            RGBTRIPLE *pixel = &image[i][j];
            int average = round(((float) pixel->rgbtBlue + pixel->rgbtGreen + pixel->rgbtRed) / 3);

            // Assign pixel color attributes to average value of all colors
            pixel->rgbtBlue = pixel->rgbtGreen = pixel->rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate pixels in rows
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate sepia color value from formula
            RGBTRIPLE *pixel = &image[i][j];
            int sepiaRed = round(.393 * pixel->rgbtRed + .769 * pixel->rgbtGreen + .189 * pixel->rgbtBlue);
            int sepiaGreen = round(.349 * pixel->rgbtRed + .686 * pixel->rgbtGreen + .168 * pixel->rgbtBlue);
            int sepiaBlue = round(.272 * pixel->rgbtRed + .534 * pixel->rgbtGreen + .131 * pixel->rgbtBlue);

            // Cap sepia color value to 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // Assign pixel color attribute to sepia color value
            pixel->rgbtRed = sepiaRed;
            pixel->rgbtGreen = sepiaGreen;
            pixel->rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate pixels in rows
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Swap pixels until the middle
            if (j < width / 2)
            {
                RGBTRIPLE *pixel1 = &image[i][j];
                RGBTRIPLE *pixel2 = &image[i][width - (j + 1)];
                RGBTRIPLE tmp = *pixel1;
                *pixel1 = *pixel2;
                *pixel2 = tmp;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of the image to keep the original values
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Iterate pixels in rows
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Declare summ and counter variables
            int summBlue = 0, summGreen = 0, summRed = 0;
            int counter = 0;

            // Iterate position value terms
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    // Check conditions for respecting the boundaries of the image
                    if (i + k >= 0 && i + k < height && j + l >= 0 && j + l < width)
                    {
                        // Add pixel color attribute values to sums of the color values
                        RGBTRIPLE pixel = copy[i + k][j + l];
                        summBlue += pixel.rgbtBlue;
                        summGreen += pixel.rgbtGreen;
                        summRed += pixel.rgbtRed;
                        counter++;
                    }
                }
            }

            // Assign pixel color attributes to average value for each color
            RGBTRIPLE *pixel = &image[i][j];
            pixel->rgbtBlue = round((float) summBlue / counter);
            pixel->rgbtGreen = round((float) summGreen / counter);
            pixel->rgbtRed = round((float) summRed / counter);
        }
    }
    return;
}
