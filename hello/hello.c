#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name? ");
    printf("Hello, %s\n", name); // %s to get ready for a string
}