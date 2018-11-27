#include <math.h>

#ifndef MOON
#define MOON

//algorithm inspiration from http://www.voidware.com/moon_phase.htm
//and https://www.subsystems.us/uploads/9/8/9/4/98948044/moonphase.pdf
//NOTE: this is a simple calculation and doesn't account for several factors, so
//it may be off ;-)
char* moon_phase(int year, int month, int day)
{
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

  char * phase;
  if (days_into >= 0 && days_into <= 7)
  {
    if (days_into >= 0 && days_into < 2) phase = "New";
    else if (days_into >= 6 && days_into < 8) phase = "Third Quarter";
    else { phase = "Waning Crescent"; };
  }
  else if (days_into > 7 && days_into <= 15)
  {
    if (days_into >= 14 && days_into < 16) phase = "Full Moon";
    else { phase = "Waning Gibbous"; };
  }
  else if (days_into > 15 && days_into <= 22)
  {
    if (days_into >= 21 && days_into < 23) phase = "First Quarter";
    else { phase = "Waxing Gibbous"; };
  }
  else if (days_into > 22 && days_into <= 29.5)
  {
    if (days_into >= 29) phase = "New";
    else { phase = "Waxing Crescent"; };
  }

  return phase;
}

#endif
