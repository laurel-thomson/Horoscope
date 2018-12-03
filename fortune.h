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

char * get_fortune(int zodiac, int moon)
{
	//printf(" %s\n", fortunes[1][1]);
	//printf(" %d %d", zodiac, moon);
	return fortunes[moon][zodiac];
}

//this is hard-coded in for now as well - will need to read in from moon phases CSV
Moon get_moon(Date * date)
{
	if (date->day < 16) return NEW;
	return FULL;
}

//Code to read in from CSV file
void readFile(char * filename){
   if(filename == "" || filename == NULL){printf("No file name given\n");}
   else{
	strtok(filename, "\n");
	//printf("Creating fortune from default file: %s\n", filename);
	FILE * f = fopen(filename, "r");
   	char str[1024];

   	if(f == NULL){
	    printf("Error reading file\n");
	}
 	else{
	   for(int i = 1; i <= 2; i++){
	      for(int j = 1; j <= 12; j++){
	         fortunes[i][j] = malloc(sizeof(char) * 1024);
		 fgets(str, 1024, f);
		 char * input[3];
		 int n = 0;
	         for(char * token = strtok(str, ","); token != NULL; token = strtok(NULL, ",")){
		    input[n] = token;
		    n++;
		 }
	         fortunes[i][j] = input[2];
		 //printf("Fortune saved: %s\n", fortunes[i][j]);
	      }
	   }//printf("Fortunes saved: %s\n", fortunes[1][1]);
	}
   //printf("Fortunes saved:%s\n", fortunes[1][1]);
   fclose(f);
   //free(fortunes[1][1]);
   printf("Fortunes saved: %s\n", fortunes[1][1]);
   }
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
