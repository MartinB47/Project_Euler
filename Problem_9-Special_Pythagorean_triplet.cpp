/*
 A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 a^2 + b^2 = c^2
 For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 Find the product abc.
 */
#include <iostream>
using namespace std;

int main() {
	for (int a = 1; a <= 500; a++) {
		for (int b = 1; b <= 500; b++) {
			for (int c = 1; c <= 500; c++) {
				if (a * a + b * b == c * c && a + b + c == 1000) {
					cout << "Pythagorean triples that add up to at 1000 are " <<  a << ", " << b << ", " << c << "." << endl;
					cout << "Their product is " << a << " * " << b << " * " << c << " = " << a * b * c << endl;
				}
			}
		}
	}
}
