/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"


int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc > 1)
    {
        printf("Usage: ./recover\n");
        return 1;
    }
    
    // remember filenames
    char* infile = "card.raw";
    
    // open input file   
    FILE* inptr = fopen(infile, "r");   
    if (inptr == NULL)
    {
        printf("Could not open %s\n", infile);
        return 2;
    }
        
    //open output file
    int number = 0;
    char outfile[10];
    sprintf(outfile, "file%i.jpg", number);
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        printf("Could not open %s\n", outfile);
        return 3;
    } 
    
    
    //store sequence
    char seq1 [4] = {0xff,0xd8,0xff,0xe0};
    char seq2 [4] = {0xff,0xd8,0xff,0xe1}; 
    
    //unsigned char temp[4];
    char buffer [512];
    int check = fgetc(inptr);
  
    do
    {   
        int count = 0;
        
        fread (buffer, sizeof(char), 512, inptr);
        
        // record position in file for checking of new jpg's
        fpos_t position;
        fgetpos (inptr, &position);
        
        // check for new jpg file
        for (int i = 0; i < 4; i++)
        {   
            if (buffer[i] == seq1[i] || buffer[i] == seq2[i])
                count++;
            
            if (count == 3)
            {
                number++;
            }                    
        }
        
        // create new file if new jpg file is found
        if (count == 3)
        {
            if (number > 0 && outptr != NULL)
                fclose(outptr);
            fsetpos (inptr, &position);  
             
            sprintf(outfile, "file%i.jpg", number);
            FILE* outptr = fopen(outfile, "w"); 

            fwrite(buffer, sizeof(char), 512, outptr);
        }
        
        // continue writing to file if no new jpg file is found        
        else if (count != 3 && outptr != NULL)
        {
            fwrite(&buffer, sizeof(char), 512, outptr);
        }
             
    } while (check != EOF);
    
    fclose (inptr);
           
}
