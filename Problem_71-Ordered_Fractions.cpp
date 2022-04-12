/*
 Consider the fraction, n/d, where n and d are positive integers. If n<d and HCF(n,d)=1, it is called a reduced proper fraction.

 If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:

 1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8

 It can be seen that 2/5 is the fraction immediately to the left of 3/7.

 By listing the set of reduced proper fractions for d ≤ 1,000,000 in ascending order of size, find the numerator of the fraction immediately to the left of 3/7.
 */
#include <iostream>
using namespace std;


void previous_fraction(int n, int d, int limit){
    double fraction = n/double(d);
    double ord, diff, min_diff, min_num, min_den, num_den_diff;
    min_diff = num_den_diff = 1;
    for (int num = 1; num <= limit; num++){
        for (int den = num+num_den_diff; den <= limit; den++){
            ord = num/double(den);
            if (ord < fraction){
                diff = fraction - ord;
                if (diff < min_diff){
                    min_diff = diff;
                    min_num = num;
                    min_den = den;
                    num_den_diff = den - num;
                }
            }
        }
    }
    cout << min_num << "/" << min_den << " is immediately to the left of " << n << "/" << d << "." << endl;
}

int main(){
    previous_fraction(3, 7, 8);
}











/*
void FindtheFraction(int M, int n, int d) {
	int den, num;
	double x, fraction, dden, dnum, Answer;
	Answer = 0;
	dden = d;
	dnum = n;
	fraction = dnum / dden;


	for (den = 2; den <= M; den++) {
		for (num = 1; num < den; num++) {
			dnum = num;
			dden = den;
			x = dnum / dden;
			if (x < fraction) {
				if (x > Answer) {
					Answer = x;
				}
			}
		}
	}
	cout << "The answer is " << Answer <<endl;
}

int main() {
	
	int M, n, d;
	cout << "Enter three values: M, n/d separated by spaces ";
	cin >> M >> n >> d;
	cout << "The inputs are " << M << " " << n << " " << d << endl;
	
	int M = 1000000;
	int n = 3;
	int d = 7;

	FindtheFraction(M, n, d);
}
*/
