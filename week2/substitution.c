#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool isAlpha(string key);
bool isUniqueLetters(string key);
void encrypt(string plaintext, string key);

int main(int argc, string argv[])
{
    // Check if exactly one argument is provided
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Get key
    string key = argv[1];

    // Validating key length
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // Validating key contains only alphabetical characters
    else if (!isAlpha(key))
    {
        printf("The key must contain only alphabetical characters\n");
        return 1;
    }
    // Validating key contains each letter exactly once
    else if (!isUniqueLetters(key))
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }
    else
    {
        string plaintext = get_string("plaintext: ");
        encrypt(plaintext, key);
        return 0;
    }
}

bool isAlpha(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        bool check = isalpha(key[i]);
        if (!check)
        {
            return false;
        }
    }
    return true;
}

bool isUniqueLetters(string key)
{
    // Convert key to uppercase for checking
    char upperKey[27];
    for (int i = 0; i < strlen(key); i++)
    {
        upperKey[i] = toupper(key[i]);
    }
    upperKey[strlen(key)] = '\0';

    // Check each letter A-Z appears exactly once
    for (char c = 'A'; c <= 'Z'; c++)
    {
        int count = 0;
        for (int i = 0; i < strlen(upperKey); i++)
        {
            if (upperKey[i] == c)
            {
                count++;
            }
        }
        if (count != 1)
        {
            return false;
        }
    }
    return true;
}

void encrypt(string plaintext, string key)
{
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        char letter = plaintext[i];

        // Change letter and print it directly
        if (islower(letter))
        {
            // Get position of letter in alphabet (0-25)
            int position = letter - 'a';
            // Print corresponding character from key (lowercase)
            printf("%c", tolower(key[position]));
        }
        else if (isupper(letter))
        {
            // Get position of letter in alphabet (0-25)
            int position = letter - 'A';
            // Print corresponding character from key (uppercase)
            printf("%c", toupper(key[position]));
        }
        else
        {
            // Non-alphabetical characters remain unchanged
            printf("%c", letter);
        }
    }
    printf("\n");
}
