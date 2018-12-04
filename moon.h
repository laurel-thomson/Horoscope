#include <math.h>

#ifndef MOON
#define MOON

//algorithm inspiration from http://www.voidware.com/moon_phase.htm
//and https://www.subsystems.us/uploads/9/8/9/4/98948044/moonphase.pdf
//NOTE: this is a simple calculation and doesn't account for several factors, so
//it may be off ;-)
int moon_phase(Date * d) //int year, int month, int day
{
  int year = d->year;
  int month = d->month->monthNumber;
  int day = d->day;

  //begin calculation to find the Julian Date (days since Jan 1, 4713 BC)
  if (month == 1 || month == 2) //if month is Jan or Feb
  {
    year--; //subtract 1 from the year
    month += 12; //and add 12 to the month
  }

  int a, b, c, e, f;
  double jd;

  a = year/100; //only keep int part
  b = a/4; //only keep int part
  c = 2 - a + b;
  e = 365.25 * (year + 4716);
  f = 30.6001 * (month + 1);
  jd = c + day + e + f - 1524.5; //the Julian Date!

  //now we find the days since the last new moon
  double days_since = jd - 2451549.5;

  //now we find how many new moon have happened
  double new_moons = days_since / 29.53;

  //drop the integer from new_moons and keep the decimal/fraction
  double new_moon_int; //the integer part of new_moons
  double frac; //the fractional part
  frac = modf(new_moons, &new_moon_int);

  //multiply by 29.53 (days per moon cycles) to get days into cycle
  double days_into = frac * 29.53;

  int phase;
  if (days_into >= 0 && days_into <= 7)
  {
    if (days_into >= 0 && days_into < 2) phase = 0;
    else if (days_into >= 6 && days_into < 8) phase = 1;
    else { phase = 2; };
  }
  else if (days_into > 7 && days_into <= 15)
  {
    if (days_into >= 14 && days_into <= 16) phase = 3;
    else { phase = 4; };
  }
  else if (days_into > 15 && days_into <= 22)
  {
    if (days_into >= 21 && days_into < 23) phase = 5;
    else { phase = 6; };
  }
  else if (days_into > 22 && days_into <= 29.5)
  {
    if (days_into >= 29) phase = 0;
    else { phase = 7; };
  }

  return phase;
}

char* convert_moon_phase_to_string(int moon)
{
  char* name;
  switch (moon)
  {
    case 0:
      name = "New";
      break;
    case 1:
      name = "First Quarter";
      break;
    case 2:
      name = "Waxing Crescent";
      break;
    case 3:
      name = "Full Moon";
      break;
    case 4:
      name = "Waxing Gibbous";
      break;
    case 5:
      name = "Last Quarter";
      break;
    case 6:
      name = "Waning Gibbous";
      break;
    case 7:
      name = "Waning Crescent";
      break;
    default:
      name = "Error";
      break;
  }
  return name;
}

#endif
