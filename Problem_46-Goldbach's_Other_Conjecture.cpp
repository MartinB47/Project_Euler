/*
 It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

 9 = 7 + 2×1^2
 15 = 7 + 2×2^2
 21 = 3 + 2×3^2
 25 = 7 + 2×3^2
 27 = 19 + 2×2^2
 33 = 31 + 2×1^2

 It turns out that the conjecture was false.

 What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
 */

#include <iostream>
#include <cmath>
using namespace std;

bool prime(long num) {
    if (num == 1) return false;
    for (int i = 2; i <= int(num / 2); i++) if (num % i == 0) return false;
    return true;
}


bool twice_a_square(long n){
    double num = sqrt(n/2);
    if (num == int(num)) return true;
    return false;
}


bool goldbach(long n){
    for (int a = 2; a <= n-2; a++){
        if (prime(a)){
            if (twice_a_square(n-a)) return true;
        }
    }
    return false;
}

bool odd_composite(long n){
    if (n%2 == 1 && !(prime(n))) return true;
    return false;
}

int main(){
    int num = 9;
    bool flag = true;
    while (flag){
        num++;
        cout << "num: " << num << endl;
        if (odd_composite(num) && !(goldbach(num))){
            flag = false;
        }
    }
    cout << num << " is the smallest odd composite number that's not goldbach." << endl;
}
