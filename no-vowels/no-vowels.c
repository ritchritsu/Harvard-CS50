#include <cs50.h>



#include <stdio.h>

string replace(string input); // prototype

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("One word only\n");
        return 1;
    }

    string result = replace(argv[1]);
    printf("%s\n", result);

    return 0;
}

string replace(string input)
{
    for (int i = 0; input[i] != '\0'; i++)
    {
        switch (input[i])
        {
            case 'A' | 'a':
                input[i] = '6';
                break;
            case 'E' | 'e':
                input[i] = '3';
                break;
            case 'I' | 'i':
                input[i] = '1';
                break;
            case 'O' | 'o':
                input[i] = '0';
                break;
        }
    }
    return input;
}
