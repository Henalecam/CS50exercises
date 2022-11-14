#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
/*
In this case i will not create a function.
Input text:

Index = 0.0588 * L - 0.296 * S - 15.8

L = avg Letters per 100 words
S = avg Sentences per 100 words
avg L = (letters \ words) . 100
avg S = (sentences \ words) . 100
*/
int main(void)
{
    int letters = 0;
    int words = 1; //The last word don't use space
    int sentences = 0;
    string text = get_string("Enter your text: ");
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i])) // I tried to use ascii codes in the first try
        {
            letters++;
        }
        if (text[i] == ' ') // Space used to separate words
        {
            words++;

        }
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)// "!", ".", "?"
        {
            sentences++;
        }
    }
    float l = ((float)letters / (float)words) * 100;
    float s = ((float)sentences / (float)words) * 100;
    int index = round(0.0588 * l - 0.296 * s - 15.8); // Could do directly here the "l" and "s"
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}
