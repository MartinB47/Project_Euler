#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

void adding(int num, int *sum) {
	for (int i = 3; i < num; i++) {
		if (i % 3 == 0 || i % 5 == 0) *sum += i;
	}
}

int main() {
	int num = 1000;
	int sum = 0;
	adding(num, &sum);
	cout << "The sum of the multiples of 3 or 5 from 1 - " << num << " is " << sum << "." << endl;
}