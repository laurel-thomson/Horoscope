#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "date.h"
#include "sign.h"
#include "fortune.h"

#define MAX_FILENAME_LENGTH 100

const char * DEFAULT_FORTUNE_FILE = "MoonPhaseFortunes.csv";
boolean isFirst = true;

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
				get_current_moon();
				break;
			case GET_ANY_MOON:
				get_any_moon();
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
	if (!isFirst) getchar();
	char c = getchar();
	isFirst = false;
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

		int moon_phase = moon_phase(current_date);

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

void get_current_moon()
{
	Date * current_date = get_current_date();
	//char *phase = convert_moon_phase_to_string(moon_phase(current_date));
	//printf("Today is %d/%d and it is a %s moon!\n",current_date->month->monthNumber,current_date->day,phase);
}

void get_any_moon()
{
	int month;
	printf("Enter a month as a number (example: May would be 5): ");
	scanf("%d", &month);

	int day;
	printf("Enter the the day of the month (example: 16): ");
	scanf("%d", &day);
	
	boolean is_valid = is_valid_date(month, day);

	if (is_valid)
	{
		Date * date = get_date(month, day);
		Date * current_date = get_current_date();
		//char *phase = convert_moon_phase_to_string(moon_phase(date));
		//printf("The moon phase for that day is %s",phase);
		free(date);
	}
	else printf("You have not entered a valid date!\n");
}
