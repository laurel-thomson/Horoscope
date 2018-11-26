#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "date.h"
#include "sign.h"

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
		Date * date = get_date(birthmonth, birthday);
		Zodiac * zodiac = get_sign(date);
		printf("Your sign is a %s!\n", zodiac->name);
		free(date);
		free(zodiac);
  }
  else printf("NOT VALID!");
  return 0;
}
