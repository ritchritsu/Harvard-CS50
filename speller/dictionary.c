// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

const unsigned int N = 26;
int wordCount = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashValue = hash(word);
    node *cursor = table[hashValue];
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{

    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{

    // open dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }

    const int BUFFER_SIZE = 46;

    // creating buffer
    char *buffer = malloc(sizeof(char) * BUFFER_SIZE);
    if (buffer == NULL)
    {
        perror("Memory allocation failed");
        fclose(source);
        return 1;
    }

    // read strings from file one at a time
    while (fscanf(source, "%s", buffer) != EOF)
    {
        // create new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Malloc didnt work for word");
            free(buffer);
            return false;

        }
        // hash word to obtain hash value (using hash function)
        strcpy(n->word, buffer);
        int hashValue = hash(n->word);
        wordCount++;
        // insert node into hash table at that location
        n->next = table[hashValue];
        table[hashValue] = n;
    }

    free(buffer);
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{

    return wordCount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // free all nodes (go to hash table, call free on each node inside of the linked lists)
    for (int i = 0; i < N; i++)
    {
        node *head = table[i];
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }

    return true;
}
