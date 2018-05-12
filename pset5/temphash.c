    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    
    typedef struct node     //struct for linked list
    {
        char word[47];
        struct node* next;
    }
    node;
    
    int findhash(char firstletter)      //this function returns a hash value for first alphabet of every word
    {
        int hash = 0;
        
        if(isupper(firstletter))
            hash = firstletter-'A';
        else hash = firstletter-'a';

        return hash;       
    }
    
    int main (void)
    {            
        char* dictfile = "small";
        
        FILE* dict = fopen(dictfile, "r");
        
        if (dict == NULL)
            return 1;
        
        //char oneword[47];      //to store the word from fscanf()
        
        node* hashtable [26];       //creates a hashtable        
        
        for (int i = 0; i < 26; i++)        //gives an index to every element in the hash table
        {
            node* temp = (node*)malloc(sizeof(node));
            temp->next = NULL;           
            hashtable[i] = temp;
        } 
        
        while ((fscanf (dict, "%s", oneword)) > 0)
        {                                        
            node* temp = (node*)malloc(sizeof(node));            
            char* tempword = (char*)malloc(strlen(oneword)+1); //gives me a new pointer to store the string (as pointed out by Antione)            
            strcpy(tempword, oneword);
            
            char firstletter = tempword[0];
                    
            int hash = 0;
            hash = findhash(firstletter);      //returns an index for the first alphabet of the word                  
            temp->word = tempword;
                       
            //printf("%s\n", temp->word);     //prints the value (just for debug)

            temp->next = hashtable[hash];            
            hashtable[hash] = temp;                       
        }
       
        for (int i = 0; i < 26; i++)
        {           
            node* traverse = hashtable[i];
            
            while (traverse != NULL)    //loop to print the linked list
            {           
                if (traverse->word > 0)
                    printf("%s\n", traverse->word);
                
                traverse = traverse->next;  
            }  
        }

        printf("\n");
        
        fclose(dict);
        
        printf("SUCCESS!!\n");      
   
    }    

