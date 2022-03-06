#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

int monthdays(int month, int year) {
	if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11) return 31;
	if (month == 3 || month == 5 || month == 8 || month == 10) return 30;
	if (month == 1) {
		if ((year % 4 != 0) || (year % 4 == 0 && year % 100 == 0 && year % 400 != 0)) return 28;
		else return 29;	
	}
}

int main() {
	//cout << "Hello World!" << endl;

	int year, month, day, day2, sundays;
	year = 1901;
	month = 0; //January;
	day = 0; //1st
	day2 = 1; //Tuesday
	sundays = 0;
	for (int i = 0; i <= 36530; i++) {
		//cout << "Year: " << year <<  " Month: " << month << " Day: " << day << " It's  a " << day2 << " today" << endl;
		day++;
		day %= monthdays(month, year);
		day2++;
		day2 %= 7;
		if (day == 0) month++;
		month %= 12;
		if (month == 0 && day == 0) year++;
		if (day == 0 && day2 == 6) {
			sundays++;
			cout << "Year: " << year <<  " Month: " << month << " Day: " << day << " It's  a " << day2 << " today" << endl;
		}
	}
	cout << sundays << " Sundays fell on the first of the month." << endl;
}

