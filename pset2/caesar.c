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
        
        
    int ucase[26];  
    char uacase[26];
    int uaindex[26];
    
    int key = atoi(argv[1]);
    
    while (key==0)
        return 1;
        
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
    
    
    string input = GetString();
    
    for (int k=0; k<strlen(input); k++)
    {

      if(isupper(input[k]))
      {
        for (int e=0; e<26; e++)
        {
            if (input[k]==uacase[e])
            {                
                int p = uaindex[e];
                int x = (p+key)%26;
                
                printf("%c", uacase[x]);
            }
        }
      }
      
      else if(islower(input[k]))
      {
         for (int e=0; e<26; e++)
        {
            if (input[k]==lcase[e])
            {                
                int p = lindex[e];
                int x = (p+key)%26;
                
                printf("%c", lcase[x]);
            }
        }
      }
      
      else printf("%c", input[k]);
     }   
    
    printf("\n");
}
