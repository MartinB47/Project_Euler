//
//  Problem_27-Quadratic_Primes.cpp
//  
//
//  Created by Martin Bobarshad on 1/13/22.
//

#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <cmath>
using namespace std;

int Prime(int num) {
    if (abs(num) == 1) return false;
    for (int i = 2; i <= int(abs(num / 2)); i++) if (abs(num) % i == 0) return false;
    return true;
}

int main(){
    int num;
    int count = 0;
    int conditions = 0;
    int n;
    for (int b = 461; b<=971; b++){
        if (Prime(b)){
            for (int a = -61; a<=41; a++){
                n = 70;
                for (int i = 0; i<=n; i++) if (Prime(pow(i,2)+i*a+b)) conditions++;
                if (conditions==n+1){
                    count++;
                    cout << "a value: " << a << endl;
                    cout << "b value: " << b << endl;
                    cout << "--------------" << endl;
                }
                conditions = 0;
            }
        }
    }
    cout << count << endl;
}
    




/*

 int main(){
     int num;
     int count = 0;
     int conditions = 0;
     int n;
     for (int b = -1000; b<=1000; b++){
         if (Prime(b)){
             for (int a = -999; a<=999; a++){
                 n = 60;
                 for (int i = 0; i<=n; i++) if (Prime(pow(i,2)+i*a+b)) conditions++;
                 if (conditions==n+1){
                     count++;
                     cout << "a value: " << a << endl;
                     cout << "b value: " << b << endl;
                     cout << "--------------" << endl;
                 }
                 conditions = 0;
             }
         }
     }
     cout << count << endl;
 }
     

 */

    
    /*
     int num;
    int count = 0;
    for (int i = -1000; i<=1000; i++){
        if (Prime(i)){
        }
    }
     */
