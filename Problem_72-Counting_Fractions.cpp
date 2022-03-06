#include <iostream>
using namespace std;

bool prime(int num) {
    if (num == 1) return false;
    for (int i = 2; i <= int(num / 2); i++) if (num % i == 0) return false;
    return true;
}

long euclidiangcd(long a, long b) {
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

void count_fractions(int d){
    int count = 0;

    for (int num = 1; num < d; num++){
        if (prime(num)){
            for (int den = num+1; den<=d; den++){
                if (den%num != 0) count++;
            }
        }
        else{
            for (int den = num+1; den <= d; den++){
                if (euclidiangcd(num, den) == 1){
                    cout << num << "/" << den << endl;
                    count++;
                }
            }
        }
    }
    cout << "Count is " << count << endl;
}

int main(){
    count_fractions(10000);
}
