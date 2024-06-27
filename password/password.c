// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{

    bool lowerCase;
    bool upperCase;
    bool number;
    bool symbol;

    // loop statement that checks each string, if all conditions are met, return true
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (isupper(password[i]))
        {
            upperCase = true;
        }
        else if (islower(password[i]))
        {
            lowerCase = true;
        }
        else if (isdigit(password[i]))
        {
            number = true;
        }
        else
        {
            symbol = true;
        }
    }

    return (lowerCase && upperCase && number && symbol);
}
