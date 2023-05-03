/*
 The 5-digit number, 16807=7^5, is also a fifth power. Similarly, the 9-digit number, 134217728=8^9, is a ninth power.

 How many n-digit positive integers exist which are also an nth power?
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int count = 0;
    //upper bound of n is 21.
    const int limit = -1 * (1 / (log10(9) - 1));
    for (int n = 1; n <= limit; n++){
        //upper bound of x is 9.
        for (int x = 1; x < 10; ++x) {
            int res = static_cast<int>(n * log10(x)) + 1;
            if (res == n){
                ++count;
            }
        }
    }
    cout << count;
}
