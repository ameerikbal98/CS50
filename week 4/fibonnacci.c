#include <cs50.h>
#include <stdio.h>

int fibonacci(int n)
{
    if(n == 1)
        return 0;
    else if(n == 2)
        return 1;
    else
        return fibonacci(n-2) + fibonacci(n-1);

}


int main(void)
{
    int n = get_int("Enter the number: ");
    printf("The number is: %i \n",fibonacci(n));

    for(int i = 1; i <= n;i++)
    {
        printf("%i ",fibonacci(i));
    }
}
