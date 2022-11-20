#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
/*
Receive word input
   (65) a = 0 = A (97)
   (66) b = 1 = B (98)
   (90) z = 2 = Z (122)


*/
// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

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
    else if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Somenthing is wrong\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] >= 65 && word[i] <= 90) // Ascii a - z
        {
            score += POINTS[word[i] - 65];
        }
        else if (word[i] >= 97 && word[i] <= 122) // Ascii A - Z
        {
            score += POINTS[word[i] - 97];
        }
        else
        {
            continue;
        }
    }
    return score;
}
