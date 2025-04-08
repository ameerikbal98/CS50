#include <cs50.h>
#include <stdio.h>

int factorial(int n)
{
    if(n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main(void)
{
    int n = get_int("Enter number: ");

    printf("%i\n",factorial(n));
}
