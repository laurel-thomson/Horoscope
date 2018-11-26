#ifndef DATE
#define DATE

typedef enum boolean { false, true } boolean;

typedef struct Month {
  char *name; //the full friendly name of the month
  char abrev[3]; //the three character abreviation of the month (ex: JAN)
  int monthNumber; //the month number
  int days; //the number of days in the month
} Month;

typedef struct Date {
	Month * month;
	int day;
} Date;


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
Month january = {
   "January",
   "JAN",
   1,
   JAN_COUNT
};

/* february */
Month february = {
  "February",
  "FEB",
  2,
  FEB_COUNT
};

/* march */
Month march = {
  "March",
  "MAR",
  3,
  MAR_COUNT
};

/* april */
Month april = {
  "April",
  "APR",
  4,
  APR_COUNT
};

/* may */
Month may = {
  "May",
  "MAY",
  5,
  MAY_COUNT
};

/* june */
Month june = {
  "June",
  "JUN",
  6,
  JUN_COUNT
};

/* july */
Month july = {
  "July",
  "JUL",
  7,
  JUL_COUNT
};

/* august */
Month august = {
  "August",
  "AUG",
  8,
  AUG_COUNT
};

/* september */
Month september = {
  "September",
  "SEP",
  9,
  SEP_COUNT
};

/* october */
Month october = {
  "October",
  "OCT",
  10,
  OCT_COUNT
};

/* november */
Month november = {
  "November",
  "NOV",
  11,
  NOV_COUNT
};

/* december */
Month december = {
  "December",
  "DEC",
  12,
  DEC_COUNT
};

Month * monthsOfYear[] = { &january, &february, &march, &april, &may, &june, &july, &august, &september, &october, &november, &december };

boolean is_valid_date(int m, int d)
{
	if (m < 0 || m > 12) return false;
	if (d < 0 || d > 31) return false;
	Month *current_month = monthsOfYear[m-1];
	if (current_month->days < d) return false;
	return true;
}

Date* get_date(int m, int d)
{
	Date *date = malloc(sizeof(Date));
	date->month = monthsOfYear[m-1];
	date->day = d;
	return date;
}


#endif
