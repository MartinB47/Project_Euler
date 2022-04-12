/*
 It turns out that 12 cm is the smallest length of wire that can be bent to form an integer sided right angle triangle in exactly one way, but there are many more examples.

 12 cm: (3,4,5)
 24 cm: (6,8,10)
 30 cm: (5,12,13)
 36 cm: (9,12,15)
 40 cm: (8,15,17)
 48 cm: (12,16,20)

 In contrast, some lengths of wire, like 20 cm, cannot be bent to form an integer sided right angle triangle, and other lengths allow more than one solution to be found; for example, using 120 cm it is possible to form exactly three different integer sided right angle triangles.

 120 cm: (30,40,50), (20,48,52), (24,45,51)

 Given that L is the length of the wire, for how many values of L ≤ 1,500,000 can exactly one integer sided right angle triangle be formed?
 */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/*
int main(){
    int index = 0, count = 0, L = 100;
    int sums[100000];
    for (int a = 2; a <= L/2; a++){
        for (int b = a; b <= L/2; b++){
            double c = sqrt(pow(a,2) + pow(b,2));
            if (c == int (c)){
                if (a+b+c <= L){
                    int sum = a+b+c;
                    //cout << a << " " << b << " " << c << endl;
                    cout << "sum: " << a+b+c << endl;
                    cout << "diff: " << sum - c << endl;
                    count++;
                    cout << "------" << endl;
                }
            }
        }
    }
    cout << "total count: " << count << endl;
}
 */

 

int integer_triangle(int l){
    int index = 0, count = 0, sum;
    for (int a = 2; a <= l/3; a++){
        for (int b = a; b <= l/2; b++){
            double c = sqrt(pow(a,2) + pow(b,2));
            if (c == int(c)){
                if (a+b+c == l) return true;
            }
        }
    }
    return false;
}

/*
int main(){
    int count = 0, sum;
    for (int l = 1; l<=100; l++){
        if (integer_triangle(l)){
            cout << l << endl;
            cout << "----" << endl;
            count++;
        }
    }
    cout << "total count: " << count << endl;
    cout << "----------------" << endl;
}
*/


int main(){
    int count = 0, count2 = 0;
    int sums[260000], index = 0;
    for (int n = 1; n <= 613; n++){
        for (int m = n+1; m <= 865; m++){
            int a = pow(m,2) - pow(n,2);
            int b = 2 * m * n;
            int c = pow(m,2) + pow(n,2);
            int sum = a+b+c;
            if (sum <= 1500000){
                sums[index++] = sum;
                count++;
            }
        }
    }
    //cout << "count: " << count << endl;
    //cout << "count 2: " << count2 << endl;
    
    
    int count3 = 0;
    for (int i = 0; i < 9500; i++){
        for (int j = i+1; j<9500; j++){
            //cout << i << " " << j << endl;
            if (sums[i] == sums[j]){
                //cout << "the " << i <<"and " << j << " problematic" << endl;
                //count3++;
                cout << "sum = " << sums[i] << endl;
            }
        }
    }
    cout << "count3: " << count3 << endl;
}


/*
int main(){
    int index = 0, count = 0, sum;
    int l = 120;
    for (int a = 2; a <= l/3; a++){
        for (int b = a; b <= l/2; b++){
            double c = sqrt(pow(a,2) + pow(b,2));
            if (c == int(c)){
                sum = a+b+c;
                if (sum == l){
                    //cout << a << " " << b << " " << c << endl;
                    //cout << l << endl;
                    //cout << "c/a: " << c / double(a) << endl;
                    //cout << "c/b: " << c / double(b) << endl;
                    //cout << "b/a: " << b / double(a) << endl;
                    //cout << "----" << endl;
                    
                    if (sum/double(a) < 3.4)
                        cout << "sum/a: " << sum / double(a) << endl;
                    //cout << "sum/b:" << sum / double(b) << endl;
                    //cout << sum / double(c) << endl;
                    count++;
                }
            }
        }
    }
    cout << "total count: " << count << endl;
    cout << "----------------" << endl;
}
*/
