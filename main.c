#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "date.h"
#include "sign.h"
#include "fortune.h"

int main() {

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
  else printf("NOT VALID!");
  return 0;
}
