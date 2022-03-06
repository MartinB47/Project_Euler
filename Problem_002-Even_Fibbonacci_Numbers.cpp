#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

int main() {
	int previous = 1;
	int digit = 2;
	int nextdigit = 0;
	int sum = 2;
	//sum is 3 because program starts counting Fibbonacci numbers from 3.
	while (nextdigit < 4000000){
		nextdigit = previous + digit;
		cout << nextdigit << endl;
		if (nextdigit % 2 == 0) sum += nextdigit;
		previous = digit;
		digit = nextdigit;

	}
	cout << "The sum is " << sum;
}
