#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Pixel must be a pointer due to scope
            RGBTRIPLE *pixel = &image[i][j];
            // As the compiler kindly hints to us, we should use "->" to access attributes of structure pointer
            if (pixel->rgbtBlue == 0x00 && pixel->rgbtGreen == 0x00 && pixel->rgbtRed == 0x00)
            {
                pixel->rgbtBlue = 0x80;
                pixel->rgbtGreen = 0x00;
                pixel->rgbtRed = 0x80;
            }
        }
    }
}
