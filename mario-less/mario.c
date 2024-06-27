#include <cs50.h>
#include <stdio.h>

int main()
{

    int height;
    // user input
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height > 8);

    // for height
    for (int i = 0; i < height; i++)
    // prints space
    {
        for (int a = 0; a < height - i - 1; a++)
        {
            printf(" ");
        }
        for (int b = 0; b < i + 1; b++)
        {
            printf("#");
        }

        for (int gap = 0; gap < 2; gap++)
        {
            printf(" ");
        }

        for (int d = 0; d < i + 1; d++)
        {
            printf("#");
        }

        for (int c = 0; c > height - i - 1; c++)
        {
            printf(" ");
        }

        printf("\n");
    }

    return 0;
}
