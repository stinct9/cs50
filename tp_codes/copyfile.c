#include<stdio.h>

int main()
{
    FILE* infile = fopen("m1.txt", "r");
    
    if (infile == NULL)
        return 1;
    
    FILE* outfile = fopen("outfile.txt", "w");
    
    if (outfile == NULL)
        return 1;
    
    int ch;
    
    do
    {
        ch = getc(infile);
    
        putc(ch, outfile);
    } while (ch != EOF);
    
    fclose(infile);
    fclose(outfile);
    
    
}
