#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8; // THERE ARe 8 BITS IN A BITE

void print_bulb(int bit); // FUNCTION PROTOTYPE

int main(void)
{
    // 1. Get input string from the user.
    string text = get_string("Enter a message: ");

    // This line starts a for loop that iterates over each character of the entered string (text). The loop continues until it
    // reaches the null terminator ('\0') indicating the end of the string.
    for (int i = 0; text[i] != '\0'; i++)
    {
        // Convert character to decimal value
        int decimalValue = (int) text[i]; // NOW THE DECIMALS ARE STORED IN decimalValue

        for (int x = BITS_IN_BYTE - 1; x >= 0; x--)
        // This line starts another for loop that converts the decimal value to binary. It iterates over each bit from the most significant bit (MSB) to the least significant bit (LSB).
        {
            int bit = (decimalValue >> x) & 1;
            print_bulb(bit);
        }
        printf("\n");
    }

    /*
     Convert the decimal value to binary representation.
     Use the print_bulb function to display light and dark emojis based on the binary representation.

   Define the print_bulb function:
      If the input bit is 0, print the dark emoji.
      If the input bit is 1, print the light emoji.

   End.
   */
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
