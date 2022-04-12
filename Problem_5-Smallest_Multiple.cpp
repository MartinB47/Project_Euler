/*
 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

 What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */
#include <iostream>
using namespace std;

int divisible_by_20(int n) {
	int sum = 0;
	for (int i = 1; i <= 20; i++) {
		sum = sum + (n % i);
	}
	if (sum == 0) return 1;
		else return 0;
}

int main() {
	int i = 0;
	bool flag = false;
	while (flag == false) {
		i+=20;
		cout << i<< endl;
		if (divisible_by_20(i) == 1) return true;
	}
}


/*


	for (int i = 1; i <= 1000000; i++) {
		if (divisible_by_20(i) == 1) {
			cout << i << endl;
			break;
		}
	}
*/
