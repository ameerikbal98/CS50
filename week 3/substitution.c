#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

/*
In a substitution cipher, we “encrypt” (i.e., conceal in a reversible way) a message by replacing
every letter with another letter. To do so, we use a key: in this case, a mapping of each of the
letters of the alphabet to the letter it should correspond to when we encrypt it. To “decrypt” the
message, the receiver of the message would need to know the key, so that they can reverse the
process: translating the encrypt text (generally called ciphertext) back into the original message
(generally called plaintext).

A key, for example, might be the string NQXPOMAFTRHLZGECYJIUWSKDVB. This 26-character key means that
A (the first letter of the alphabet) should be converted into N (the first character of the key), B
(the second letter of the alphabet) should be converted into Q (the second character of the key),
and so forth.

A message like HELLO, then, would be encrypted as FOLLE, replacing each of the letters according to
the mapping determined by the key.

In a file called substitution.c in a folder called substitution, create a program that enables you
to encrypt messages using a substitution cipher. At the time the user executes the program, they
should decide, by providing a command-line argument, on what the key should be in the secret message
they’ll provide at runtime.
*/
int main(int argc, string argv[])
{

    string key = argv[1];
    if (argc == 1) // checks if it provides no key at all
    {
        printf("Usage: ./readability key\n");
        return 1;
    }
    if (argc > 2) // checks if it provides more than 1 key
    {
        printf("Too many arguments, Please provide a single string of 26 alphabetic characters\n");
        return 1;
    }
    else
    {
        if (strlen(argv[1]) != 26) // checks if the key is exactly 26 characters
        {
            printf("Key should be of size 26\n");
            return 1;
        }
        else
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (toupper(key[j]) == toupper(key[i])) // this will check for duplicate keys
                    {
                        printf("Duplicate characters in key are not allowed\n");
                        return 1;
                    }
                }
                if (!isalpha(argv[1][i])) // check if there are any non alphabetic characters
                {
                    printf("The key should be only alphabetic characters \n");
                    return 1;
                }
                else
                {
                    key[i] = (char) toupper(
                        argv[1][i]); // before storing the key we first convert it to upper case
                }
            }
        }
    }

    string text = get_string("plaintext:");

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] = key[text[i] - 65]; // if the text have upper case character then we copy
                                             // directly from the key as we have already converted
                                             // all the key characters to upper case
            }
            else
            {
                text[i] = tolower(key[toupper(text[i]) -
                                      65]); // this will first convert the key to uppercase before
                                            // figuring out the relative index in array and then
                                            // conver the chracter in the key array to lower case
            }
        }
    }

    printf("ciphertext:%s\n", text);
}
