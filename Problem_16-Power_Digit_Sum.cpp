#include <iostream>
#include<math.h>
using namespace std;
/*
void solution(int exponent) {

    int order = 0;
    int digits = 302;
    int number[digits];
    number[0] = 1;

    for (int i = 0; i < exponent; i++) {
        int carry = 0;
        for (int j = 0; j <= order; j++) {
            
            int product = 2 * number[j] + carry;
            number[j] = product % 10;
            carry = product / 10;
            if (j == order && carry > 0) {
                order++;
            }
          
        }
        
    }
    for (int i = 20; i>=0; i--){
        cout <<"Number " << i <<": " << number[i] << endl;
    }
    cout << "------------" << endl << endl;
   
}
*/

void raise(int exponent) {

    int order = 0;
    int digits = 302;
    int number[digits];
    number[0] = 1;

    for (int i = 0; i < exponent; i++) {
        int carry = 0;
        for (int j = 0; j <= order; j++) {
            int product = 2 * number[j] + carry;
            cout << "product is " << product << endl;
            number[j] = product % 10;
            cout << "The " << j <<"th number is " << product % 10 << endl;
            carry = product / 10;
            cout << "The carry is " << carry << endl;
            cout << "------------" << endl << endl;
            if (j==order && carry > 0){
                order++;
                cout << "Order:  " << order << endl;
            }
        }
    }
    for (int i = order; i>=0; i--){
        cout <<"Number " << i <<": " << number[i] << endl;
    }
    cout << "------------" << endl << endl;
   
}

int main(){
    raise(20);
}
