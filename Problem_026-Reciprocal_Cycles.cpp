/*
 A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

 1/2    =     0.5
 1/3    =     0.(3)
 1/4    =     0.25
 1/5    =     0.2
 1/6    =     0.1(6)
 1/7    =     0.(142857)
 1/8    =     0.125
 1/9    =     0.(1)
 1/10    =     0.1
 Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

 Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
 */

#include <bits/stdc++.h>
using namespace std;

int cycle_length(int n){
    int i = 1, x = 1;
    while (true){
        x = (x * 10) % n;
        if (x == 1) return i;
        ++i;
    }
}

int main(){
    int max_d = 0, max_length = 0;
    for (int d = 2; d < 1000; d++){
        if (d % 2 == 0 || d % 5 == 0) continue;
        int length = cycle_length(d);
        if (length > max_length){
            max_length = length;
            max_d = d;
        }
    }
    cout << max_d;
}
