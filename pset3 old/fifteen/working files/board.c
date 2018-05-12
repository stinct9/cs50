#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int d = GetInt();
    int num = d*d;
    int board[d][d];
    
    for(int i=0; i<d; i++)
        for(int j=0; j<d; j++)
        {
            board[i][j]=num-1;
            num = num-1;
        }   
           
    if (d%2 == 0)
    {
        int c = board[d-1][d-2];
        board[d-1][d-2] = board[d-1][d-3];
        board[d-1][d-3] = c;
    }  
      
    for(int i=0; i<d; i++)
    {     
        for(int j=0; j<d; j++)
        {
            if (board[i][j]==0)
                printf("%2s","_");
            else
                printf("%2d ",board[i][j]);    
        }   
        
        printf("\n");        
    } 
               
}

