/*
 An irrational decimal fraction is created by concatenating the positive integers:

 0.12345678910(1)112131415161718192021...

 It can be seen that the 12th digit of the fractional part is 1.

 If dn represents the nth digit of the fractional part, find the value of the following expression.

 d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
 */

#include <iostream>
#include <string>
using namespace std;

char champernowne(int n){
    string s = "";
    int num = 1;
    while (n>=s.length()){
        string s1 = to_string(num);
        s += s1;
        num++;
    }
    return s[n-1];
}
int main(){
    int product = 1;
    int digit;
    for (int i = 1; i<=1000000; i*=10){
        digit = champernowne(i)-48;
        cout << i << ": " << digit << endl;
        product *= digit;
    }
    cout << "Product: " << product << endl;
}
