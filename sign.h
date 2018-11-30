#ifndef SIGN
#define SIGN

typedef struct Zodiac {
  char name[12];
  int index;
} Zodiac;

typedef enum zodiac_enum {
AQUARIUS,
PISCES,
ARIES,
TAURUS,
GEMINI,
CANCER,
LEO,
VIRGO,
LIBRA,
SCORPIO,
SAGITTARIUS,
CAPRICORN
} zodiac_enum;

Zodiac * get_sign(Date * date) //returns the sign of the given date
{
  Zodiac * zodiac = malloc(sizeof(Zodiac));
  int day = date->day;
  switch (date->month->monthNumber)
  {
    case 1:
      if (day < 20)
      {
        strcpy(zodiac->name, "Capricorn");
		zodiac->index = CAPRICORN;
      }
      else
      {
	    strcpy(zodiac->name, "Aquarius");
		zodiac->index = AQUARIUS;
      }
      break;
    case 2:
      if (day < 19)
      {
	    strcpy(zodiac->name, "Aquarius");
		zodiac->index = AQUARIUS;
      }
      else
      {
		strcpy(zodiac->name, "Pisces");
		zodiac->index = PISCES;
      }
      break;
    case 3:
      if (day < 21)
      {
		strcpy(zodiac->name, "Pisces");
		zodiac->index = PISCES;
      }
      else
      {
		strcpy(zodiac->name, "Aries");
		zodiac->index = ARIES;
      }
      break;
    case 4:
      if (day < 20)
      {
		strcpy(zodiac->name, "Aries");
		zodiac->index = ARIES;
      }
      else
      {
		strcpy(zodiac->name, "Taurus");
		zodiac->index = TAURUS;
      }
      break;
    case 5:
      if (day < 21)
      {
		strcpy(zodiac->name, "Taurus");
		zodiac->index = TAURUS;
      }
      else
      {
		strcpy(zodiac->name, "Gemini");
		zodiac->index = GEMINI;
      }
      break;
    case 6:
      if (day < 21)
      {
		strcpy(zodiac->name, "Gemini");
		zodiac->index = GEMINI;
      }
      else
      {
		strcpy(zodiac->name, "Cancer");
		zodiac->index = CANCER;
      }
      break;
    case 7:
      if (day < 23)
      {
		strcpy(zodiac->name, "Cancer");
		zodiac->index = CANCER;
      }
      else
      {
		strcpy(zodiac->name, "Leo");
		zodiac->index = LEO;
      }
      break;
    case 8:
      if (day < 23)
      {
		strcpy(zodiac->name, "Leo");
		zodiac->index = LEO;
      }
      else
      {
		strcpy(zodiac->name, "Virgo");
		zodiac->index = VIRGO;
      }
      break;
    case 9:
      if (day < 23)
      {
		strcpy(zodiac->name, "Virgo");
		zodiac->index = VIRGO;
      }
      else
      {
		strcpy(zodiac->name, "Libra");
		zodiac->index = LIBRA;
      }
      break;
    case 10:
      if (day < 23)
      {
		strcpy(zodiac->name, "Libra");
		zodiac->index = LIBRA;
      }
      else
      {
		strcpy(zodiac->name, "Scorpio");
		zodiac->index = SCORPIO;
      }
      break;
    case 11:
      if (day < 22)
      {
		strcpy(zodiac->name, "Scorpio");
		zodiac->index = SCORPIO;
      }
      else
      {
		strcpy(zodiac->name, "Sagittarius");
		zodiac->index = SAGITTARIUS;
      }
      break;
    case 12:
      if (day < 22)
      {
		strcpy(zodiac->name, "Sagittarius");
		zodiac->index = SAGITTARIUS;
      }
      else
      {
		strcpy(zodiac->name, "Capricorn");
		zodiac->index = CAPRICORN;
      }
      break;
    default:
      printf("Invalid month, unable to determine sign.");
      break;
  }

  return zodiac;
}

#endif
