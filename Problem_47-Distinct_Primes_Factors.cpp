/*
 The first two consecutive numbers to have two distinct prime factors are:

 14 = 2 × 7
 15 = 3 × 5

 The first three consecutive numbers to have three distinct prime factors are:

 644 = 2² × 7 × 23
 645 = 3 × 5 × 43
 646 = 2 × 17 × 19.

 Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?
 */

#include <iostream>
using namespace std;


int Prime(long num) {
    if (num == 1) return false;
    for (long i = 2; i <= long(num / 2); i++) if (num % i == 0) return false;
    return true;
}

int distincts(long n){
    if (n == 1 || Prime(n)) return 1;
    int num = n;
    int distinct, count;
    distinct = count = 0;

    for (int i = 2; i<=n/2;){
        if (num % i == 0 && Prime(i)){
            count++;
            num /= i;
        }
        else{
            if (count) distinct++;
            count = 0;
            i++;
        }
    }
    return distinct;
}

int main(){
    long num = 1;
    while (!(distincts(num) == 4 && distincts(num+1) == 4 && distincts(num+2) == 4 && distincts(num+3) == 4)) num++;
    cout << "The first four consecutive numbers to have four distinct prime factors starts from " << num << "." << endl;
}
