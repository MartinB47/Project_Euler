#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

int factors(int n) {
	int counter = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0)
			counter++;
	}
	return counter;
}

int triangluar(int n) {
	int value = 0;
	for (int i = 1; i <= n; i++) {
		value += i;
	}
	return value;
}

int main() {
	int divisors = 0;
	int num = 1;
	while (divisors <= 500) {
		divisors = factors(triangluar(num));
		cout << triangluar(num)<<endl;
		num++;
	}
}