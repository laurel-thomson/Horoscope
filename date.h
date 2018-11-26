#ifndef DATE
#define DATE

typedef enum boolean { false, true } boolean;

typedef struct month {
  char *name; //the full friendly name of the month
  char abrev[3]; //the three character abreviation of the month (ex: JAN)
  int monthNumber; //the month number
  int days; //the number of days in the month
} month;

typedef struct date {
  char month[10]; //the month of the date
  int monthNumber; //the month number of the date
  int day; //the day of the date
} date;


typedef enum monthDay {
  JAN_COUNT = 31,
  FEB_COUNT = 28,
  MAR_COUNT = 31,
  APR_COUNT = 30,
  MAY_COUNT = 31,
  JUN_COUNT = 30,
  JUL_COUNT = 31,
  AUG_COUNT = 31,
  SEP_COUNT = 30,
  OCT_COUNT = 31,
  NOV_COUNT = 30,
  DEC_COUNT = 31
} monthDay;


/* january */
month january = {
   "January",
   "JAN",
   1,
   JAN_COUNT
};

/* february */
month february = {
  "February",
  "FEB",
  2,
  FEB_COUNT
};

/* march */
month march = {
  "March",
  "MAR",
  3,
  MAR_COUNT
};

/* april */
month april = {
  "April",
  "APR",
  4,
  APR_COUNT
};

/* may */
month may = {
  "May",
  "MAY",
  5,
  MAY_COUNT
};

/* june */
month june = {
  "June",
  "JUN",
  6,
  JUN_COUNT
};

/* july */
month july = {
  "July",
  "JUL",
  7,
  JUL_COUNT
};

/* august */
month august = {
  "August",
  "AUG",
  8,
  AUG_COUNT
};

/* september */
month september = {
  "September",
  "SEP",
  9,
  SEP_COUNT
};

/* october */
month october = {
  "October",
  "OCT",
  10,
  OCT_COUNT
};

/* november */
month november = {
  "November",
  "NOV",
  11,
  NOV_COUNT
};

/* december */
month december = {
  "December",
  "DEC",
  12,
  DEC_COUNT
};

month * monthsOfYear[] = { &january, &february, &march, &april, &may, &june, &july, &august, &september, &october, &november, &december };

boolean is_valid_date(int m, int day)
{
	if (m < 0 || m > 12) return false;
	if (day < 0 || day > 31) return false;
	month *current_month = monthsOfYear[m-1];
	if (current_month->days < day) return false;
	return true;
}

#endif
