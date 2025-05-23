#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// prototype
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int totalPoints = 0;
    // iterate through word1
    for (int i = 0; word[i] != '\0'; i++)
    {
        char upperCaseLetter = toupper(word[i]);

        // check if the character is a valid uppercase letter
        if (upperCaseLetter >= 'A' && upperCaseLetter <= 'Z')
        {
            // map the letter to its corresponding index in POINTS ARRAY
            int index = upperCaseLetter - 'A';
            // add all the points from the word (DONE)
            totalPoints += POINTS[index];
        }
    }

    return totalPoints;
}
