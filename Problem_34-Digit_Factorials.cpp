/*
 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

 Find the sum of all numbers which are equal to the sum of the factorial of their digits.

 Note: As 1! = 1 and 2! = 2 are not sums they are not included.
 */
#include <iostream>
#include <cmath>
using namespace std;


long long int factorial(int num){
    long long int product = 1;
    for (int i = 1; i<=num; i++) product *= i;
    return product;
}

int Curious(int n){
    int fact_sum = 0;
    int num = n;
    while (num != 0){
        fact_sum += factorial(num%10);
        num =  (num - num%10) / 10;
    }
    if (fact_sum == n) return true;
    return false;
}

               
               
int main(){
    int sum = 0;
    for (int i = 3; i<=1000000; i++){
        if (Curious(i)) sum+=i;
    }
    cout << "The sum of curious numbers is: " << sum << endl;
}
