#include<stdio.h>
#include<stdlib.h>
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