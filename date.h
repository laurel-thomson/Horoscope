#ifndef DATE
#define DATE

typedef struct date {
  char month[10]; //the month of the date
  int monthNumber; //the month number of the date
  int day; //the day of the date
} date;

boolean is_valid_date(date d)
{
  if (d.monthNumber >= 1 && d.monthNumber <= 12) //is it between jan and dec?
  {
    //now check the dates
    switch (d.monthNumber)
    {
      case 1: //month numbers w/ 31 days
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
        if (d.day >= 1 && d.day <= 31) return true;
        else return false;
        break;
      case 4: //month numbers w/ 30 days
      case 6:
      case 9:
      case 11:
        if (d.day >= 1 && d.day <= 30) return true;
        else return false;
        break;
      case 2: //special case for february
        if (d.day >= 1 && d.day <= 28) return true;
        else if (d.day == 29) //is day feb. 29?
        {
          //check if leap year
          int year;
          printf("What is the year of your birthday? (ex: 2012)\n");
          scanf("%d", &year);

          if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) //is it a leap year
          {
            return true; //valid leap year date
          }
          else
          {
            return false; //not a leap year :(
          }
        }
        else
        {
          return false;
        }
        break;
      default:
        break;
    }
  }
  return true;
}

#endif
