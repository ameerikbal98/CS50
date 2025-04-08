#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = get_int("Enter the number of elements: ");

    int numbers[100];

    printf("Enter the elements: ");
    for(int i = 0; i < n; i++)
    {
        numbers[i] = get_int("");
    }

    int swap_count = -1, j = 1;

    while(swap_count != 0)
    {
        swap_count = 0;

        for(int i = 0; i < n - j; i++)
        {
            if(numbers[i] > numbers[i+1])
            {
                int temp = numbers[i+1];
                numbers[i+1] = numbers[i];
                numbers[i] = temp;
                swap_count += 1;
            }
        }
        j += 1;
    }

    printf("sorted: ");
    for(int i = 0; i < n;i++)
    {
        printf("%i ",numbers[i]);
    }
    printf("\n");
}
