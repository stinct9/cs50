#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

int main (void)
{
    int haystack[5];
    
    for(int i = 0; i < 5; i++)
    {
        printf("Haystack %d is: ", i+1);
        int straw = GetInt();
        
        haystack[i] = straw;
    }

    int n = 5;

    sort(haystack, n);
    
    for(int i = 0; i < 5; i++)
        printf("%d\n",haystack[i]);   

}
