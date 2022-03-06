#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

int SumDigits(int n) {
	int num = n;
	int lastdigit;
	int sum = 0;
	while (num >= 1) {
		lastdigit = num % 10;
		sum += lastdigit;
		num -= lastdigit;
		num /= 10;
	}
	return sum;
}

int main() {
	for (int i = 9; i <= 1000; i++) {
		cout << (i - SumDigits(i)) << endl;
	}
}