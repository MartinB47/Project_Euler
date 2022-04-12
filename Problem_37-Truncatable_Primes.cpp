/*
 The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

 Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

 NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
 */
#include <iostream>
#include <cmath>
using namespace std;

bool prime(long num) {
    
    if (num == 1 || num == 0) return false;
    for (long i = 2; i <= long(num / 2); i++) if (num % i == 0) return false;
    return true;
}

int countdigits(int n) {
    if (n == 0) return 1;
    double x;
    x = 1 + floor (log10(abs(n)));
    return x;
}

int nthdigit(int n, int digit) {//The number, desired digit
    int desired;
    int num = n;
    for (int i = 1; i <= digit; i++) {
        desired = num % 10;
        num -= desired;
        num /= 10;
    }
    return desired;
}

int reverse(int n){
    int num = n;
    int digits = countdigits(num);
    int digit;
    int index = 1;
    int reversed = 0;
    while (num>=1){
        digit = num % 10;
        reversed += digit*pow(10,digits-index);
        num = (num-digit)/10;
        index++;
    }
    return reversed;
}

bool truncatable_prime_left(int n){
    long num = n;
    int index1 = 0;
    int index2 = 1;
    int digits = countdigits(num);
    while (num >= 1){
        if (!(prime(num))){
            return false;
            break;
        }
        num -= nthdigit(num,digits-index1)*pow(10,digits-index2);
        index1++;
        index2++;
    }
    return true;
}

bool truncatable_prime_right(int n){
    long num = n;
    int digits = countdigits(num);
    while (num >= 1){
        if (!(prime(num))) return false;
        num -= num%10;
        num /= 10;
    }
    return true;
}

bool truncatable_prime(int n){
    if (truncatable_prime_left(n) && truncatable_prime_right(n)) return true;
    return false;
}

int main(){
    int num = 8;
    int count = 0;
    int sum = 0;
    while (count <11){
        if (truncatable_prime(num)){
            cout << num << endl;
            sum += num;
            count++;
        }
        num++;
    }
    cout << "The sum of truncatable primes is " << sum << "." << endl;
}

