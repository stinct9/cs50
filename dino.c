    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>

typedef struct dino
{
	int birth;
	int death;
} 
dino;

typedef struct timeline
{
	int startyr;
	int endyr;
	int alive;
} 
timeline;


int main()
{
	int count = 0;

	dino data [5] = {{-80000,-79950}, {20,70}, {22,60}, {58,65}, {1950,2004}};

	timeline yearbook[5];

	int n = 0;
	int j = 0;
	
	yearbook[n].startyr = -80000;		//assuming sorted list
    yearbook[n].endyr = -80000;
    int start = 0;
    

	for (int i = 0; i < 5; i++)
	{
		int next = 0;
		count = 0;
		int flag = 0;
	
		printf("Start YEAR %i ",yearbook[i].startyr);
		printf(" End YEAR %i\n",yearbook[i].startyr);
		
		if (i > 0)
		{
		    start = yearbook[n-1].endyr;
		}
		else if (i == 0)
		{
		    start = yearbook[n].endyr;
		}
        
        printf("Start = %i\n", start);
        
        j = start;
        
		while (next == 0 && j < 2005)
		{
			j++;
			
			for (int k = 0; k < 5; k++)
			{
			    if (j <= data[k].death && j >= data[k].birth)
			    {
			        count++;
			    }
            }

			if ( flag != count)
			{
				yearbook[n].endyr = start -1;
				yearbook[n].alive = count;
				next = 1;
			}
			
			flag = count;		
		}

		n++;
		
	}
	
	for (int i = 0; i < 5; i++)
	{
	    printf("1. %i\n",yearbook[i].startyr);
	}

}

