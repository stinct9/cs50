nclude <stdio.h>
#include <cs50.h>
int main(void)
{
       float money; 
       int quarters, dimes, nickels, pennies ;
       // propmts the user to give input
           do
           {
                   printf ("o hai! How much change is owed?");
                   money = GetFloat();
               }
       while (money < 0);
       
           // counting the no. of coins
           money = money * 100;
       quarters = money / 25; 
       money = money - (25 * quarters);
       dimes = money / 10;
       money = money - (10 * dimes);
       nickels = money / 5;
       money = money - (5 * nickels);
       pennies = money;    
           
           printf("%d\n",pennies + nickels + dimes + quarters);
       
           
               
}
