/*
 A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 Find the largest palindrome made from the product of two 3-digit numbers.
 */
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
