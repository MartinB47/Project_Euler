#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;


int CountDigits(int n) {
	if (n == 0) return 1;
	double x;
	x = 1 + floor(log(abs(n)) / log(10));
	return x;
}


void FindRotatingIntegers(int n) { //this code finds different rotations of a number (e.g. 267, 276, 726, 762)
	int m;
	m = CountDigits(n);
	cout << n << " has " << m << " digits" << endl;

	int d, x, i, digits[20], w[20];
	x = n;
	for (i = 0; i < m; i++) {
		d = x % 10;
		//cout << "Last digit " << d << endl;
		digits[m - 1 - i] = d; //m-1 is essentially 2. we do this to put the numbers in order of the numbers.
		x -= d;
		x /= 10;

	}
	cout << "The digits are : " << endl;
	for (i = 0; i < m; i++) cout << i << " " << digits[i] << endl;





	cout << endl << endl;





	int p, j, k;

	for (i = 0; i < m; i++) {
		p = pow(10, m-1);
		x = 0;
		for (j = 0; j < m; j++) {
			k = (i + j) % m;
			x = x + digits[k] * p;
			p = p / 10;
		}
		cout << "The number is " << x << endl;
	}
}



 
bool Prime(long long int num) {
	bool flag = true;
	for (long long int i = 2; i <= int(num / 2); i++) {
		if (num % i == 0) {
			flag = false;
			break;
		}
	}
	return flag;
}






int main() {
	FindRotatingIntegers(251);
	system("PAUSE");
}