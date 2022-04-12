/*
 Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

 1634 = 1^4 + 6^4 + 3^4 + 4^4
 8208 = 8^4 + 2^4 + 0^4 + 8^4
 9474 = 9^4 + 4^4 + 7^4 + 4^4
 As 1 = 1^4 is not a sum it is not included.

 The sum of these numbers is 1634 + 8208 + 9474 = 19316.

 Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.


 */

#include <iostream>
#include <cmath>
using namespace std;

int fifth_power_digits_sum(int n){
    int sum = 0;
    int num = n;
    while (num>=1){
        sum += pow(num%10,5);
        num -= (num%10);
        num /= 10;
    }
    return (sum==n);
}

int main(){
    int totalsum = 0;
    for (int i = 2; i<=100000000; i++){
        if (fifth_power_digits_sum(i)){
            totalsum += i;
            cout << i << endl;
        }
    }
    cout << "The total sum of numbers equal to the fifth power of their digits is " << totalsum << endl;
    
}
