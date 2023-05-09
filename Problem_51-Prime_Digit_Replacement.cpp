/*
 By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

 By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.

 Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.
 */

#include <bits/stdc++.h>
using namespace std;

// generates all combinations indexes to be altered given  length of target
// e.g. for n = 2, combinations = {{0}, {0,1}, {0,2}, {1}, {1,2}, {2}}
void generate_combinations(vector<vector<int>> &combinations, vector<int> &current, int start, int n){
    if (start == n){
        return;
    }
    for (int i = start; i < n; ++i){
        current.push_back(i);
        //skips sequence of size n
        // e.g. for n = 3, {0,1,2} will be omitted.
        if (current.size() < n){
            combinations.push_back(current);
        }
        generate_combinations(combinations, current, i + 1, n);
        current.pop_back();
    }
}

// Sieve of Eratosthenes generates primes up to n.
vector<bool> sieve(int n){
    vector<bool> is_prime(n + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i <= n; ++i){
        if (is_prime[i]){
            for (int j = i * i; j <= n; j += i){
                is_prime[j] = 0;
            }
        }
    }
    return is_prime;
}


int main(){
    const int n = 1e6;
    vector<bool> is_prime = sieve(n);
    
    int current_length = 1;
    vector<vector<int>> combinations;
    vector<int> current;
    generate_combinations(combinations, current, 0, current_length);
    for (int p = 0; p < n + 1; ++p){
        if (!is_prime[p]) continue;
        string s = to_string(p);
        int length = s.size();
        //generate a new set of combinations with new digit count
        if (length > current_length){
            current_length = length;
            combinations.clear();
            current.clear();
            generate_combinations(combinations, current, 0, current_length);
        }
        
        for (const auto &v: combinations){
            //store the family of primes in a set.
            unordered_set<int> primes;
            
            //if we're changing the first digit, it can't be 0.
            char start = (v[0] == 0) ? '1' : '0';
            for (char ch = start; ch <= '9'; ++ch){
                string t = s;
                for (const int &d: v){
                    t[d] = ch;
                }
                int variation = stoi(t);
                //add potential prime to family
                if (is_prime[variation]){
                    primes.insert(variation);
                }
            }
            
            //checks for families of size 8, including p itself
            if (primes.size() == 8 && primes.find(p) != primes.end()){
                cout << p;
                return 0;
            }
        }
    }
}
