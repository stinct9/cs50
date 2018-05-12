#include <math.h>
#include <stdio.h>
#include <cs50.h>


int main (void)
{
 float money=-1;
 int x;
 int i=0;

 while (money<0)
 { printf("How much change is owed?\n");
   money = GetFloat();
 }
 
 if (money>0)
 money=money*100;
 
 x = round(money);
 
 
    while (x>25 || x==25)
    { x=x-25;
      i++;
      }
    
    while (x>10 || x==10)
    { x=x-10;
      i++;
      }
    
    while (x>5 || x==5)
    { x=x-5;
      i++;
      }
    
    while (x>0 || x==1)
    { x=x-1;
      i++;
      }  
     
     printf("%i\n",i); 
           
}
