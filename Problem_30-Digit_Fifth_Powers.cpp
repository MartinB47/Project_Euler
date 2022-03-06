#include<stdio.h>
#include<stdlib.h>
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
