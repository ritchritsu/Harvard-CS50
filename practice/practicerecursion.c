#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void stairs(int n);

int main(void)
{
    int height = get_int("height: ");
    stairs(height);
}

void stairs(int n)
{

    if (n <= 0)
    {
        return;
    }

stairs(n-1);


        for (int i = 0; i < n; i++)
        {
            printf("#");
        }
        printf("\n");


}
