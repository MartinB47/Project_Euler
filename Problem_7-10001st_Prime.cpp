#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

int Prime(int num) {
	bool flag = true;
	for (int i = 2; i <= int(num / 2); i++) {
		if (num % i == 0) {
			flag = false;
			break;
		}
	}
	return flag;
}

int nth_prime(int n) {
	int quantity, numbers;
	quantity = numbers = 0;
	while (quantity <= n) {
		numbers++;
		if (Prime(numbers) == 1) quantity++;
	}
	return numbers;
}

int main() {
	cout << "Enter desired nth Prime: " << endl;
	int num;
	cin >> num;
	cout << "The " << num << "th prime number is " << nth_prime(num) << endl;
}