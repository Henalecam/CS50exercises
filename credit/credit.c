#include <cs50.h>
#include <stdio.h>

void validatecard(long creditnumber);

int main(void)
{
  long creditnumber;

  creditnumber = get_long("Number: ");

  validatecard(creditnumber);

}

int inicialvalid(long creditnumber)
{
    while (creditnumber > 100)
    {
        creditnumber /= 10;
    }
    return creditnumber;
}

int numberlenght(long creditnumber)
{
    int digits = 0;
    while (creditnumber != 0)
    {
        digits++;
        creditnumber /= 10;
    }
    return digits;
}


char *digitscheck(long creditnumber)
{
    int first_two_digits = inicialvalid(creditnumber);
    int digits = numberlenght(creditnumber);
    if (first_two_digits > 50 && first_two_digits < 56)
    {
        if (digits == 16)
        {
            return ("MASTERCARD\n");
        }
        else
        {
            return ("INVALID\n");
        }
    }
    else if (first_two_digits == 34 || first_two_digits == 37)
    {
        if (digits == 15)
        {
            return ("AMEX\n");
        }
        else
        {
            return ("INVALID\n");
        }
    }
    else if (first_two_digits >= 40 && first_two_digits <= 50)
    {
        if (digits == 13 || digits == 16)
        {
            return ("VISA\n");
        }
        else
        {
            return ("INVALID\n");
        }
    }
    else
    {
        return ("INVALID\n");
    }
}


bool validateluhn(long creditnumber)
{
    int digits = numberlenght(creditnumber);
    int credit[digits];
    int contador = 0;
    int sobra = 0;
    while (creditnumber != 0)
    {
        sobra = creditnumber % 10;
        credit[contador] = sobra;
        contador ++;
        creditnumber /= 10;
    }
    int somarr = 0;
    int multiarr = 0;
    for (int i = 0; i < digits; i++)
    {
        if (i % 2 == 0)
        {
            somarr += credit[i];
        }
        else if (credit[i] * 2 >= 10)
        {
            multiarr += (credit[i] * 2) % 10;
            multiarr ++;
        }
        else
        {
            multiarr += credit[i] * 2;
        }


    }

    if ((somarr + multiarr) % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void validatecard(long creditnumber)
{
    if (validateluhn(creditnumber) == true)
    {
        char *flag = digitscheck(creditnumber);
        printf("%s", flag);
    }
    else
    {
        printf("INVALID\n");
    }

}