#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

int smallestfactor(long long int n) {
	long long int smallest;
	long long int i = 2;
	bool flag = true;
	while (flag) {
		if (n % i == 0) {
			smallest = i;
			flag = false;
		}
		i++;
	}
	return smallest;
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
	long long int num = 600851475143;
	long long int factor;
	long long int max = 1;
	while (num != 1) {
		factor = smallestfactor(num);
		if (Prime(factor) == 1 && factor > max) max = factor;
		num /= factor;
	}
	cout << "The largest prime factor is " << factor << "." << endl;
}
