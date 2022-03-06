#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;


int countdigits(int n) {
    if (n == 0) return 1;
    double x;
    x = 1 + floor (log10(abs(n)));
    return x;
}


int nthdigit(long num, int digit) {
    int desired;
    long int n = num;
    for (int i = 1; i <= digit; i++) {
        desired = n % 10;
        n -= desired;
        n /= 10;
    }
    return desired;
}

bool zero_detector(int n){
    for (int i = 1; i<=countdigits(n); i++) if (nthdigit(n, i) == 0) return true;
    return false;
}

long pandigital(long num){
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

long formnumber(int a, int b, int c){
    string s1 = to_string(a);
    string s2 = to_string(b);
    string s3 = to_string(c);
    string s = s1 + s2 + s3;
    
    int d = stoi(s);
    return d;
}



int main(){
    int product, product2, sum, sum2, count1, count2;
    count1 = count2 = sum = sum2 = 0;
    for (int a = 1; a<=5000; a++){
        for (int b = 1; b<=5000; b++){
            if (a<b){
                product = a*b;
                if ((countdigits(a)+countdigits(b)+countdigits(product)) == 9) {
                    if (pandigital(formnumber(a, b, product)) && !(zero_detector(formnumber(a, b, product)))){
                        
                        cout << a << " x " << b << " = " << product << endl;
                        //cout << product << endl;
                        count1++;
                        sum += product;

                        for (int c = a+1; c<=5000; c++){
                            for (int d = 1; d<=5000; d++){
                                if (c<d){
                                    product2 = c*d;
                                    if ((countdigits(c)+countdigits(d)+countdigits(product2)) == 9) {
                                        if (pandigital(formnumber(c, d, product2)) && !(zero_detector(formnumber(c, d, product2)))){
                                            if (product2 == product){
                                                cout << "found a duplicate" << endl;
                                                cout << "The duplicate is " << c << " x " << d << "= " << product2 << endl;
                                                count2++;
                                                sum-=product2;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        cout << " ---------" << endl << endl;
                    }
                }
            }
        }
    }
    //cout << "Count: " << count1 << endl;
    //cout << "Duplicates: " << count2 << endl;
    cout << "Sum of Products: " << sum << endl << endl;
}


/*
int main(){
    int product, sum, index;
    bool flag = true;
    sum = index = 0;
    int products[70];
    for (int a = 1; a<=5000; a++){
        for (int b = 1; b<=5000; b++){
            if (a<b){
                product = a*b;
                if ((countdigits(a)+countdigits(b)+countdigits(product)) == 9) {
                        if (pandigital(formnumber(a, b, product))){
                            cout << a << " x " << b << " = " << product << endl;
                            cout << " ---------" << endl;
                            products[index] = product;
                            index++;
                            sum += product;
                        }
                }
            }
        }
    }
    cout <<" Total sum: " << sum << endl << endl;
    
    
    
    for (int i = 0; i<=65; i++){
        cout << i << ": " << products[i] << endl;
    }
}
*/
