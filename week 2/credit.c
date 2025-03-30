#include "cs50/cs50.h"
#include <stdio.h>
/*
    Luhn’s Algorithm

    Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add
   those products’ digits together. Add the sum to the sum of the digits that weren’t multiplied
   by 2. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent
   to 0), the number is valid!

*/
int main()
{
    long num = get_long("Number: ");
    int i = 0, d, sum_2 = 0, sum_1 = 0;
    char type = 'N';

    while (num > 0)
    {
        d = num % 10;
        if (i % 2 == 0)
        {
            sum_1 += d;
        }
        else
        {
            d = d * 2;
            while (d > 0)
            {
                sum_2 = sum_2 + ((d % 10));
                d = d / 10;
            }
        }
        if (num < 100 && type == 'N')
        {
            if (num == 34 || num == 37)
            {
                type = 'A';
            }
            else if (num <= 55 && num >= 51)
            {
                type = 'M';
            }
            else if (num <= 49 && num >= 40)
            {
                type = 'V';
            }
            else
            {
                type = 'I';
                break;
            }
        }
        num = num / 10;
        i += 1;
    }
    sum_1 += sum_2;

    if (sum_1 % 10 == 0)
    {
        if (type == 'A' && i == 15)
        {
            printf("AMEX\n");
        }
        else if (type == 'V' && (i == 13 || i == 16))
        {
            printf("VISA\n");
        }
        else if (type == 'M' && i == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
