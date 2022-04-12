/*
 If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

 {20,48,52}, {24,45,51}, {30,40,50}

 For which value of p ≤ 1000, is the number of solutions maximised?
 */

#include <iostream>
#include <cmath>
using namespace std;





int main(){
    int count = 0;
    int max = 0;
    int a , b, p, maxp;
    double c;
    for (p = 1; p<1000; p++){
        
        for (a = 1; a < 1000; a++){
            for (b = 1; b < 1000; b++){
                c = pow((pow(a,2) + pow(b,2)),0.5);
                double d = (int) c;
                    if (d == c && a+b+c == p){
                        count++;
                    }
            }
        }
        
        if (count > max){
            max = count;
            maxp = p;
        }
        count = 0;

    }
    cout << "At p = " << maxp << ", the number of trianglar variations are maximized" << endl;
}


/*
 cout << "a: " << a << endl;
cout << "b: " << b << endl << endl;
cout << "c: " << c << endl;
cout << "d: " << d << endl;
cout << "-------------" << endl;
count++;
 */
