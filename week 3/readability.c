#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

/*
So what sorts of traits are characteristic of higher reading levels? Well, longer words probably
correlate with higher reading levels. Likewise, longer sentences probably correlate with higher
reading levels, too.

A number of “readability tests” have been developed over the years that define formulas for
computing the reading level of a text. One such readability test is the Coleman-Liau index. The
Coleman-Liau index of a text is designed to output that (U.S.) grade level that is needed to
understand some text. The formula is

index = 0.0588 * L - 0.296 * S - 15.8

where L is the average number of letters per 100 words in the text, and S is the average number of
sentences per 100 words in the text.
*/
int main(void)
{
    int word_count = 0, sentence_count = 0, letter_count = 0;
    float L = 0, S = 0;
    int index;

    string str = get_string("Text ");

    word_count = count_words(str);
    letter_count = count_letters(str);
    sentence_count = count_sentences(str);

    L = (letter_count / (float) word_count) * 100;
    S = (sentence_count / (float) word_count) * 100;

    index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int letter_count = 0;
    // Return the number of letters in text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letter_count += 1;
        }
    }

    return letter_count;
}

int count_words(string text)
{
    int word_count = 0;
    // Return the number of words in text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ' || text[i] == '\0')
        {
            while (text[i] == ' ' && i < len)
            {
                i++;
            }
            word_count += 1;
        }
    }
    return word_count + 1;
}

int count_sentences(string text)
{
    int sentence_count = 0;
    // Return the number of sentences in text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '?' || text[i] == '.' || text[i] == '!')
        {
            sentence_count += 1;
        }
    }
    return sentence_count;
}
