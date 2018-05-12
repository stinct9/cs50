#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long long int num;
    long long int i;
    
    do
    {   i=0;
        printf("Number:");
        num = GetLongLong();       
        
        while (num>0)
        {   num=num/10;
            i++;
        }       
    } while ( (i!=13) && (i!=15) && (i!=16) );
    
     
    printf("The number of digit/s are/is:%lld\n",i);

}
