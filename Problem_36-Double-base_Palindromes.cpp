/*
 The decimal number, 585 = 1001001001 (base two) (binary), is palindromic in both bases.

 Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

 (Please note that the palindromic number, in either base, may not include leading zeros.)
 */
#include <iostream>
#include<iomanip>
using namespace std;


bool palindrome(int n) {
    int current, reversed = 0;
    int copy = n;
    do
    {
        current = copy % 10;
        reversed = current + (reversed * 10);
        copy /= 10;
    } while (copy != 0);
    if (n == reversed) return true;
        else return false;
}


int main(){
    int count = 0;
    for (int i = 1; i<=1000000; i++){
        if (palindrome(i)) count++;
    }
    cout << bin << count << endl;
}
