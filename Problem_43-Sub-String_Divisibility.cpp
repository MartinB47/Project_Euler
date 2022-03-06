#include <iostream>
#include <cmath>
#include<stdio.h>
using namespace std;

/*
int Prime(int num) {
    if (num == 1) return false;
    for (int i = 2; i <= int(num / 2); i++) if (num % i == 0) return false;
    return true;
}

int nextprime(int prime) {
    int nextprime = ++prime;
    while (!Prime(nextprime)) nextprime++;
    return nextprime;
}

bool divisibility(int num, int divisor){
    if (num%divisor==0) return true;
    return false;
}


bool divisibility_property(int num){
    
    int divisor = 2;
    int i, j;
    for (i = 9; i >= 3; i--){
        if (!(divisibility( formnumber(nthdigit(num, i), nthdigit(num, i-1), nthdigit(num, i-2)), divisor))){
            return false;
        }
        divisor = nextprime(divisor);
    }
    return true;
}
 

int main(){
    int count = 0;
    int num;
    for (long long int i = 123456789; i<=200000000; i++){
        num = formnumber(nthdigit(i,3), nthdigit(i,2), nthdigit(i,1));
        if (num == 867 || num == 289){
            count++;
        }
    }
    cout << "Count is " << count << endl;
}
 */


int formnumber(int a, int b, int c){
    return a*100 + b*10 + c;
}

int nthdigit(long int num, int digit) {
    int desired;
    long int n = num;
    for (int i = 1; i <= digit; i++) {
        desired = n % 10;
        n -= desired;
        n /= 10;
    }
    return desired;
}

int countdigits(long n) {
    if (n == 0) return 1;
    double x;
    x = 1 + floor (log10(abs(n)));
    return x;
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

int main(){
    long d2d3d4, d3d4d5, d4d5d6, d5d6d7, d6d7d8, d7d8d9, d8d9d10, last9, finalnum, finalsum;
    int count = 0;
    for (int d2 = 0; d2<=9;d2++){
        for (int d3 = 0; d3<=9;d3++){
            for (int d4 = 0; d4<=9;d4++){
                d2d3d4 = formnumber(d2,d3,d4);
                if (pandigital(d2d3d4) && d2d3d4%2==0){
                    for (int d5 = 0; d5<=9;d5++){
                        d3d4d5 = formnumber(d3,d4,d5);
                        if (pandigital(d3d4d5) && d3d4d5%3==0){
                            for (int d6 = 0; d6<=9;d6++){
                                d4d5d6 = formnumber(d4,d5,d6);
                                if (pandigital(d4d5d6) && d4d5d6%5==0){
                                    for (int d7 = 0; d7<=9;d7++){
                                        d5d6d7 = formnumber(d5,d6,d7);
                                        if (pandigital(d5d6d7) && d5d6d7%7==0){
                                            for (int d8 = 0; d8<=9;d8++){
                                                d6d7d8 = formnumber(d6,d7,d8);
                                                if (pandigital(d6d7d8) && d6d7d8%11==0){
                                                    for (int d9 = 0; d9<=9;d9++){
                                                        d7d8d9 = formnumber(d7,d8,d9);
                                                        if (pandigital(d7d8d9) && d7d8d9%13==0){
                                                            for (int d10 = 0; d10<=9; d10++){
                                                                d8d9d10 = formnumber(d8,d9,d10);
                                                                if (pandigital(d8d9d10) && d8d9d10%17==0){
                                                                    last9 = d2d3d4*pow(10,6) + d5d6d7*1000 + d8d9d10;
                                                                    if (pandigital(last9) && last9>=pow(10,8)){
                                                                        for (int d1 = 1; d1<=9; d1++){
                                                                            finalnum = d1*pow(10,9) + last9;
                                                                            if (pandigital(finalnum)){
                                                                                cout << "Final Number: " << finalnum << endl;
                                                                                finalsum += finalnum;
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
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "The sum of finalized numbers is " << finalsum << endl;
}
