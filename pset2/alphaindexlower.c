#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)
{   
    int lcase[26];  
    char lacase[26];
    int lindex[26];
    
    for (int a=0; a<26; a++)
    {
        int b = 'a'+a;
        //printf("%i ", b);       
        lcase[a]=b;
    }
    
    for (int b=0; b<26; b++)
    {
        lacase[b]=lcase[b];
        //printf("%c", uacase[b]);
    }
    
    for (int c=0; c<26; c++)
    {
        int alphanum = lcase[c]-97;
        lindex[c] = alphanum;
    }
    
    string alpha = GetString();
    
    for (int k=0; k<strlen(alpha); k++)
    {
        //printf("%c\n", alpha[k]+2);
        
        for (int d=0; d<26; d++)
        {
            if (alpha[k]==lacase[d])
            {
                printf("Index is %i & Alphabet is %c \n",lindex[d],alpha[k]);
                
            }
        }
    }
    
    printf("\n");
}
