/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./resize infile outfile\n");
        return 1;
    }

    // remember filenames
    char* infile = argv[1];
    char* outfile = argv[2];
    int size = 1;

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // new file's BITMAPFILEHEADER
    BITMAPFILEHEADER bfre;
    bfre = bf;
    bfre.bfSize = 54 + (bf.bfSize-54)*size;
    
    //new file's BITMAPINFOHEADER
    BITMAPINFOHEADER bire;
    bire = bi;
    bire.biHeight = bi.biHeight*size;
    bire.biWidth = bi.biWidth*size;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bfre, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bire, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // determine padding for resized file scanlines
    int repadding =  (4 - (bire.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //length of pixels with padding
    //int length = -(bi.biWidth+padding);
    
    RGBTRIPLE pixels[bi.biHeight][bi.biWidth];
    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {   
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                pixels[i][j] = triple;
            
                                                           
            }       
            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);       
    }
    
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {   
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                fwrite(&pixels[i][j], sizeof(RGBTRIPLE), 1, outptr);
            
                                                         
            }  
                        // then add it back (to demonstrate how)
            for (int k = 0; k < repadding; k++)
            {
                fputc(0x00, outptr);
            }    
     
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
