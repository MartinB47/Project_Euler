/*
 Consider the fraction, n/d, where n and d are positive integers. If n<d and HCF(n,d)=1, it is called a reduced proper fraction.

 If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:

 1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8

 It can be seen that there are 3 fractions between 1/3 and 1/2.

 How many fractions lie between 1/3 and 1/2 in the sorted set of reduced proper fractions for d ≤ 12,000?
 */
#include <iostream>
using namespace std;

int euclidiangcd(long a, long b) {
    long larger = a;
    long smaller = b;
    while (true){
        if (larger<smaller){
            smaller = a;
            larger = b;
        }
        int r = larger % smaller;
        if (r==0) return smaller;
        larger = smaller;
        smaller = r;
    }
}

long count_fractions(int d){
    int count = 0;
    double result;
    double one_third = 1 / double(3);
    double one_half = 1 / double(2);
    for (int num = 1; num < d; num++){
        for (int den = num+1; den <= d; den++){
            if (euclidiangcd(num, den) == 1) {
                result = num / double(den);
                if (result > one_third && result < one_half) count++;
            }
        }
    }
    return count;
}

int main(){
    cout << count_fractions(12000) << endl;
}
