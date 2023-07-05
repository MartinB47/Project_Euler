/*
 Euler’s Totient function, Φ(n) [sometimes called the phi function], is used to determine the number of positive numbers less than or equal to n which are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, Φ(9)=6.

 The number 1 is considered to be relatively prime to every positive number, so Φ(1)=1.

 Interestingly, Φ(87109)=79180, and it can be seen that 87109 is a permutation of 79180.

 Find the value of n, 1 < n < 10^7, for which Φ(n) is a permutation of n and the ratio n/Φ(n) produces a minimum.
 */

#include <bits/stdc++.h>
using namespace std;

//This function calculates the Euler's Totient function values for numbers up to 'n' using the Sieve of Eratosthenes algorithm
vector<int> eulerTotientSieve(int n) {
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    
    for (int i = 2; i <= n; ++i) {
        phi[i] = i;
    }

    for (int i = 2; i <= n; ++i) {
        // if i is prime
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    
    return phi;
}

//Check if two integers are permutations of each other by counting the occurrence of each digit and comparing the counts.
bool arePermutations(int num1, int num2){
    array<int, 10> digits1 = {0};
    array<int, 10> digits2 = {0};
    //early size comparison avoids unnecessary computations for non-permutations
    int size1 = 0, size2 = 0;
    
    while (num1){
        ++digits1[num1 % 10];
        num1 /= 10;
        ++size1;
    }
    while (num2){
        ++digits2[num2 % 10];
        num2 /= 10;
        ++size2;
    }
    
    return size1 == size2 && digits1 == digits2;
}

int main(){
    const int limit = 1e7 - 1;
    int result = 2;
    double minRatio = DBL_MAX;
    vector<int> phi = eulerTotientSieve(limit);
    
    for (int n = 2; n <= limit; ++n){
        double ratio = n / double(phi[n]);
        //check the less expensive minimum ratio condition first
        if (ratio < minRatio && arePermutations(n, phi[n])){
            minRatio = ratio;
            result = n;
        }
    }
    
    cout << result;
    return 0;
}
