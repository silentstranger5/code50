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
            // Calculate the average value of the summ of pixel colors atributes
            RGBTRIPLE *pixel = &image[i][j];
            int average = round(((float) pixel->rgbtBlue + pixel->rgbtGreen + pixel->rgbtRed) / 3);

            // Assign pixel color atributes an average value of all colors
            pixel->rgbtBlue = pixel->rgbtGreen = pixel->rgbtRed = average;
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
                        // Add pixel color attribute values to color value sums
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
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

    // Declare coefficients of the matrix of the Sobel operator
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Iterate pixels in rows
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Declare of Sobel operator variables
            int GxBlue = 0, GxGreen = 0, GxRed = 0;
            int GyBlue = 0, GyGreen = 0, GyRed = 0;

            // Iterate position value terms
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    // Check conditions for respecting the boundaries of the image
                    if (i + k >= 0 && i + k < height && j + l >= 0 && j + l < width)
                    {
                        // Calculate values of the Sobel operator from the coefficients of the matrix
                        RGBTRIPLE pixel = copy[i + k][j + l];
                        GxBlue += pixel.rgbtBlue * Gx[k + 1][l + 1];
                        GxGreen += pixel.rgbtGreen * Gx[k + 1][l + 1];
                        GxRed += pixel.rgbtRed * Gx[k + 1][l + 1];
                        GyBlue += pixel.rgbtBlue * Gy[k + 1][l + 1];
                        GyGreen += pixel.rgbtGreen * Gy[k + 1][l + 1];
                        GyRed += pixel.rgbtRed * Gy[k + 1][l + 1];
                    }
                }
            }

            // Union of Sobel operator values for two dimensions
            int sobelBlue = round(sqrt(pow(GxBlue, 2) + pow(GyBlue, 2)));
            int sobelGreen = round(sqrt(pow(GxGreen, 2) + pow(GyGreen, 2)));
            int sobelRed = round(sqrt(pow(GxRed, 2) + pow(GyRed, 2)));

            // Cap Sobel operator values to 255
            if (sobelBlue > 255)
            {
                sobelBlue = 255;
            }
            if (sobelGreen > 255)
            {
                sobelGreen = 255;
            }
            if (sobelRed > 255)
            {
                sobelRed = 255;
            }

            // Assign pixel color attributes to the values of the Sobel operator
            RGBTRIPLE *pixel = &image[i][j];
            pixel->rgbtBlue = sobelBlue;
            pixel->rgbtGreen = sobelGreen;
            pixel->rgbtRed = sobelRed;
        }
    }
    return;
}
