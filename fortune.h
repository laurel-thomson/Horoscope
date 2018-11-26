#ifndef FORTUNE
#define FORTUNE

typedef enum Moon {
	NEW,
	FULL
} Moon;

//the fortunes are hard-coded in for now - will need to update this to read from a CSV
const char * fortunes[2][12] = 
{
	{"f00","f01","f02","f03","f04","f05","f06","f07","f08","f09","f010","f011"},
	{"f10","f11","f12","f13","f14","f15","f16","f17","f18","f19","f110","f111"},
};

const char * get_fortune(Zodiac * zodiac, Moon moon)
{
	return fortunes[moon][zodiac->index];
}

#endif
