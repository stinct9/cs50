#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (void)
{
    string input = GetString();
    
    int l = strlen(input);
    
    int j=0;
    
    for (int i=0; i<l; i++)
    {
        if (input[i]>='A' && input[i]<='Z')
            j++;
        if (input[i]>='a' && input[i]<='z')
            j++;
        
    }
    
    printf("%i\n",j);
}
