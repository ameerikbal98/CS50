#include "cs50/cs50.h"
#include <stdio.h>

int main()
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    int left_bound = n, right_bound = n + 3;
    for (int i = 0; i < n; i++) // this will execute for the pyramid's height
    {
        int j = 0;
        while (j < (2 * (n + 1))) // execute a pyramid's width which is 2 times the pyramid
                                  // hight + 1 accounting the space between the pyramids
        {
            if ((j <= left_bound - 1 && j >= left_bound - 1 - i) ||
                (j >= right_bound - 1 &&
                 j <= right_bound - 1 + i)) // this will check the bounds of the # symbol and if the
                                            // j is within the bounds # will be printed
            {
                printf("#");
            }
            else if (j > (right_bound - 1 + i)) // checks if the bound over the right most
                                                // bound and breaks the code
            {
                break;
            }
            else // if no # then a space will be printed
            {
                printf(" ");
            }
            j++;
        }
        printf("\n");
    }
}
