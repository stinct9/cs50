#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[])
{   
    while (argc<2 || argc>2)
    {
        printf("Incorrect argument\n");
        return 1;
    }
    
    int keylen = strlen(argv[1]);
    char argkey[keylen];
    
    for (int z=0; z<keylen; z++)    //loop to store argument in an array called argkey
    {
        argkey[z]=argv[1][z];
    }
       
    for (int i=0; i<keylen; i++)
    {
        if (argkey[i]>'Z' && argkey[i]<'a')
        {
            printf("Incorrect argument\n");
            return 1;
        }
            
        if (argkey[i]>'z' || argkey[i]<'A')
        {
            printf("Incorrect argument\n");
            return 1;
        }
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
    
    for (int a=0; a<keylen; a++)    //loop to convert argv into an array of numbers and store in an another array called vkey
    {
        if (islower(argkey[a]))
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
        else if (isupper(argkey[a]))
        {
            for (int b=0; b<26; b++)
            {
                if (argkey[a]==uacase[b])
                {
                    vkey[a]=uaindex[b];
                    //printf("%i",vkey[a]);
                }
            }
        }       
    }
    
    string input = GetString();
    
    int w=0;
        
    for (int k=0; k<strlen(input); k++)     //loop to encrypt input string
    {
      if (isalpha(input[k]))
      {  
      
      if(isupper(input[k]))
      {
        for (int e=0; e<26; e++)
        {
            if (input[k]==uacase[e])
            {                
                int p = uaindex[e];
                
                int x = (p+vkey[w%keylen])%26;
                
                printf("%c", uacase[x]);
            }
        }
      }
      
      else
      {
         for (int e=0; e<26; e++)
        {
            if (input[k]==lcase[e])
            {                
                int p = lindex[e];
                int x = (p+vkey[w%keylen])%26;
                
                printf("%c", lcase[x]);
            }
        }
      }
      w++;
      }
      else 
      {
        printf("%c", input[k]);
      }
     }   
    
    printf("\n");
}
