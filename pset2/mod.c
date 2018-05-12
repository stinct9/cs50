#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (int argc, string argv[])
{  
    int keylen = strlen(argv[1]);
    
    printf("%i\n",keylen);
    
    char argkey[keylen];
    
    for (int z=0; z<keylen; z++)
    {
        argkey[z]=argv[1][z];
    }
    
    int ucase[26];  
    char uacase[26];
    int uaindex[26];    
        
    for (int a=0; a<26; a++)
    {
        int b = 'A'+a;
        //printf("%i ", b);       
        ucase[a]=b;
    }
    
    for (int b=0; b<26; b++)
    {
        uacase[b]=ucase[b];
    }    
    
    for (int c=0; c<26; c++)
    {
        int alphanum = ucase[c]-65;
        uaindex[c] = alphanum;
    }

    int lcase[26];  
    char lacase[26];
    int lindex[26];
    
    for (int a=0; a<26; a++)    //an array of int which says int 0 is equal to int 97
    {
        int b = 'a'+a;
        //printf("%i ", b);       
        lcase[a]=b;
    }
    
    for (int b=0; b<26; b++)    //an array of int which says char 0 is equal to ascii 97
    {
        lacase[b]=lcase[b];
        //printf("%c", uacase[b]);
    }
    
    for (int c=0; c<26; c++)    //an array of int which says int 97 is equal to 0
    {
        int alphanum = lcase[c]-'a';
        lindex[c] = alphanum;
    } 
    
    char vkey[keylen];
    
    for (int a=0; a<keylen; a++)
    {
        if (islower(argkey[a])
        {
            for (int b=0; b<26; b++)
            {
                if (argkey[a]==lacase[b])
                {
                    vkey[a]=lindex[b];
                    //printf("%i",vkey[a]);
                }
            }
        }
        else if (isupper(argkey[a])
        {
            for (int b=0; b<26; b++)
            {
                if (argkey[a]==uacase[b])
                {
                    vkey[a]=uindex[b];
                    //printf("%i",vkey[a]);
                }
            }
        }       
    }
    
    
    
}   
