#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
/*
In the game of Scrabble, players create words to score points, and the number of points is the sum
of the point values of each letter in the word.
A   B   C   D   E   F   G   H   I   J   K   L   M   N   O   P    Q  R   S   T   U   V   W   X   Y    Z
1	3	3	2	1	4	2	4	1	8	5	1	3	1	1	3	10	1	1	1	1	4	4	8	4	10

For example, if we wanted to score the word “CODE”, we would note that the ‘C’ is worth 3 points,
the ‘O’ is worth 1 point, the ‘D’ is worth 2 points, and the ‘E’ is worth 1 point. Summing these, we
get that “CODE” is worth 7 points.

In a file called scrabble.c in a folder called scrabble, implement a program in C that determines
the winner of a short Scrabble-like game. Your program should prompt for input twice: once for
“Player 1” to input their word and once for “Player 2” to input their word. Then, depending on which
player scores the most points, your program should either print “Player 1 wins!”, “Player 2 wins!”,
or “Tie!” (in the event the two players score equal points).
*/
int main(void)
{
    string p1 = get_string("Player 1:");
    string p2 = get_string("Player 2:");
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    int score1 = 0, score2 = 0;
    int index;

    for (int i = 0, len = strlen(p1); i < len;
         i++) // the code uses the asci code to find the eight score for each letters from the array
    {
        if (isalpha(p1[i]))
        {
            score1 += points[tolower(p1[i]) - 'a'];
        }
    }

    for (int i = 0, len = strlen(p2); i < len; i++)
    {
        if (isalpha(p2[i]))
        {
            score2 += points[tolower(p2[i]) - 'a'];
        }
    }

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
