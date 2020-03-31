#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int LEN = 26; // number of letters

int main(int argc, string argv[])
{
    string key, upperKey = NULL;
    int arr_ascii[LEN];

    if (argc != 2) // No second arg
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else if (strlen(argv[1]) != LEN) //Must to have 26 digits
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        key = argv[1];

        for (int k = 0; k < LEN; k++)
        {
            arr_ascii[k] = toupper(key[k]); // build key variable

            if (!(bool) isalpha(key[k])) //if digit not a alphabetic
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;

            }
        }

        for (int i = 0; i < LEN; i++)
        {
            for (int j = i + 1; j < LEN; j++) //counting leaving one
            {
                if (arr_ascii[i] == arr_ascii[j])
                {
                    printf("Key must not contain repeated character.\n");
                    return 1;
                }
            }
        }

        string plaintext = get_string("plaintext: ");

        printf("ciphertext:");

        for (int i = 0; i < strlen(plaintext); i++)
        {
            if (isalpha(plaintext[i]))
            {
                //look for relative position and if lower add 32
                printf("%c", arr_ascii[toupper(plaintext[i]) - 65] + (bool) islower(plaintext[i]) * 32);
            }
            else
            {
                printf("%c", plaintext[i]); // not a letter
            }
        }
        printf("\n");
    }

}