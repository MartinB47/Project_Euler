/*
 The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.

 Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

 (Please note that the palindromic number, in either base, may not include leading zeros.)
 */

#include <bits/stdc++.h>
using namespace std;

//reverses a string
string reverse(string s){
    for (int i = 0; i < s.size() / 2; i++){
        swap(s[i], s[s.size() - 1 - i]);
    }
    return s;
}

//checks if a string is read the same backwards
bool palindrome(string s){
    return s == reverse(s);
}

//convert an integer to its binary representation
string toBinary(int n){
    string res;
    while (n != 0){
        res += to_string(n % 2);
        n /= 2;
    }
    return reverse(res);
}

int main(){
    int sum = 0;
    for (int i = 1; i < pow(10,6); i++){
        string s = to_string(i);
        if (palindrome(s) && palindrome(toBinary(i))){
            sum += i;
        }
    }
    cout << sum << "\n";
}
