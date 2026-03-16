
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;


const unsigned int N = 26;

node *table[N];

unsigned int word_count = 0;


bool check(const char *word)
{
    
    unsigned int index = hash(word);
    
    
    node *cursor = table[index];
    
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    
    return false;
}

unsigned int hash(const char *word)
{
    
    return toupper(word[0]) - 'A';
}


bool load(const char *dictionary)
{
   
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }
    
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    
    char word[LENGTH + 1];
    while (fscanf(source, "%s", word) == 1)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(source);
            return false;
        }
        
        strcpy(new_node->word, word);
        new_node->next = NULL;
        
    
        unsigned int index = hash(word);
        
        new_node->next = table[index];
        table[index] = new_node;
        
        
        word_count++;
    }
    
    fclose(source);
    return true;
}

unsigned int size(void)
{
    return word_count;
}

bool unload(void)
{

    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        table[i] = NULL;
    }
    
    return true;
}