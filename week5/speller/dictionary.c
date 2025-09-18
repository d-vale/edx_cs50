// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 701;

// Hash table
node *table[N];

// Track how many words are loaded
static unsigned int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Find correct bucket using hash
    unsigned int idx = hash(word);
    node *ptr = table[idx];

    // Traverse linked list at that bucket
    while (ptr != NULL)
    {
        if (strcasecmp(ptr->word, word) == 0)
        {
            return true;
        }
        ptr = ptr->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Use first and last letter to spread words more evenly
    char first = toupper(word[0]);
    char last = toupper(word[strlen(word) - 1]);

    if (!isalpha(first))
    {
        return 0;
    }

    unsigned int h = ((first - 'A') * 27 + (last - 'A')) % N;
    return h;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (!file)
    {
        fprintf(stderr, "Could not open %s\n", dictionary);
        return false;
    }

    char buffer[LENGTH + 1];
    word_count = 0;

    while (fscanf(file, "%45s", buffer) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (!new_node)
        {
            fclose(file);
            return false;
        }

        strcpy(new_node->word, buffer);

        unsigned int index = hash(buffer);
        new_node->next = table[index];
        table[index] = new_node;

        word_count++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *trav = table[i];
        while (trav != NULL)
        {
            node *temp = trav;
            trav = trav->next;
            free(temp);
        }
    }
    return true;
}
