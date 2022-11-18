#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
/*código = letra + ---> outra letra
alphabet = array
formula = c[i]=(p[i]+k)%26
c = ciphertext
p = plaintext
k = positions
c[i] = each letter
p[i] = text character

Function to cripto

Key == last argument = argv[argc - 1]

input plain

output cipher

convert int key = atoi(argv[1])
*/

bool only_digits(string argv[]);

void rotate(string plaintext, int key, string ciphertext);

int main(int argc, string argv[])
{
    if (argc == 2 && only_digits(argv) == true) // Calling only_digits function
    {
        int key = atoi(argv[1]);

        string plaintext = get_string("plaintext: ");
        string ciphertext = plaintext; //Just to have the same array
        rotate(plaintext, key, ciphertext); //Calling rotate function
        printf("ciphertext: %s\n", ciphertext);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

}

bool only_digits(string argv[])
{
    string key = argv[1];
    {
        for (int i = 0; i < strlen(key); i++)
        {
            if (!isdigit(key[i]))
            {
                return false; // Some digit is not a number
            }
        }
        return true; // Every digit is a number
    }
}

void rotate(string plaintext, int key, string ciphertext)
{
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char tocip = plaintext[i]; // just to be didatic

        if (isalpha(tocip)) // If is a alphabetical letter
        {
            if (islower(tocip))
            {
                int lowercip = tocip - 97; // Lower - 'a' = 0~26

                tocip = (((lowercip + key)) % 26) + 97;// it mantains in range 26

                ciphertext[i] = tocip;
            }
            else
            {
                int uppercip = tocip - 65;// upper - 'A' = 0~26

                tocip = ((uppercip + key) % 26) + 65;

                ciphertext[i] = tocip;
            }
        }
        else
        {
            ciphertext[i] = tocip;
        }
    }
}
