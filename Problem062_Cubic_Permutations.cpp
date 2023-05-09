/*
 The cube, 41063625 (345^3), can be permuted to produce two other cubes: 56623104 (384^3) and 66430125 (405^3). In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.

 Find the smallest cube for which exactly five permutations of its digits are cube.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    //map the sorted digits of cubed numbers to its occurrences and first original occurrence
    unordered_map<string, pair<int, string>> cubed_numbers;

    long long n = 0;
    while (++n){
        long long cubed = pow(n, 3);
        string original = to_string(cubed);
        string sorted = original;
        sort(sorted.begin(), sorted.end());

        //count stores number of occurrences of sorted cubed numbers.
        auto &[count, first_occurrence] = cubed_numbers[sorted];

        if (count == 0) {
            first_occurrence = original;
        }

        if (++count == 5) {
            cout << first_occurrence;
            return 0;
        }
    }
}
