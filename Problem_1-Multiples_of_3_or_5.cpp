/*
 If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 Find the sum of all the multiples of 3 or 5 below 1000.
 */
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
