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
