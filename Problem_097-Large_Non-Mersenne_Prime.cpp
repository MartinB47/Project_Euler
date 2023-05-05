/*
 The first known prime found to exceed one million digits was discovered in 1999, and is a Mersenne prime of the form 2^6972593−1; it contains exactly 2,098,960 digits. Subsequently other Mersenne primes, of the form 2^p−1, have been found which contain more digits.

 However, in 2004 there was found a massive non-Mersenne prime which contains 2,357,207 digits: 28433×2^7830457+1.

 Find the last ten digits of this prime number.
 */

#include <bits/stdc++.h>
using namespace std;

//multiply vector of length 10 by mult
void multiply(vector<int> &num, int mult){
    int carry = 0;
    for (int i = 9; i >= 0; i--){
        num[i] = num[i] * mult + carry;
        carry = num[i] / 10;
        num[i] %= 10;
    }
}

int main(){
    vector<int> num(10);
    num[9] = 1;
    multiply(num, 28433);
    for (int i = 0; i < 7830457; i++){
        multiply(num, 2);
    }
    //adding one without worrying about potential carry.
    num[9]++;
    
    for (const int &n: num){
        cout << n;
    }
}
