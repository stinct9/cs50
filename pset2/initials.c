#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    string name = GetString();
    int i=strlen(name);
        
    //printf("The number of characters is: %i\n", i);
    
    for (int x=0; x<i; x++)
    {
        if(x==0)
            printf("%c", toupper(name[x]));
        else if (name[x]==32)
            printf("%c", toupper(name[x+1]));
        
    } 
    
    printf("\n");

}
