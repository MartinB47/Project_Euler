/*
 Pentagonal numbers are generated by the formula, Pn=n(3n−1)/2. The first ten pentagonal numbers are:

 1, 5, 12, 22, 35, 51, 70, 92, 117, 145, ...

 It can be seen that P4 + P7 = 22 + 70 = 92 = P8. However, their difference, 70 − 22 = 48, is not pentagonal.

 Find the pair of pentagonal numbers, Pj and Pk, for which their sum and difference are pentagonal and D = |Pk − Pj| is minimised; what is the value of D?
 */

#include<iostream>
#include <cmath>
using namespace std;

bool quadratic_solution(int a, int b, long long int c){
    double solution_p = ( (-1*b) + sqrt( b*b-4*a*c) ) / (2*a) ;
    //double solution_n = ( (-1*b) - sqrt( b*b-4*a*c) ) / (2*a);
    if (solution_p == int(solution_p)) return true;
    return false;
}

bool pentagonal(long long int num){
    return (quadratic_solution(3, -1, -2*num));
}

long long int nth_pentagonal(int n){
    return ((3*n*n-n)/2);
}

int main(){
    int num1, num2, count1, count2;
    count1 = count2 = 0;
    for (int a = 1; a<=10000; a++){
        for (int b = 1; b<=10000; b++){
            num1 = nth_pentagonal(a);
            num2 = nth_pentagonal(b);
            if (pentagonal(num1+num2)){
                count1++;
                if (pentagonal(abs(num1-num2))){
                    count2++;
                    cout << "num1: " << num1 << endl;
                    cout << "num2: " << num2 << endl;
                    cout << "difference: " << abs(num1 - num2) << endl;
                    cout << "--------" << endl;
                }
            }
        }
    }
    
        cout << count1 << endl << count2 << endl;
}




/*
 int main(){
     int count1 = 0;
     int count2 = 0;
     int count3 = 0;
     int count4 = 0;
     for (int a = 1; a<=100000; a++){
         for (int b = 1; b<=100000; b++){
             if (pentagonal(3*a*a - a + 3*b*b-b)){
                 count3++;
                 if (pentagonal(abs(3*a*a - a - 3*b*b + b) )){
                     count4++;
                     if pentagonal( (3*a*a - 3)/2)
                         cout << "a: " << a << endl;
                 }
             }
         }
     }
     cout << "done" << endl;
     cout << count1 << endl << count2 << endl << count3 << endl << count4 << endl;
 }
 */


/*
 
 int main(){
     int count1 = 0;
     int count2 = 0;
     int count3 = 0;
     int count4 = 0;

     for (int a = 10000000; a<=30000000; a++){
         if (pentagonal(a)){
             count1++;
             for (int b = 10000000; b<=30000000; b++){
                 if (pentagonal(b)){
                     count2++;
                     if (pentagonal(abs(a-b))){
                         count3++;
                         if (pentagonal(a+b)){
                             count4++;
                             cout << "a: " << a << endl;
                             cout << "b: " << b << endl;
                         }
                     }
                 }
             }
         }
     }
     cout << "done" << endl;
     cout << count1 << endl << count2 << endl << count3 << endl << count4 << endl;
 }
 */
