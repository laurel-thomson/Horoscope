#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef SIGN
#define SIGN

typedef struct zodiac {
  char name[10]; //the full friendly name of the zodiac sign
  char abrev[3]; //the three character abreviation of the sign (ex: virgo is VIR)
} zodiac;

typedef enum zodiac_enum {
Aquarius,
Pisces,
Aries,
Taurus,
Gemini,
Cancer,
Leo,
Virgo,
Libra,
Scorpio,
Sagittarius,
Capricorn
} zodiac_enum;

char * get_sign(Date * date) //returns the sign of the given date
{
  char * sign;
  int day = date->day;
  switch (date->month->monthNumber)
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
      if (day < 21)
      {
        sign = "Pisces";
      }
      else
      {
        sign = "Aries";
      }
      break;
    case 4:
      if (day < 20)
      {
        sign = "Aries";
      }
      else
      {
        sign = "Taurus";
      }
      break;
    case 5:
      if (day < 21)
      {
        sign = "Taurus";
      }
      else
      {
        sign = "Gemini";
      }
      break;
    case 6:
      if (day < 21)
      {
        sign = "Gemini";
      }
      else
      {
        sign = "Cancer";
      }
      break;
    case 7:
      if (day < 23)
      {
        sign = "Cancer";
      }
      else
      {
        sign = "Leo";
      }
      break;
    case 8:
      if (day < 23)
      {
        sign = "Leo";
      }
      else
      {
        sign = "Virgo";
      }
      break;
    case 9:
      if (day < 23)
      {
        sign = "Virgo";
      }
      else
      {
        sign = "Libra";
      }
      break;
    case 10:
      if (day < 23)
      {
        sign = "Libra";
      }
      else
      {
        sign = "Scorpio";
      }
      break;
    case 11:
      if (day < 22)
      {
        sign = "Scorpio";
      }
      else
      {
        sign = "Sagittarius";
      }
      break;
    case 12:
      if (day < 22)
      {
        sign = "Sagittarius";
      }
      else
      {
        sign = "Capricorn";
      }
      break;
    default:
      printf("Invalid month, unable to determine sign.");
      break;
  }

  return sign;
}

#endif
