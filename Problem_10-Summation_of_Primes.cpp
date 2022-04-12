/*
 The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 Find the sum of all the primes below two million.
*/
#include <iostream>
using namespace std;

bool Prime(long long int num) {
	if ((num % 10) == 5) return false;
	for (long long int i = 2; i <= long long int(num / 2); i++) {
		if (num % i == 0) return false;
	}
	return true;
}

void sumprimes(int n) {
	long long int sum = 0;
	for (long long int i = 3; i < n; i+=2) {
		if (Prime(i) == 1) {
			sum += i;
			cout << i << endl;
		}
	}
	cout<< "sum: " << sum;
}

int main() {
	sumprimes(2000000);
}
