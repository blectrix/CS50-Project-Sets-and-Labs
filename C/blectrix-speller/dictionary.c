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
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Declare variables
unsigned int word_count;
unsigned int hash_value;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Declare variables
    int len = strlen(word);
    char lword[len + 1];

    // Make word lower case for hash function
    for (int i = 0; i < len; i++)
    {
        lword[i] = tolower(word[i]);
    }

    lword[len] = '\0';

    hash_value = hash(lword);
    node *cursor = table[hash_value];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) != 0)
        {
            cursor = cursor->next;
        }
        else
        {
            return true;
        }

    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long total = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        total += tolower (word[i]);
    }
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open dictionary
    FILE *file = fopen(dictionary, "r");

    // If can't open file malloc return NULL, return false
    if (file == NULL)
    {
        printf("Unable to open %s\n", dictionary);
        return false;
    }

    // Decalare variable called word
    char word[LENGTH + 1];

    // Scans dictionary word by word (populating hash table with nodes containing words found in dictionary)
    while (fscanf(file, "%s", word) != EOF)
    {
        // Mallocs a node for each new word (i.e., creates node pointers)
        node *new_node = malloc(sizeof(node));

        // Checks if malloc succeeded, returns false if not
        if (new_node == NULL)
        {
            unload();
            return false;
        }

        // Copies word into node if malloc succeeds
        strcpy(new_node->word, word);

        // Initializes & calculates index of word for insertion into hashtable
        hash_value = hash(word);

        // Initializes head to point to hashtable index/bucket
        new_node->next = table[hash_value];

        // Inserts new nodes at beginning of lists
        table[hash_value] = new_node;
        word_count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (word_count > 0)
    {
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    //free list from each array element
    for (int i = 0; i < N; i++)
    {

        node *cursor = table[i];

        //free list from head element table[i]
        while (cursor != NULL)
        {

            //tmp hold variable so cursor can move down list before free
            node *tmp = cursor;

            //point to next link
            cursor = cursor -> next;

            free(tmp);
        }
        if (cursor == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
