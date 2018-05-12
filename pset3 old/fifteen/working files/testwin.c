#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int d = GetInt();
    int num = 1;
    int board[d][d];
    int start = 1;
    int tally = (d*d)-1;
       
    
    for(int i=0; i<d; i++)
        for(int j=0; j<d; j++)
        {
            board[i][j]=num;
            num = num+1;
        }   
    
    board[d-1][d-1]=0;
    
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
    
    for(int i=0; i<d; i++)
    {
        for(int j=0; j<d; j++)
        {
            if(board[i][j]==start)
                start++;
            
            if(i==d-1 && j==d-1)
                start--;  
                
        }
  
    }

    if(start==tally)
        printf("YOU HAVE WON!!\n    %d", start);

    else
        printf("YOU HAVE LOST\n     %d", start);

}
