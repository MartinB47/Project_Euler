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
