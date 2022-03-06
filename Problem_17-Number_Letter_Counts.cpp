#include<stdio.h>
#include <iostream>
using namespace std;

int countletter(int n) { //Single digit number
	int count = 0;
	if (n == 1 || n == 2 || n == 6) return 3;
	if (n == 4 || n == 5 || n == 9) return 4;
	if (n == 3 || n == 7 || n == 8) return 5;
	if (n == 0) return 0;
}

bool is_teen(int n) {
	int lasttwo = n % 100;
	if (lasttwo % 100 >= 10 && lasttwo <= 19) return true;
}

int countteens(int n) {//The number
	int lasttwo = n % 100;
	if (lasttwo == 10) return 3;
	if (lasttwo == 11 || lasttwo == 12) return 6;
	if (lasttwo == 15 || lasttwo == 16) return 7;
	if (lasttwo == 13 || lasttwo == 14 || lasttwo == 19 || lasttwo == 18) return 8;
	if (lasttwo == 17)  return 9;
}

int nthdigit(int n, int digit) {//The number, desired digit
	int desired;
	int num = n;
	for (int i = 1; i <= digit; i++) {
		desired = num % 10;
		num -= desired;
		num /= 10;
	}
	return desired;
}

int countty(int n) {//The number
	int tenths = nthdigit(n, 2);
	if (tenths == 4 || tenths == 5 || tenths == 6 ) return 5;
	if (tenths == 2 || tenths == 3 || tenths == 8 || tenths == 9) return 6;
	if (tenths == 7) return 7;
	if (tenths == 0) return 0;
}

bool is_hundred(int n) {
	if (n % 100 == 0) return true;
	return false;
}



int main() {
	int sum, sumofletter;
	sum = 0;
	sumofletter = 0;
	int number;
	for (int i = 1; i <= 999; i++) {
		number = i;
		sumofletter = 0;
		sumofletter += countletter(nthdigit(number, 1));
		sumofletter += countty(number);
		if (countletter(nthdigit(number, 3)) > 0) sumofletter += 10 + countletter(nthdigit(number, 3));
		if (is_teen(number) == 1) {
			sumofletter -= countletter(nthdigit(number, 1));
			sumofletter -= countty(number);
			sumofletter += countteens(number);
		}
		if (is_hundred(number) == 1) {
			sumofletter -= 3;
		}
		cout << "Number: " << number << "." << endl;
		cout << "Sum: " << sumofletter << "." << endl;
		sum += sumofletter;
	}
	cout << "The sum of the letters of the numbers from 1 - 1000: " << sum + 11;
}

/*if (is_hundred(number) == 1) sum += (7 + countletter(nthdigit(number, 3)));
	else
	{
		if (is_teen(number) == 1) sum += countteens(number);
		else
		{
			sum += countletter(nthdigit(number, 1));
			sum += countty(number);
		}
	}*/
















/*int countty(int n) {
	int lasttwo
}*/




/*void digit(int n) {
	int digits;
	int lastdigit;
	int num = n;
	for (int i = 1; i <= digits; i++) {
		lastdigit = num % 10;
		num = (num - lastdigit) / 10;
		cout << lastdigit;
	}
}*/
