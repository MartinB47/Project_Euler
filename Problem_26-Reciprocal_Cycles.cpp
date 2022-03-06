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

bool pandigital(int num){
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


/*
long nthdecimal(int n, int d){
    int q, r;
    long decimal_int = 1;
    string decimals = "";
    r = n;
    
    while(pandigital(decimal_int)){
        int num = r*10;
        q = num/d;
        r = num%d;
        //cout << "q: " << q << endl;
        //cout << "r: " << r << endl;
        decimals += to_string(q);
        decimal_int = stoi(decimals);
        //cout << decimal_int << endl;
        //cout << "---------" << endl;
    }
    
    
    //cout << "final: " << decimal_int << endl;
    return (decimal_int-(decimal_int%10))/10;

}
*/

void nthdecimal(int n, int d){
    int q, r, count, initial_r;
    r = n;
    
    while(true){
        int num = r*10;
        q = num/d;
        r = num%d;
        cout << "q: " << q << endl;
        cout << "r: " << r << endl;
        cout << "---------" << endl;
        count++;
    }
    
    
    cout << "count: " << count << endl;
}

int main(){
    nthdecimal(1,23);
    
    
    
    
    
    /*long max = 1;
    long result;
    for (int i = 204; i<=1000; i++){
        result = nthdecimal(1,i);
        cout << "i: " << i << endl;
        if (result > max){
            cout << 1 << "/" << i << endl;
            cout << result << endl;
            cout << "--------" << endl;
            max = result;
        }
    }
     */
}
