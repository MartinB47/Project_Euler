/*
 Consider quadratic Diophantine equations of the form:

 x^2 – Dy^2 = 1

 For example, when D=13, the minimal solution in x is 649^2 – 13×180^2 = 1.

 It can be assumed that there are no solutions in positive integers when D is square.

 By finding minimal solutions in x for D = {2, 3, 5, 6, 7}, we obtain the following:

 3^2 – 2×2^2 = 1
 2^2 – 3×1^2 = 1
 9^2 – 5×4^2 = 1
 5^2 – 6×2^2 = 1
 8^2 – 7×3^2 = 1

 Hence, by considering minimal solutions in x for D ≤ 7, the largest x is obtained when D=5.

 Find the value of D ≤ 1000 in minimal solutions of x for which the largest value of x is obtained.
 */

#include <iostream>
#include <cmath>
using namespace std;

int euclidiangcd(long a, long b) {
    long larger = a;
    long smaller = b;
    while (true){
        if (larger<smaller){
            smaller = a;
            larger = b;
        }
        int r = larger % smaller;
        if (r==0) return smaller;
        larger = smaller;
        smaller = r;
    }
}
int main(){
    int max_x = 88751;
    for (int d = 426; d<=1000; d++){
        bool flag = true;
        for (int x = max_x; x<=max_x+10000; x++){
            if (!flag) break;
            for (int y = 3000; y<=13000; y++){
                if (!flag) break;
                if ((pow(x,2) - d * pow(y,2)) == 1){
                    flag = false;
                    cout << "D right now: " << d << endl;
                    if (x > max_x){
                        max_x = x;
                        cout << "D: " << d << endl;
                        cout << "x: " << x << endl;
                        cout << "y: " << y << endl;
                        cout << "---------" << endl;
                    }
                }
            }
        }
    }
}

/*
int main(){
    int max_x = 33281;
    for (int d = 65; d<=1000; d++){
        bool flag = true;
        for (int x = max_x; x<=40000; x++){
            if (!flag) break;
            for (int y = 1; y<=10000; y++){
                if (!flag) break;
                if ((pow(x,2) - d * pow(y,2)) == 1){
                    flag = false;
                    cout << "D right now: " << d << endl;
                    if (x > max_x){
                        max_x = x;
                        cout << "D: " << d << endl;
                        cout << "x: " << x << endl;
                        cout << "y: " << y << endl;
                        cout << "---------" << endl;
                    }
                }
            }
        }
    }
}
 */
