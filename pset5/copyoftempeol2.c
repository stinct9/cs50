    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>

/* ################################################# STRUCT DEF ################################################################## */     
    typedef struct node     //struct for linked list
    {
        char* word;
        struct node* next;
    }
    node;
 
 /* ################################################# FUNCTIONS ################################################################## */   
    int findhash(int wordlen)      //this function returns a hash value for first alphabet of every word
    {
        int hash = 0;
        hash =wordlen-1;                 
        return hash;       
    }
    
    void init_table(node* hashtable[])      
    {
        for(int i = 0; i < 26; i++)
            hashtable[i] = NULL;
    }
    
    void printlist(node* hashtable[])
    {
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
    }
    
    void freehashtable(node* hashtable[])
    {
        for (size_t i=0; i<26; ++i)     //free all memory
        {
            while (hashtable[i])
            {
                node *temp = hashtable[i];
                hashtable[i] = temp->next;
                free(temp->word);
                free(temp);
            }
        }  
    }
    
    void lowercase(char word[], int length)
    {      
        for(int i = 0; i < length; i++)
        {
            if(word[i] >=65 && word[i] <= 90)
                word[i] = word[i] + 32;
        }       
    }
    
    void read_dictionary(FILE* dict, char oneword[], node* hashtable[])
    {       
        while ((fscanf (dict, "%s", oneword)) > 0)      //2.While (true)
        {                                                    
            int length = strlen(oneword);
            
            node* temp = malloc(sizeof(node));       //3. Create a node pointer temp and allocate memory for it                        
            temp->word = malloc(sizeof(char)*length+1);     //new!            
            
            lowercase(oneword, length);
            strcpy(temp->word, oneword);        //improvement by eliminating use of char* firstword
            
            temp->next = NULL;
                   
            int hash = findhash(length);      //returns an index for the first alphabet of the word                  
                      
            //printf("%s\n", temp->word);     //prints the value (just for debug)
            while(hashtable[hash] != NULL)
            {
                hashtable[hash] = hashtable[hash]->next;
            }
            
            hashtable[hash] = temp;                       
        }             
    }
    
/* ################################################# FUNCTIONS END :: MAIN START ################################################################## */    
    int main (void)
    {            
        char* dictfile = "large";
        char* checkfilename = "austinpowers.txt";
        
        FILE* dict = fopen(dictfile, "r");        
        FILE* checkfile = fopen(checkfilename, "r");
        
        if (dict == NULL)
            return 1;
        
        char oneword[47];      //to store the word from fscanf()
        char checkword[47];
        
        node* hashtable [26];       //1. creates a hashtable
        
        init_table(hashtable);      //1. initialize hashtable to NULL
        
        read_dictionary(dict, oneword, hashtable);      

        //printlist(hashtable);
        
        int count = 0;      //to count the number of misspelled words
        
           
        char c; 
        int i = 0;
                   
        while(EOF != (c = fgetc(checkfile))) 
        {               
            if(c == ' ' || c == '\n' || c == '\0' || c == '\t' || c == '!' || c == '.' || c == ',' || c == '?' || c == ')' || c == ':' || c == '-' || c == '(' || c =='&')
            {
                checkword[i] = '\0';
                i = 0;
                //printf("%s :: Scanned word\n", checkword);
                  
                int flag = 0;
                int wordlen = strlen(checkword);
                int hash1 = findhash(wordlen);
                //printf("%d\n",hash1);
            
                if (hash1 >= 0)     //hash returns -1 for all words starting with non-alphabets
                {
                    int length1 = strlen(checkword)+1;
           
                    lowercase(checkword, length1);
            
                    node* traverse = hashtable[hash1];
            
                    while (traverse != NULL && flag == 0)    //loop to print the linked list
                    {           
                        if (strcmp(traverse->word, checkword) == 0)
                        {
                            //printf("Word found in Dictionary\n");
                            flag = 1;
                            break;
                        }                
                        traverse = traverse->next;
                    }                
            
                    if(flag == 0)
                    {                       
                        printf("%s :: Not found in dictionary\n", checkword);
                        count++;
                    }
                }
            }
            else
            {
                checkword[i] = c;
                i++;
            }
        }      
       
        freehashtable(hashtable);

        printf("\n");
        printf("%d\n", count);
        
        fclose(dict);
        fclose(checkfile);
        
        printf("SUCCESS!!\n");      
   
    }   
/* ################################################# PROGRAM ENDS ################################################################## */ 
