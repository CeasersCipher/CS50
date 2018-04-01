// vigenere cipher
// encrypted message = (message + cipherargument(letter)) % 26

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // check # arguments & if incorrect reset
    if (argc != 2)
    {
        printf("Try Again. \n");
        return 1;
    }
    // check if key is alphabetic if not reset
    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Key must be a letter/alphabetic character");
                return 1;
            }

        }
    }

    // Store key as string and get len
    string k = argv[1];
    int LengthKey = strlen(k);

    string p = get_string("Enter your message: ");

    printf("ciphertext: ");
    // begin cipher encryption & loop through text
    for (int i = 0, j = 0, n = strlen(p); i < n; i++)
    {
        int keyLetter = tolower(k[j % LengthKey]) - 'a';

        if (isupper(p[i])) // if uppercase char run against upper
        {
            printf("%c", 'A' + (p[i] - 'A' + keyLetter) % 26);
            j++;
        }
        else if (islower(p[i])) // if lowercase char run against lower
        {
            printf("%c", 'a' + (p[i] - 'a' + keyLetter) % 26);
            j++;
        }
        else // default print
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");
    return 0;
}