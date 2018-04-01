// necessary libs
#include <stdlib.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// implement (encrypted message) = (message) + (argument/cipher code) % 26
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Try Again\n");
        return 1;
    }

    // if argv is correct  put key into variable
    int k = atoi(argv[1]);

    if (k < 0)
    {
        printf("Try Again\n");
        return 1;
    }
    else
    {
        // ask for code to encrypt
        string code = get_string("What to encrypt: ");
        printf("ciphertext: ");
        for (int i = 0, n = strlen(code); i<n; i++)
        {
            //check lower
            if islower(code[i])
            {
                printf("%c", (((code[i] + k) - 97) % 26) + 97);
            }
            //check upper
            else if isupper(code[i])
            {
                printf("%c", (((code[i] + k) - 65) % 26) + 65);
            }
            // default print
            else
            {
                printf("%c", code[i]);
            }
        }
        printf("\n");
        return 0;
    }
}