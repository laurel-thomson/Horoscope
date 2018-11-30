#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "date.h"
#include "sign.h"
#include "fortune.h"
#include "moon.h"

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

		const char * fortune = get_fortune(zodiac, get_moon(current_date));
		printf("Your fortune is %s\n", fortune);

    char* phase = moon_phase(2018, birthmonth, birthday);
    printf("The moon phase on your birthday this year is a %s!\n", phase);

		free(birth_date);
		free(current_date);
		free(zodiac);
  }
  else printf("NOT VALID!");
  return 0;
}
