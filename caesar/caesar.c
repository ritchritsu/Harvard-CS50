#include <cs50.h>
#include <stdio.h>
#include <ctype.h>



int main(int argc, string argv[])
{

 if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }



return 0;
}


bool only_digits(string argv[1])
{

if (isdigit(argv[1]))
{
    return true;
}

else
{
return false;
}
}






