#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
typedef struct node
{
    char* word;
    struct node* next;
} node;
 
size_t findhash(char firstletter)
{
    size_t hash = 0;
   
    if(isupper(firstletter))
        hash = firstletter-'A';
    else hash = firstletter-'a';
   
    return hash;
}
 
int main (void)
{
    static const size_t H_SIZE = 30;
   
    node* hashtable[H_SIZE];
    memset(hashtable, 0, sizeof(hashtable));
   
    FILE* dict = fopen("small", "r");
    if (dict == NULL)
        return 1;
   
    char oneword[47];
    while ((fscanf (dict, "%46s", oneword)) > 0)
    {
        size_t slen = strlen(oneword);
        node* temp = malloc(sizeof *temp);
        if (temp != NULL)
        {
            temp->word = malloc(slen+1);
            if (temp->word != NULL)
            {
                memcpy(temp->word, oneword, slen+1);
                size_t hash = findhash(oneword[0]) % H_SIZE;
                temp->next = hashtable[hash];
                hashtable[hash] = temp;
            }
            else
            {
                perror("Failed to allocate string for new node");
                free(temp);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            perror("Failed to allocate  new node");
            exit(EXIT_FAILURE);
        }
    }
   
    for (size_t i = 0; i < H_SIZE; i++)
    {
        const node *temp = hashtable[i];
        while (temp != NULL)
        {
            if (temp->word != NULL)
            {
                printf("%s\n", temp->word);
                temp = temp->next;
            }
        }
    }
   
    for (size_t i=0; i<H_SIZE; ++i)
    {
        while (hashtable[i])
        {
            node *tmp = hashtable[i];
            hashtable[i] = tmp->next;
            free(tmp->word);
            free(tmp);
        }
    }
   
    printf("\n");
    fclose(dict);
   
    printf("SUCCESS!!\n");      
   
}
