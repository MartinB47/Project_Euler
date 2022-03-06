#include <iostream>
using namespace std;

int nthdigit(int num, int digit) {
    int desired;
    int n = num;
    for (int i = 1; i <= digit; i++) {
        desired = n % 10;
        n -= desired;
        n /= 10;
    }
    return desired;
}

int main(){
    int ndigit, ddigit, ndigit2, ddigit2, nproduct, dproduct;
    nproduct = dproduct = 1;
    for (int n = 10; n<=99; n++){
        for (int d = 10; d<=99; d++){
            if (n!=d){
                ndigit = nthdigit(n,1);
                ddigit = nthdigit(d,2);
                
                if (ndigit == ddigit){
                    ndigit2 = nthdigit(n, 2);
                    ddigit2 = nthdigit(d, 1);
                    
                    if (n/double(d) == ndigit2/ double(ddigit2)){
                        nproduct *= ndigit2;
                        dproduct *= ddigit2;
                    }
                }
            }
        }
    }
    cout << "The Product of curious fractions is: " << nproduct << "/" << dproduct << "." << endl;
}
