#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    double average;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
             average = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0, w = width/2; j < w; j++)
        {
        RGBTRIPLE temp = image[i][j];
        image[i][j] = image[i][(width-1)-j];
        image[i][(width-1)-j] = temp;
        }
    }

}

// Blur image
//For each pixel, you'll need to calculate the average color values (red, green, blue) of the surrounding pixels. This will require another nested loop to iterate over the surrounding pixels.
//Be careful at the edges of the image, as not all pixels have 8 neighbors. You'll need to add some conditions to handle these cases.
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    //putting the copy into the pixel
    RGBTRIPLE copy[height][width];
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            copy[x][y].rgbtBlue = image[x][y].rgbtBlue;
            copy[x][y].rgbtGreen = image[x][y].rgbtGreen;
            copy[x][y].rgbtRed = image[x][y].rgbtRed;
        }
    }


for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
          int aveR, aveG, aveB;
          aveR= aveG = aveB = 0;
          int count = 0;

           //nested for loop for the pixel neighbors
            for (int i = (x-1); i <= (x+1); i++)
            {
                for (int j = (y-1); j <= (y+1); j++)
                {
                  if ( ( i >= 0 && i <= (height-1)) &&  ( j >= 0 && j <= (width-1)))
                  {
                    aveR += copy[i][j].rgbtRed;
                    aveG += copy[i][j].rgbtGreen;
                    aveB += copy[i][j].rgbtBlue;
                    count++;
                  }

                }


            }
                image[x][y].rgbtRed = (int) round((double)aveR / (double)count);
                image[x][y].rgbtGreen = (int) round((double)aveG / (double)count);
                image[x][y].rgbtBlue = (int) round((double)aveB / (double)count);
        }
    }

















}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
