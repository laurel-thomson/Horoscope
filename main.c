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
		printf("Would you like to have your fortune told? (y)es or (n)o: ");
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

			char * fortune = get_fortune(1,1); //Try calling getfortune(#,#)
			printf("Your fortune is %s\n", fortune);

			free(birth_date);
			free(current_date);
			free(zodiac);
		}
		else printf("You have not entered a valid date!\n");
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
