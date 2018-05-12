 /****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "dictionary.h"


typedef struct node
{
    char word[LENGTH+1];
    struct node* next;
}
node;

node* hashtable [LENGTH+1];
int mispelledwordcount = 0;
int dictcount = 0;

/*################ OWN FUNCTION START ##################*/
    int findhash(int wordlen)      //this function returns a hash value for first alphabet of every word
    {
        int hash = wordlen - 1;               
        return hash;       
    }
    
    void lowercase(char word[], int length)
    {      
        for(int i = 0; i < length; i++)
        {
            if(word[i] >=65 && word[i] <= 90)
                word[i] = word[i] + 32;
        }       
    }
    
    void init_table(node* hashtable[])      
    {
        for(int i = 0; i < 26; i++)
            hashtable[i] = NULL;
    }
/*################ OWN FUNCTION END ###################*/

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
                int flag = 0;
                int wordlen = strlen(word);
                //printf("%d\n",hash1);
                char checkword[wordlen+1];
                strcpy(checkword, word);
                int hash1 = findhash(wordlen);               
            
                if (hash1 >= 0)     //hash returns -1 for all words starting with non-alphabets
                {
                    int length1 = strlen(checkword)+1;           
                    lowercase(checkword, length1);
                    node* traverse = hashtable[hash1];
            
                    while (traverse != NULL && flag == 0)    //loop to print the linked list
                    {           
                        if (strcmp(traverse->word, checkword) == 0)
                        {
                            //printf("Word found in Dictionary\n");
                            flag = 1;
                            break;
                        }                
                        traverse = traverse->next;
                    }                
            
                    if(flag == 0)
                    {                       
                        //printf("%s :: Not found in dictionary\n", checkword);
                        mispelledwordcount++;
                    }
                }
    if(flag == 1)       //means found in dictionary
        return true;
    
    else return false;      //means not found in dictionary
}

/**
 * Loads dictionary into memory.  Returns true if successful enlse false.
 */
bool load(const char* dictionary)
{
    // TODO    
    FILE* dict = fopen(dictionary, "r");   
    char oneword[LENGTH+1];
    init_table(hashtable);
    
    while ((fscanf (dict, "%s", oneword)) > 0)      //2.While (true)
    {                                                    
        int length1 = strlen(oneword)+1;
            
        node* temp = malloc(sizeof(node));       //3. Create a node pointer temp and allocate memory for it                        
        //temp->word = NULL;     //new!            
            
        lowercase(oneword, length1);
        strcpy(temp->word, oneword);        //improvement by eliminating use of char* firstword 
                   
        int hash = findhash(length1-1);      //returns an index for the first alphabet of the word                  
                      
        temp->next = NULL;
        
        //printf("%s\n", temp->word);     //prints the value (just for debug)
        while (hashtable[hash]->next != NULL)
                hashtable[hash] = hashtable[hash]->next;
        
        hashtable[hash]->next = temp;
        dictcount++;                              
    } 
            
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO   
    return dictcount;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    
        for (size_t i = 0; i < 26; i++)     //free all memory
        {
            while (hashtable[i])
            {
                node *temp = hashtable[i];
                hashtable[i] = temp->next;
                free(temp);
            }
        }
    
    return true;
}
