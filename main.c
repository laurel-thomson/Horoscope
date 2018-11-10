#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "month.h"
#include "date.h"
#include "zodiac.h"

int main() {
  printf("The month is %s, abrev is %s, number is %d, days is %d\n",
   january.name,
   january.abrev,
   january.monthNumber,
   january.days);

  /* aquarius */
  zodiac aquarius = {
    "Aquarius",
    "AQU"
  };

  date test = { "January", 1, 21 }; //a sample day

  char *sign; //the sign of the person which we will update later

  printf("The test date is %s %d\n", test.month, test.day);

  if (test.monthNumber == 1)
  {
    if (test.day < 20)
    {
      //capricorn
    }
    else
    {
      //aquarius
      sign = aquarius.name;
    }
  }
  else if (test.monthNumber == 2)
  {
    if (test.day < 19)
    {
      //aquarius
      sign = aquarius.name;
    }
    else
    {
      //pisces
    }
  }

  printf("The person born on %s %d would be an %s\n", test.month, test.day, sign);
  return 0;
}
