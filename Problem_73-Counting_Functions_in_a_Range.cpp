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
