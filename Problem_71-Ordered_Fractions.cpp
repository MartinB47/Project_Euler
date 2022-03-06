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
