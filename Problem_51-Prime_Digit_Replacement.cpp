/*
 By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

 By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.

 Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.
 */

#include <bits/stdc++.h>
using namespace std;

// Function to generate all combinations of indexes to be altered given length of target
// For n = 2, combinations = {{0}, {0,1}, {0,2}, {1}, {1,2}, {2}}
void generate_combinations(vector<vector<int>> &combinations, vector<int> &current, int start, int n) {
    for (int i = start; i < n; ++i){
        current.push_back(i);
        if (current.size() < n){
            combinations.push_back(current);
        }
        generate_combinations(combinations, current, i + 1, n);
        current.pop_back();
    }
}

// Function to generate primes up to n using Sieve of Eratosthenes
vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i){
        if (is_prime[i]){
            for (int j = i * i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main() {
    const int upperLimit = 1e6;
    vector<bool> is_prime = sieve(upperLimit);
    
    int current_length = 1;
    vector<vector<int>> combinations;
    vector<int> current;
    generate_combinations(combinations, current, 0, current_length);
    for (int num = 0; num < upperLimit + 1; ++num){
        if (!is_prime[num]) continue;
        string numStr = to_string(num);
        int length = numStr.size();
        // Generate a new set of combinations with new digit count
        if (length > current_length){
            current_length = length;
            combinations.clear();
            current.clear();
            generate_combinations(combinations, current, 0, current_length);
        }
        
        for (const auto &combination: combinations){
            unordered_set<int> primes;
            char start = (combination[0] == 0) ? '1' : '0';
            for (char ch = start; ch <= '9'; ++ch){
                string temp = numStr;
                for (const int &digit: combination){
                    temp[digit] = ch;
                }
                int variation = stoi(temp);
                // Add potential prime to family
                if (is_prime[variation]){
                    primes.insert(variation);
                }
            }
            
            // Check for families of size 8, including num itself
            if (primes.size() == 8 && primes.find(num) != primes.end()){
                cout << num;
                return 0;
            }
        }
    }
}
