/*
 Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.

 *37 36  35 34 33 32  *31
 38  *17 16 15 14 *13 30
 39  18  *5 4  *3 12  29
 40  19  6  1  2  11  28
 41  20  *7 8  9  10  27
 42  21  22 23 24 25  26
 *43 44  45 46 47 48  49

 It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime; that is, a ratio of 8/13 ≈ 62%.

 If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed. If this process is continued, what is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%?
 */

#include <bits/stdc++.h>
using namespace std;

//checks if a number is prime
bool isPrime(int n) {
    if (n < 2) return false;
    if (n <= 3) return true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int x = 0, primes = 0;
    double prime_ratio;

    do {
        x++;
        
        //upper-left diagonal: 4x^2 + 1
        int d1 = 4 * x * x + 1;
        //upper-right diagonal: 4x^2 - 2x + 1
        int d2 = 4 * x * x - 2 * x + 1;
        //bottom-left diagonal: 4x^2 + 2x + 1
        int d3 = 4 * x * x + 2 * x + 1;
        
        if (isPrime(d1)) primes++;
        if (isPrime(d2)) primes++;
        if (isPrime(d3)) primes++;

        prime_ratio = static_cast<double>(primes) / (4 * x + 1);
    } while (prime_ratio > 0.1);

    //side-length formula is 2x + 1.
    cout << 2 * x + 1;
}
