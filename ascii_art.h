#ifndef ASCII_ART
#define ASCII_ART

//zodiac art source: https://asciiart.website/index.php?art=religion/astrology

char * aquarius_art = "\n\n"
"   .-\"-._.-\"-._.-\n"
"   .-\"-._.-\"-._.-\n\n";

char * pisces_art = "\n\n"
"   `-.    .-'\n"
"     :  :\n"
"   --:--:--\n"
"     :  :\n"
"  .-'    `-.\n\n";

char * aries_art = "\n\n"
"  (_  \\ /  _)\n"
"       |\n"
"       |\n\n";

char * taurus_art = "\n\n"
"    .     .\n"
"    '.___.'\n"
"    .'   `.\n"
"   :       :\n"
"   :       :\n"
"    `.___.'\n\n";


char * gemini_art = "\n\n"
"    ._____.\n"
"      | |  \n"
"      | |\n"
"     _|_|_\n"
"    '     '\n\n";

char * cancer_art = "\n\n"
"      .--.\n"
"     /   _`.\n"
"    (_) ( )\n"
"   '.    /\n"
"     `--'\n\n";

char * leo_art = "\n\n"
"      .--.\n"
"     (    ) \n"
"    (_)  /\n"
"        (_,\n\n";

char * virgo_art = "\n\n"
"   _\n"
"  ' `:--.--.\n"
"     |  |  |_ \n"
"     |  |  | )\n"
"     |  |  |/\n"
"          (J\n\n";

char * libra_art = "\n\n"
"        __\n"
"   ___.'  '.___ \n"
"   ____________\n\n";

char * scorpio_art = "\n\n"
"   _\n"
"  ' `:--.--.\n"
"     |  |  |    \n"
"     |  |  |\n"
"     |  |  |  ..,\n"
"           `---':\n\n";

char * sagittarius_art = "\n\n"
"          ...\n"
"          .': \n"
"        .'\n"
"    `..'\n"
"    .'`.\n\n";

char * capricorn_art = "\n\n"
"            _\n"
"    \\      /_)   \n"
"     \\    /`.\n"
"      \\  /   ;\n"
"       \\/ __.'\n\n";

//moon art source: http://www.oocities.org/spunk1111/celestal.htm

char * new_moon_art = "\n\n"
"        _..._ \n"
"      .:::::::.  \n"
"     :::::::::::\n"
"     :::::::::::  \n"
"     `:::::::::'  \n"
"       `':::''\n\n";

char * first_quarter_art = "\n\n"
"       _..._     \n"
"      .::::  `.    \n"
"     ::::::    :\n"
"     ::::::    :  \n"
"     `:::::   .'  \n"
"       `'::.-' \n\n";

char * waning_crescent_art = "\n\n"
"        _..._     \n"
"      .' .::::.    \n"
"     :  :::::::: \n"
"     :  ::::::::  \n"
"     `. '::::::'  \n"
"       `-.::'' \n\n";

char * full_moon_art = "\n\n"
"       _..._     \n"
"      .'     `.    \n"
"     :         :\n"
"     :         :  \n"
"     `.       .'  \n"
"       `-...-'  \n\n";

char * waning_gibbous_art = "\n\n"
"       _..._     \n"
"      .'   `::.    \n"
"     :       :::\n"
"     :       :::  \n"
"     `.     .::'  \n"
"       `-..:'' \n\n";

char * last_quarter_art = "\n\n"
"        _..._     \n"
"      .'  ::::.    \n"
"     :    :::::: \n"
"     :    ::::::  \n"
"     `.   :::::'  \n"
"       `-.::''  \n\n";

char * waxing_gibbous_art = "\n\n"
"      _..._     \n"
"      .::'   `.    \n"
"     :::       : \n"
"     :::       :  \n"
"     `::.     .'  \n"
"       `':..-'   \n\n";

char * waxing_crescent_art = "\n\n"
"        _..._     \n"
"      .::::. `.    \n"
"     :::::::.  :\n"
"     ::::::::  :  \n"
"     `::::::' .'  \n"
"       `'::'-' \n\n";

void print_moon_art(int phase)
{
	switch(phase)
	{
		case 0:
			printf("%s",new_moon_art);
			break;
		case 1:
			printf("%s",first_quarter_art);
			break;
		case 2:
			printf("%s",waxing_crescent_art);
			break;
		case 3:
			printf("%s",full_moon_art);
			break;
		case 4:
			printf("%s",waxing_gibbous_art);
			break;
		case 5:
			printf("%s",last_quarter_art);
			break;
		case 6:
			printf("%s",waning_gibbous_art);
			break;
		case 7:
			printf("%s",waning_crescent_art);
			break;
		default:
			printf("Error.");
			break;
	}
}

void print_zodiac_art(Zodiac * zodiac)
{
	switch(zodiac->index)
	{
		case 0:
			printf("%s",aquarius_art);
			break;
		case 1:
			printf("%s",pisces_art);
			break;
		case 2:
			printf("%s",aries_art);
			break;
		case 3:
			printf("%s",taurus_art);
			break;
		case 4:
			printf("%s",gemini_art);
			break;
		case 5:
			printf("%s",cancer_art);
			break;
		case 6:
			printf("%s",leo_art);
			break;
		case 7:
			printf("%s",virgo_art);
			break;
		case 8:
			printf("%s",libra_art);
			break;
		case 9:
			printf("%s",scorpio_art);
			break;
		case 10:
			printf("%s",sagittarius_art);
			break;
		case 11:
			printf("%s",capricorn_art);
			break;
		default:
			break;
	}
}
#endif
