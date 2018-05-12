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
    int number = 0;
    char outfile[16];
    sprintf(outfile, "file%i.jpg", number);
    FILE* outptr = fopen(outfile, "w");    
       
    unsigned int buffer [512];
    
    while ((fread(&buffer, 512, 1, inptr)) > 0)
    {                              
        if (buffer[0] == 0xff)
            if (buffer[1] == 0xd8)
                if (buffer[2] == 0xff)
                    if (buffer[3] == 0xe0 || buffer[3] == 0xe1)
                    {
                        fclose(outptr);                        
                        sprintf(outfile, "file%i.jpg", number);
                        outptr = fopen (outfile, "w");
                        number++;                      
                    }

      if (number > 0)
          fwrite (&buffer, 512, 1, outptr);
    }
    
    fclose (inptr);
    fclose (outptr);
           
}
