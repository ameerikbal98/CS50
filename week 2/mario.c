#include "cs50/cs50.h"
#include <stdio.h>


/*
In a file called mario.c in a folder called mario-more, implement a program in C that recreates that pyramid, using hashes (#) for bricks, as in the below:

   #  #
  ##  ##
 ###  ###
####  ####

And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive int between, say, 1 and 8, inclusive.
*/


int main()
{
    int n;
    do
    {
        //n = get_int("Height: ");
        n = 5;
    }
    while (n < 1 || n > 8);

    int left_bound = n, right_bound = n + 3;
    for (int i = 0; i < n; i++) // this will execute for the pyramid's height
    {
        int j = 0;
        while (j < (2 * (n + 1))) // execute a pyramid's width which is 2 times the pyramid
                                  // height + 1 accounting the space between the pyramids
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
