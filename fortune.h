#ifndef FORTUNE
#define FORTUNE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Moon {
	NEW,
	FULL
} Moon;

//the fortunes are hard-coded in for now - will need to update this to read from a CSV
const char * fortunes[2][12];

const char * get_fortune(Zodiac * zodiac, Moon moon)
{
	return fortunes[moon][zodiac->index];
}

//this is hard-coded in for now as well - will need to read in from moon phases CSV
Moon get_moon(Date * date)
{
	if (date->day < 16) return NEW;
	return FULL;
}

//Code to read in from CSV file
void readFile(char * filename){
   FILE * f = fopen(filename, "r");
   char buf[1024];

   if(f == NULL){
	printf("Error reading file\n");
   }
   else{
	for(int i = 1; i <= 2; i++){
	  for(int j = 1; j <= 12; j++){
	    fortunes[i][j] = malloc(sizeof(char) * 1024);
	    strcpy(fortunes[i][j], buf);
	  }
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
