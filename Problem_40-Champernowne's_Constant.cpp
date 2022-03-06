#include <iostream>
#include <string>
using namespace std;

char champernowne(int n){
    string s = "";
    int num = 1;
    while (n>=s.length()){
        string s1 = to_string(num);
        s += s1;
        num++;
    }
    return s[n-1];
}
int main(){
    int product = 1;
    int digit;
    for (int i = 1; i<=1000000; i*=10){
        digit = champernowne(i)-48;
        cout << i << ": " << digit << endl;
        product *= digit;
    }
    cout << "Product: " << product << endl;
}
