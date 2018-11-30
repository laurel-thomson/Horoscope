#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "date.h"
#include "sign.h"
#include "fortune.h"

#define MAX_FILENAME_LENGTH 100

char * DEFAULT_FORTUNE_FILE = "MoonPhaseFortunes.csv";

int main() {
	
	readFile(DEFAULT_FORTUNE_FILE);
	
	while (true)
	{
		int x;
		printf("Enter x: ");
		scanf(" %d",&x);
		
		int y;
		printf("Enter y: ");
		scanf(" %d",&y);
		
		char * fortune = test_get_fortune(x,y);
		
		printf("%s\n",fortune);
	}
	freeData();
	return 0;
}
