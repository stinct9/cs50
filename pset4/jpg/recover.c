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
        
    //open output file
    int number = 000;
    char outfile[16];
    sprintf(outfile, "%03d.jpg", number);
    FILE* outptr = fopen(outfile, "w");    
  
    unsigned char buffer[512];
    unsigned char jpeg[5] = {0xFF, 0xD8, 0xFF, 0xE0, 0xE1};
    
    while ((fread(&buffer, 512, 1, inptr)) > 0)
    {                              
        if (buffer[0] == jpeg[0] && buffer[1] == jpeg[1] && buffer[2] == jpeg[2])
        {
            if (buffer[3] == jpeg[3] || buffer[3] == jpeg[4])
            {
                fclose(outptr);         
                sprintf(outfile, "%03d.jpg", number);
                outptr = fopen (outfile, "w");
                number++;                    
            }               
         }

        if (number > 0)
            fwrite (&buffer, sizeof(buffer), 1, outptr);
    }
    
    fclose (inptr);
    fclose (outptr);          
}
