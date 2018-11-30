#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "date.h"
#include "sign.h"
#include "fortune.h"
#include "moon.h"

#define MAX_FILENAME_LENGTH 100

const char * DEFAULT_FORTUNE_FILE = "MoonPhaseFortunes.csv";

int main() {

	printf("Welcome to your own personal ~~Fortune Teller~~\n\n");
	printf("Would you like to specify your own fortune CSV file? (y)es or (n): ");
	char c = getchar();

	if (c == 'y' || c == 'Y')
	{
		//read in from a csv of the user's choice
		char filename[MAX_FILENAME_LENGTH];
		printf("What file would you like to read from? ");
		scanf("%s",filename);
		readFile(filename);
	}
	else
	{
		//read in from the default file
		readFile(DEFAULT_FORTUNE_FILE);
	}

	while (true)
	{
		printf("Would you like to have your fortune told? (y)es or (n)o ");
		char a;
		scanf(" %c",&a);
		if (a == 'n' || a == 'N')
		{
			printf("Sorry to see you go!\n");
			break;
		}
		int birthmonth;
		printf("Enter the month of your birthday (example: May would be 5): ");
		scanf("%d", &birthmonth);

		int birthday;
		printf("Enter the day of your birthday (example: 16): ");
		scanf("%d", &birthday);

		boolean is_valid = is_valid_date(birthmonth, birthday);

		if (is_valid)
		{
			Date * birth_date = get_date(birthmonth, birthday, 2018); //get_date returns a Date* struct with the specified params
			Date * current_date = get_current_date();
			Zodiac * zodiac = get_sign(birth_date);

			printf("Your sign is a %s!\n", zodiac->name);

			//printf("Today is %d/%d and it is a %s moon!\n",current_date->month->monthNumber,current_date->day,moon_string);
			int your_moon = moon_phase(birth_date);
			char* your_moon_string = convert_moon_phase_to_string(your_moon);
			printf("The moon phase on your birthday this year is a %s!\n", your_moon_string);

			if (your_moon >= 0 && your_moon <= 4) your_moon = 0; //moon for fortune calc is new_moon
			else { your_moon = 1; } //moon is full for fortune calculation

			const char * fortune = get_fortune(zodiac, your_moon);
			printf("Your fortune is %s\n", fortune);

			free(birth_date);
			free(current_date);
			free(zodiac);
		}
		else printf("You have not entered a valid date!\n");
	}
	//call function to free fortune memory
	freeData();
	return 0;
}
