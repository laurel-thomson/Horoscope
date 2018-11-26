#ifndef ZODIAC
#define ZODIAC

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


#endif
