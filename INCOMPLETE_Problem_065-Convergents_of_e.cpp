#include <bits/stdc++.h>
using namespace std;

//Define a function to calculate the greatest common divisor
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

//Define a function to simplify the fraction
void simplify(pair<long long, long long>& f) {
    long long n = gcd(f.first, f.second);
    f.first /= n;
    f.second /= n;
}

//Define a function to add a number to a fraction
void add(const long long n, pair<long long, long long>& f) {
    f = {n * f.second + f.first, f.second};
}

int main() {
    //Fill the sequence with appropriate values
    vector<long long> seq(100, 1);
    long long k = 1;
    for (long long i = 0; i < 100; i++) {
        if (i % 3 == 1)
            seq[i] = 2 * k++;
    }
    
    //Going above 45 will result in long long overflow.
    const long long n = 45;
    pair<long long, long long> f = {1, seq[n - 2]};

    for (long long i = n - 3; i >= 0; i--) {
        add(seq[i], f);
        //One over a fraction is just swapping its top and bottom
        swap(f.first, f.second);
        simplify(f);
    }

    add(2, f);

    cout << f.first << "/" << f.second << "\n";
    
    //Sum the digits of the numerator
    string numerator = to_string(f.first);
    long long sum = accumulate(numerator.begin(), numerator.end(), 0, [](long long sum, const char& ch) {
        return ch - '0' + sum;
    });

    cout << sum;

    return 0;
}
