#include <cs50.h>
#include <stdio.h>

int main()
{
    int n, numbers[100];
    n = get_int("Enter the no of numbers: ");
    printf("Enter the numbers: ");
    for (int i = 0; i < n; i++)
    {
        numbers[i] = get_int("");
    }

    for(int i = 0; i < n;i++)
    {
        int smallest = numbers[i], small_pos = i;
        int temp = 0;
        for(int j = i + 1; j < n; j++)
        {
            if(numbers[j] < smallest)
            {
                smallest = numbers[j];
                small_pos = j;
            }
        }
        if(small_pos != i)
        {
            temp = numbers[i];
            numbers[i] = smallest;
            numbers[small_pos] = temp;
        }

    }
    printf("sorted: ");
    for(int i = 0; i < n;i++)
    {
        printf("%i ",numbers[i]);
    }
    printf("\n");
}
