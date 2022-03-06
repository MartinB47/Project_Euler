#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;



int collatz(long long int n) {
	long long int num = n;
	long long int terms = 1;
	while (num != 1) {
		if (num % 2 == 0) num /= 2;
		else
			num = 3 * num + 1;
		terms++;
	}
	return terms;
}


int main() {
	long long int maxterms = collatz(1);
	long long int max = 1;
	for (long long int i = 1000000; i >= 2; i--) {
		if (collatz(i) > maxterms) {
			maxterms = collatz(i);
			max = i;
			cout << "Number " << i << " has " << collatz(i) << " terms." << endl;
		}
	}
	cout << "The number with the longest collatz sequence:  " << max << endl;
}