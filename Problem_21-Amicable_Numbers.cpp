#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

int sum_of_divisors (int n){
	int sum = 1;
	for (int i = 2; i <= (n / 2); i++) {
		if (n % i == 0) sum += i;
	}
	return sum;
}





int main() {
	int sum = 0;
	for (int i = 1; i <= 1000000; i++) {
		if (i == sum_of_divisors(sum_of_divisors(i)) && i != sum_of_divisors(i)) {
			sum += (i + sum_of_divisors(i));
			i = sum_of_divisors(i);
			cout << "1st: " << i << endl << "2nd: " << sum_of_divisors(i) << endl;
			cout << "-------------" << endl;
		}
	}
	cout << "The sum of Amicable pairs under 10,000: " << sum << endl;
}