#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "month.h"
#include "date.h"
#include "zodiac.h"

char * get_sign(int month, int day); //returns the sign of the given date

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

  sign = get_sign(test.monthNumber, test.day); //get_sign function returns their sign

  printf("The person born on %s %d would be an %s\n", test.month, test.day, sign);
  return 0;
}

char * get_sign(int month, int day)
{
  char * sign;
  switch (month)
  {
    case 1:
      if (day < 20)
      {
        sign = "Capricorn";
      }
      else
      {
        sign = "Aquarius";
      }
      break;
    case 2:
      if (day < 19)
      {
        sign = "Aquarius";
      }
      else
      {
        sign = "Pisces";
      }
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      break;
    case 8:
      break;
    case 9:
      break;
    case 10:
      break;
    case 11:
      break;
    case 12:
      break;
    default:
      printf("Invalid month, unable to determine sign.");
      break;
  }

  return sign;
}
