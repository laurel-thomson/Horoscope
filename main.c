#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "date.h"
#include "sign.h"
#include "fortune.h"

#define MAX_FILENAME_LENGTH 100

const char * DEFAULT_FORTUNE_FILE = "MoonPhaseFortunes.csv";

typedef enum FortuneTellerState {
	TELL_FORTUNE,
	UPLOAD_CSV,
	GET_CURRENT_MOON,
	GET_ANY_MOON,
	QUIT
} FortuneTellerState;

FortuneTellerState state;

int main() {
	//read in the fortunes from the default file in case the user doesn't specify a file to read from
	readFile(DEFAULT_FORTUNE_FILE);
	
	printf("Welcome to your own personal ~~Fortune Teller~~\n\n");
	while(state != QUIT)
	{
		print_menu();
		switch(state)
		{
			case TELL_FORTUNE:
				tell_fortune();
				break;
			case UPLOAD_CSV:
				upload_csv();
				break;
			case GET_CURRENT_MOON:
				//todo: get current moon
				printf("Getting current moon...");
				break;
			case GET_ANY_MOON:
				//todo: get any moon
				printf("Getting any moon...");
				break;
			default:
				break;
		}
	}

	freeData();
	return 0;
}

void print_menu()
{
	printf("Choose one of the menu options: \n\n"
			"---------(1)Have your fortune told\n"
			"---------(2)Get the current moon phase\n"
			"---------(3)Get the moon phase of any day\n"
			"---------(4)Upload a fortune csv file\n"
			"---------(5)Quit\n");
	getchar();
	char c = getchar();
	switch(c)
	{
		case '1':
			state = TELL_FORTUNE;
			break;
		case '2':
			state = UPLOAD_CSV;
			break;
		case '3':
			state = GET_CURRENT_MOON;
			break;
		case '4':
			state = GET_ANY_MOON;
			break;
		case '5':
			state = QUIT;
			break;
		default:
			printf("Invalid choice!\n");
			break;
	}
}

void tell_fortune()
{
	int birthmonth;
	printf("Enter the month of your birthday (example: May would be 5): ");
	scanf("%d", &birthmonth);

	int birthday;
	printf("Enter the day of your birthday (example: 16): ");
	scanf("%d", &birthday);

	boolean is_valid = is_valid_date(birthmonth, birthday);

	if (is_valid)
	{
		Date * birth_date = get_date(birthmonth, birthday);
		Date * current_date = get_current_date();
		Zodiac * zodiac = get_sign(birth_date);

		printf("Your sign is a %s!\n", zodiac->name);

		Moon moon = get_moon(current_date);

		char * moon_string;

		if (moon == 0)
		{
			moon_string = "new";
		}
		else
		{
			moon_string = "full";
		}

		printf("Today is %d/%d and it is a %s moon!\n",current_date->month->monthNumber,current_date->day,moon_string);

		const char * fortune = get_fortune(zodiac, moon);
		printf("Your fortune is %s\n", fortune);

		free(birth_date);
		free(current_date);
		free(zodiac);
	}
	else printf("You have not entered a valid date!\n");
}

void upload_csv()
{
	char filename[MAX_FILENAME_LENGTH];
	printf("What file would you like to read from? ");
	scanf("%s",filename);
	readFile(filename);
}
