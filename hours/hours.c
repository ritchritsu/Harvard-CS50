#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output); //function prototype

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: "); //user input
    int hours[weeks]; //hours has an index of weeks

    for (int i = 0; i < weeks; i++) //user input loop that stops once i reaches the number of weeks inputted by the user
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output; //declaring a char called output
    do // do/while loop that repeats if answer isnt T or A
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    int sum = 0;
    for (int x=0; x<weeks; x++)
    {
    sum+=hours[x];
    }


    int average = sum/weeks;
    return (output == 'T') ? sum : (output == 'A') ? average : -1; // if output = T, display sum        if output = A, display average     else display -1
}
