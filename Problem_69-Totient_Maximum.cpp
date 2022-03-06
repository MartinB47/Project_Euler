#include <iostream>
#include <cmath>
using namespace std;

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

int coprime(int a, int b) {
    if (euclidiangcd(a, b) == 1) return true;
    return false;
}

long phi(long n) {
    int count = 0;
    for (long i = 1; i <= n; i++) if (coprime(i,n)) count++;
    return count;
}

bool prime(int num) {
    if (num == 1) return false;
    for (int i = 2; i <= int(num / 2); i++) if (num % i == 0) return false;
    return true;
}

int nextprime(int num) {
    int next_prime = ++num;
    while (!prime(next_prime)) next_prime++;
    return next_prime;
}

int main(){
    int num = 2;
    int multiplier = 3;
    double max_ratio = 1;
    int max_num = 1;
    while (num <= 1000000){
        double ratio = num/double(phi(num));
        cout << "When n = " << num << " Ratio: " << ratio << "." << endl;
        num *= multiplier;
        multiplier = nextprime(multiplier);
    }
}
