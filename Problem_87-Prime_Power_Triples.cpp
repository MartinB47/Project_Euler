/*
 The smallest number expressible as the sum of a prime square, prime cube, and prime fourth power is
 . In fact, there are exactly four numbers below fifty that can be expressed in such a way:
         28 = 2^2 + 2^3 + 2^4
         33 = 3^2 + 2^3 + 2^4
         49 = 5^2 + 2^3 + 2^4
         47 = 2^2 + 3^3 + 2^4
 How many numbers below fifty million can be expressed as the sum of a prime square, prime cube, and prime fourth power?
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    // Implementing the Sieve of Eratosthenes algorithm
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    // Collecting the primes into a separate vector
    vector<int> primes;
    for (int i = 0; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}

int main() {
    const int limit = 5e7;
    // Calculating the limit for the sieve function
    const int sieve_limit = sqrt(limit);
    vector<int> primes = sieve(sieve_limit);
    
    unordered_set<int> unique_sums;
    for (const int& p1 : primes) {
        int sum1 = pow(p1, 4);
        if (sum1 >= limit) break;

        for (const int& p2 : primes) {
            int sum2 = sum1 + pow(p2, 3);
            if (sum2 >= limit) break;

            for (const int& p3 : primes) {
                int sum3 = sum2 + pow(p3, 2);
                if (sum3 >= limit) break;

                unique_sums.insert(sum3);
            }
        }
    }
    
    // Output the size of the set (i.e., the count of unique sums)
    cout << unique_sums.size();
}
