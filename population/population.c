#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int x, y;
    do
    {
        x = get_int("Start size: ");
    }
    while (x < 9);

    // TODO: Prompt for end size
    do
    {
        y = get_int("End size: ");
    }
    while (y < x);

    // TODO: Calculate number of years until we reach the threshold
    int population = x;
    int years = 0;

    while (population < y)
    {
        int newBorn = population / 3;
        int passedAway = population / 4;
        int newLlamas = newBorn - passedAway;
        population += newLlamas;
        years++;
    }

    // TODO: Print the number of years
    printf("Years: %i\n", years);

    return 0;
}
