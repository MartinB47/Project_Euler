#include<stdio.h>
#include <iostream>
#include <cmath>
using namespace std;


int Prime(int num) {
    if (num == 1) return false;
    for (int i = 2; i <= int(num / 2); i++) if (num % i == 0) return false;
    return true;
}

int countdigits(int n){
    return ceil(log10(n));
}

int nthdigit(int n, int digit){
    int desired;
    int num = n;
    for (int i = 1; i <= digit; i++) {
        desired = num % 10;
        num -= desired;
        num /= 10;
    }
    return desired;
}


 void rotations(int num){
     int digits = countdigits(num);
     int rotation = 0;
     int power, i, j;
     for (i = digits-1; i>=0; i--){
         power = digits-1;
         rotation = 0;
         for (j = digits-1; j>=0; j--){
            rotation += pow(10,power) * nthdigit(num , (i+j) % digits + 1);
             power--;
         }
         cout << rotation << endl;
     }
}





int main(){
    int count, count2, num, digits, rotation, power, i, j;
    count = count2 = 0;
    for (num = 1; num<=1000000;num++){
        
        if (Prime(num)){
            digits = countdigits(num);
            rotation = 0;
            
            for (i = digits-1; i>=0; i--){
               power = digits-1;
               rotation = 0;
                for (j = digits-1; j>=0; j--){
                    rotation += pow(10,power) * nthdigit(num , (i+j) % digits + 1);
                    power--;
               }
                cout << rotation << endl;
                if (Prime(rotation)) count2++;
            }
            cout << "----------" << endl;
        }
        if (count2 == digits){
            count++;
            cout << "Circular Prime!" << endl;
        }
        count2 = 0;
    }
    cout << "Total Circular Primes: " << count << endl;
}
   
