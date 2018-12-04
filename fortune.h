#ifndef FORTUNE
#define FORTUNE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Moon {
	NEW,
	FULL
} Moon;

char * fortunes[2][12];

char * get_fortune(Zodiac * zodiac, int moon)
{
	return fortunes[moon][zodiac->index];
}

boolean readFile(const char * filename){
	if (filename == NULL)
	{
		printf("\nNo file name given\n\n");
		return false;
	}

	FILE * f = fopen(filename, "r");
   	char str[1024];

   	if(f == NULL)
	{
	    printf("\nError reading file\n\n");
		return false;
	}
	
   for(int i = 0; i < 2; i++)
   {
		for(int j = 0; j <= 11; j++)
		{  
			fortunes[i][j] = malloc(sizeof(char) * 1024);
			fgets(str, 1024, f);
			strcpy(fortunes[i][j],str);
		}
   }
   fclose(f);
   return true;
}

//Method to free inputted fortune data
void freeData(){
   for(int i = 0; i < 2; i++){
     for(int j = 0; j< 12; j++){
     	free(fortunes[i][j]);
     }
   }
}
#endif
