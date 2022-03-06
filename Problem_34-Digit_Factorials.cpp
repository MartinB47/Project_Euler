//
//  Problem_34-Digit_Factorials.cpp
//  
//
//  Created by Martin Bobarshad on 1/14/22.
//

#include <stdio.h>
#include<stdlib.h>
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
