
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main (int argc, char* argv[])
{
    //check proper usage
    if (argc < 3)
    {
        printf ("Usage: ./whodunit infile outfile\n");
        return 1;
    }
    
    //remember file names
    char* infile = argv[1];
    char* outfile = argv[2];
    
    //open infile
    FILE* inptr = fopen (infile, "r");
    
    if (inptr == NULL)
    {
        printf ("Could not open file.\n");
        return 1;
    }
    
    //open outfile
    FILE* outptr = fopen (outfile, "w");
    
    if (outptr == NULL)
    {
        printf ("Could not create file.\n");
        fclose (inptr);
        return 1;
    }
    
    //read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread (&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    
    //read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread (&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    //check if infile is BMP 24bit uncompressed
       
    
    //write outfile's BITMAPFILEHEADER
    fwrite (&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    
    //write outfile's BITMAPINFOHEADER
    fwrite (&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    //determine paddings
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4; 
    
    //copy scanlines
    for (int i = 0,  biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for (int j = 0; j < bi.biWidth; j++)
        {
            RGBTRIPLE triple;
            
            fread (&triple, sizeof(RGBTRIPLE), 1, inptr);
            
            // define a color for filter
            RGBTRIPLE filter;
            filter.rgbtBlue = 0x00;
            filter.rgbtGreen = 0x00;
            filter.rgbtRed = 0x00;
            
            // filter out the Red and White color with the filter
            if (triple.rgbtGreen == 0x00 && triple.rgbtBlue == 0x00 && triple.rgbtRed == 0xff)
                triple = filter;
            
            if (triple.rgbtGreen == 0xff && triple.rgbtBlue == 0xff && triple.rgbtRed == 0xff)
                triple = filter;
          
            fwrite (&triple, sizeof(RGBTRIPLE), 1, outptr);
        }
        
        fseek (inptr, padding, SEEK_CUR);
        
        for (int k = 0; k < padding; k++)
            fputc (0x00, outptr);
    }

    
    fclose (outptr);
        fclose (inptr);
    
    return 0;
            
}
