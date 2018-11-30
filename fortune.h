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

char * test_get_fortune(int x, int y)
{
	return fortunes[x][y];
}

char * get_fortune(Zodiac * zodiac, int moon)
{
	return fortunes[moon][zodiac->index];
}

void readFile(char * filename){
	if (filename == "" || filename == NULL)
	{
		printf("No file name given\n");
		return;
	}

	FILE * f = fopen(filename, "r");
   	char str[1024];

   	if(f == NULL)
	{
	    printf("Error reading file\n");
		return;
	}
	
   for(int i = 0; i < 2; i++)
   {
		for(int j = 0; j <= 11; j++)
		{  
			fortunes[i][j] = malloc(sizeof(char) * 1024);
			fgets(str, 1024, f);
			strcpy(fortunes[i][j],str);
			printf("x: %d, y: %d\n %s\n\n",i,j, fortunes[i][j]);
		}
   }
   fclose(f);
}

//Method to free inputted fortune data
void freeData(){
   for(int i = 1; i <= 2; i++){
     for(int j = 1; j<= 12; j++){
     	free(fortunes[i][j]);
     }
   }
}
#endif
