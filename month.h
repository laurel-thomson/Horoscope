#include <stdio.h>
#include <string.h>

#ifndef MONTH
#define MONTH

typedef struct month {
  char *name; //the full friendly name of the month
  char abrev[3]; //the three character abreviation of the month (ex: JAN)
  int monthNumber; //the month number
  int days; //the number of days in the month
} month;

typedef enum boolean { false, true } boolean;

typedef enum monthDay {
  JAN = 31,
  FEB = 28,
  MAR = 31,
  APR = 30,
  MAY = 31,
  JUN = 30,
  JUL = 31,
  AUG = 31,
  SEP = 30,
  OCT = 31,
  NOV = 30,
  DEC = 31
} monthDay;

/* january */
month january = {
   "January",
   "JAN",
   1,
   JAN
};

/* february */
month february = {
  "February",
  "FEB",
  2,
  FEB
};

/* march */
month march = {
  "March",
  "MAR",
  3,
  MAR
};

/* april */
month april = {
  "April",
  "APR",
  4,
  APR
};

/* may */
month may = {
  "May",
  "MAY",
  5,
  MAY
};

/* june */
month june = {
  "June",
  "JUN",
  6,
  JUN
};

/* july */
month july = {
  "July",
  "JUL",
  7,
  JUL
};

/* august */
month august = {
  "August",
  "AUG",
  8,
  AUG
};

/* september */
month september = {
  "September",
  "SEP",
  9,
  SEP
};

/* october */
month october = {
  "October",
  "OCT",
  10,
  OCT
};

/* november */
month november = {
  "November",
  "NOV",
  11,
  NOV
};

/* december */
month december = {
  "December",
  "DEC",
  12,
  DEC
};

#endif
