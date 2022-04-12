/*
 The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

 We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

 There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

 If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
 */
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
