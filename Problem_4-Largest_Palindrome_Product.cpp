#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

bool Palindrome(int n) {
	int current, reversed = 0;
	int copy = n;
	do
	{
		current = copy % 10;
		reversed = current + (reversed * 10);
		copy /= 10;
	} while (copy != 0);
	if (n == reversed) return true;
		else return false;
}

int main() {
	int product;
	for (int first = 999; first >= 100; first--) {
		for (int second = 999; second >= 100; second--) {
			
			product = first * second;
			if (Palindrome(product) == 1) {
				cout << product << endl;
				break;
			}
		}
	}
}