#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
/*
argv[1] should be the key
key = 26 character
*/

bool checking(string argv[]);

void ciphering(string key, string plaintext, string ciphertext);

int main(int argc, string argv[])
{
    if(argc != 2 || strlen(argv[1]) != 26 || checking(argv) == false)
    {
        printf("Something is wrong.\n");
        return 1;
    }
    else
    {
        string key = argv[1];
        string plaintext = get_string("plaintext: ");
        string ciphertext = plaintext;
        ciphering(key, plaintext, ciphertext);
        printf("ciphertext: %s", ciphertext);

    }
}
/*
ciphering have
key = array 26
plaintext = abc
ciphertext = abc - 97
i = 0/ [a] - 97 = 0
key[plaintext[i] - 97]
*/
void ciphering(string key, string plaintext, string ciphertext)
{
    for(int i = 0; 1 < strlen(plaintext); i++)
    {
        char tocip = plaintext[i];

        if(isalpha(tocip))
        {
            if(islower(tocip))
            {
                int keyfinder = tocip - 97;

                char keytocip = key[keyfinder];

                ciphertext[i] = keytocip;

            }
            else
            {
                int keyfinder = tocip - 65;

                char keytocip = key[keyfinder];

                ciphertext[i] = keytocip;

            }
        }
        else
        {
            ciphertext[i] = tocip;
        }
    }
}
bool checking(string argv[])
{
    string key = argv[1];
    {
        for (int i = 0; i < strlen(key); i++)
        {
            //printf("%d this is I\n", i); (that was a debbug)
            if (!isalpha(key[i]))
            {
                return false; // Some digit is not a number
            }
            for(int j = 0; j < i; j++)
            {
                //printf("%d this is J\n", j); (debbug too)
                if(key[i] == key[j])
                {
                    return false;
                }
            }
        }
        return true; // Every digit is a number
    }
}
