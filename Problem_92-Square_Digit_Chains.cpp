/*
 A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.

 For example,

 44 → 32 → 13 → 10 → 1 → 1
 85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89

 Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.

 How many starting numbers below ten million will arrive at 89?
 */
#include <iostream>
#include <cmath>
using namespace std;

int sum_digits_squared(int n){
    int sum = 0;
    int num = n;
    int digit;
    while (num != 0){
        digit = num%10;
        sum += pow(digit,2);
        num = (num-digit) / 10;
    }
    return sum;
}

int main(){
    int count = 0;
    for (int i = 1; i<=10000000; i++){
        int chain = i;
        cout << "number: " << chain << endl;
        while (true){
           chain = sum_digits_squared(chain);
           //cout << chain << endl;
           if (chain == 1) break;
           if (chain == 89){
               count++;
               break;
           }
       }
        //cout << "--------" << endl;
    }
    cout << "total of 89 ending chains: " << count << endl;
}
