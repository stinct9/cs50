#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)
{   
    int ucase[26];  
    char uacase[26];
    int aindex[26];
    
    for (int a=0; a<26; a++)
    {
        int b = 'A'+a;
        //printf("%i ", b);       
        ucase[a]=b;
    }
    
    for (int b=0; b<26; b++)
    {
        uacase[b]=ucase[b];
        //printf("%c", uacase[b]);
    }
    
    for (int c=0; c<26; c++)
    {
        int alphanum = ucase[c]-65;
        aindex[c] = alphanum;
    }
    
    string alpha = GetString();
    
    for (int k=0; k<strlen(alpha); k++)
    {
        //printf("%c\n", alpha[k]+2);
        
        for (int d=0; d<26; d++)
        {
            if (alpha[k]==uacase[d])
            {
                printf("Index is %i & Alphabet is %c \n",aindex[d],alpha[k]);
                
            }
        }
    }
    
    printf("\n");
}
