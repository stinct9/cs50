    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    typedef struct node
    {
        char* word;
        struct node* next;
    }
    node;  
    
    int main (int argc, char* argv[])
    {
        
        FILE* dict = fopen(argv[1], "r");
        if (dict == NULL)
            printf("ERROR: Could not open dictionary file");
        
        node* start = NULL;
               
        char* oneword = malloc(sizeof(node));       
        
        while ((fscanf (dict, "%s", oneword))>0)
        {        
            //printf("%s \n", read);             
            node* temp = (node*)malloc(sizeof(node));
            node* current = (node*)malloc(sizeof(node));
            char* tempword = malloc(sizeof(char));
            
            strcpy(tempword, oneword);
             
            temp->word = tempword;
            
            if (start == NULL)
            {               
                temp->next = NULL;
                start = temp;
            }
            else
            {
                    current = start;
                    while (current->next != NULL)
                    {
                        current = current->next;
                    }
                    
                    current->next = temp;
                    temp->next = NULL;                
            } 
        }
        
        node* traverse = start;
        int count = 0;
        
        while(traverse->next != NULL)
        {           
            printf("%s\n", traverse->word);
            traverse = traverse->next;
            count++;
        }
        
        printf("Number of words in the dictionary is %d\n", count);
        
        free(traverse);
                
            
        FILE* check = fopen(argv[2], "r");
        if (check == NULL)
            printf("ERROR: Could not open file to be checked");
            
        fclose(dict);
        fclose(check);
        
        printf("SUCESS!!\n");      
        
    }    

