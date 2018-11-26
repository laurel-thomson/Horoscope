#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "date.h"
#include "sign.h"

int main() {

  /* aquarius */
  zodiac aquarius = {
    "Aquarius",
    "AQU"
  };

  date test = { "January", 1, 21 }; //a sample day

  int birthmonth;
  printf("Enter the month of your birthday (example: May would be 5): ");
  scanf("%d", &birthmonth);
  printf("Birth month is %d\n", birthmonth);
  printf("\n");

  int birthday;
  printf("Enter the day of your birthday (example: 16): ");
  scanf("%d", &birthday);
  printf("Total bithday is %d/%d\n", birthmonth, birthday);
  printf("\n");
  
  boolean is_valid = is_valid_date(birthmonth, birthday);
  if (is_valid) printf("that is a valid date.");
  else printf("NOT VALID!");

  char *newsign = get_sign(birthmonth, birthday);
  printf("Your sign is a %s!\n", newsign);
  return 0;
}
