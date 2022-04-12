/*
 The sum of the squares of the first ten natural numbers is 385.
 The square of the sum of the first ten natural numbers is 3025.
 Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.
 Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */
#include <iostream>
using namespace std;

int square_sum(int n) {
	int sum=0;
	for (int i = 0; i <= n; i++) {
		sum += i;
	}
	return sum * sum;
}

int sum_of_squares(int n) {
	int sum = 0;
	for (int i = 0; i <= n; i++) {
		sum += i * i;
	}
	return sum;
}

int main() {
	cout << "The square of the sum of the numbers from 1 - 100: " << square_sum(100) << endl;
	cout << "Sum of the squares of the numbers from  1 - 100: " << sum_of_squares(100) << endl;
	int difference = square_sum(100) - sum_of_squares(100);
	cout << "The difference is " << difference << "." << endl;
}
