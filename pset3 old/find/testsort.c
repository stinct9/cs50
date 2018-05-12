#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int haystack[5];
    
    for(int i = 0; i < 5; i++)
    {
        printf("Haystack %d is: ", i+1);
        int straw = GetInt();
        
        haystack[i] = straw;
    }
    
    for(int i=0; i < 5; i++)
    {
        for(int i = 1; i < 5; i++)
        {
            int temp = haystack[i-1];        
            if (haystack[i] < haystack[i-1])
            {
                haystack[i-1] = haystack[i];
                haystack[i] = temp;
            }
        }
    }
    
     for(int i = 0; i < 5; i++)
        printf("%d\n",haystack[i]);
    
}
