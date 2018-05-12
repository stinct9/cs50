#include <stdio.h>
#include <cs50.h>

int main()
{ 
    int height=-1;
    
    while (height>23 || height<0)
        {
         printf("Height:"); 
         height =GetInt();
        }
   
    int h=0;
    int space=height+1;
    while (h<height)
    {
     printf("%*s",space,"##");
     int w=h;
        while (w>0)
        {
         printf ("#");
         w--;
        }
     h++;
     space--; 
     printf("\n");  
    }
 
}
