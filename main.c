#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "month.h"
#include "date.h"
#include "zodiac.h"
#include "sign.h"

int main() {
  /*printf("The month is %s, abrev is %s, number is %d, days is %d\n",
   january.name,
   january.abrev,
   january.monthNumber,
   january.days);*/

  /* aquarius */
  zodiac aquarius = {
    "Aquarius",
    "AQU"
  };

  date test = { "January", 1, 21 }; //a sample day

  //char *sign; //the sign of the person which we will update later

  //printf("The test date is %s %d\n", test.month, test.day);

  //sign = get_sign(test.monthNumber, test.day); //get_sign function returns their sign

  //printf("The person born on %s %d would be an %s\n", test.month, test.day, sign);

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

  char *newsign = get_sign(birthmonth, birthday);
  printf("Your sign is a %s!\n", newsign);
  return 0;
}
