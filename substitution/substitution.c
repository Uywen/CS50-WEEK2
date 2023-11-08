#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[]) 
{
    if(argc != 2)
    {
        printf("Usage: ./substitution key\n");
    }

    string key = argv[1];
    for(int i = 0; i < strlen(key); i++)
    {
        // Characters entered need to be alphabets and need to be 26 characters long
        if(!isalpha(key[i]))
        {
            printf("Key must contain 26 characters");
        }

        // If its not 26 characters long this error will  print
        if(strlen(key) != 26)
        {
            printf("Must have 26 Characters.");
        }
    }

    // Checks if their are any duplicate values in the plaintext
    for(int i = 0 ; i < strlen(key); i++)
    {
        for(int j = i + 1; j < strlen(key); j++)
        {
            if(toupper(key[i]) == toupper(key[j]))
            {
                printf("Duplicate was found\n");
            }
        }
    }

    string plaintext = get_string("plaintext: ");

// Chnages all alphabets in key to uppercase
    for(int i = 0; i < strlen(key); i++)
    {
        // if lowercase we convert it to uppercase
        if(islower(key[i]))
        {
            key[i] = key[i] - 32;
        }
    }

    printf("cyphertext: ");

    for(int i = 0 ; i < strlen(plaintext);i++)
    {
        if(isupper(plaintext[i]))
        {
            // find the position of a particular plaintext.
        int answer = plaintext[i] - 65;
        printf("%c", key[answer]);
        }
        else if(islower(plaintext[i]))
        {
            int answer = plaintext[i] - 97;

            // plus 32 because it needs to be converted back to lowercase
            // Because the difference between uppercase and lowercase is 32
            printf("%c", key[answer] + 32);
        }
        else printf("%c", plaintext[i]);
    }
    printf("\n");
}