#include <cs50.h>
#include <stdio.h>
/*
Copy and paste from the "mario-more"
Just to do every exercise
*/

int main(void)
{
    // Will repeat the ask until enter a acceptable value
    int height;
    int row;
    int col;
    int space;

    do
    {

        height = get_int("Choose the height of the pyramid:");

    }

    while (1 > height || height > 8);

    for (row = 0; row < height; row++)// Here we do separate lines and columns
    {
        for (space = 0; space < height - row - 1; space ++)
        {
            //reducing spaces
            printf(" ");
        }
        for (col = 0; col <= row; col++)
        {
            // Creating first column of hashes
            printf("#");
        }
        printf("\n");
    }



}