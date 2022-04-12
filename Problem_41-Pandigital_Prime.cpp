/*
 We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

 What is the largest n-digit pandigital prime that exists?
 */

#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

bool Prime(long num) {
    if (num == 1) return false;
    for (long long int i = 2; i <= num / 2; i++) if (num % i == 0) return false;
    return true;
}


int countdigits(long n) {
    if (n == 0) return 1;
    double x;
    x = 1 + floor (log10(abs(n)));
    return x;
}

int nthdigit(long num, int digit) {
    int desired;
    long int n = num;
    for (int i = 1; i <= digit; i++) {
        desired = n % 10;
        n -= desired;
        n /= 10;
    }
    return desired;
}

int pandigital(long num){
    int i, j, digits;
    digits = countdigits(num);
    for (i = 1; i <= digits; i++){
        for (j = 1; j <= digits; j++){
            if (i!=j){
                if (nthdigit(num,i) == nthdigit(num,j)) return false;
            }
        }
    }
    return true;
}

int formnumber(int a, int b, int c){
    return a*100 + b*10 + c;
}



int main(){
    long d1d2d3, d4d5d6, d7d8d9, finalnum;
    int digits = 7;
    bool flag = true;
    for (int d1 = digits; d1>= 1; d1--){
        for (int d2 = digits; d2>= 1; d2--){
            for (int d3 = digits; d3>= 1; d3--){
                d1d2d3 = formnumber(d1,d2,d3);
                 if (pandigital(d1d2d3) && flag){
                    for (int d4 = digits; d4>= 1; d4--){
                        for (int d5 = digits; d5>= 1; d5--){
                            for (int d6 = digits; d6>= 1; d6--){
                                d4d5d6 = formnumber(d4,d5,d6);
                                for (int d7 = digits; d7>= 1; d7--){
                                    finalnum = d1d2d3*pow(10,4) + d4d5d6*10 + d7;
                                    if (pandigital(finalnum) && flag){
                                        cout << "Num: " << finalnum << endl << endl;
                                         if (Prime(finalnum)){
                                            cout << "The largest pandigital prime is " << finalnum << endl;
                                            flag = false;
                                         }
                                    }
                                }
                            }
                        }
                    }
                 }
            }
        }
    }
}
