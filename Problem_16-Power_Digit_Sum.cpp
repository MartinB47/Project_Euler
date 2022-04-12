/*
 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

 What is the sum of the digits of the number 2^1000?
 */

#include <iostream>
#include<cmath>
#include <math.h>
using namespace std;

void raise_2(int *array){
    for (int i = 0; i<=302; i++){
        array[i] = array[i] * 2;
        //cout << array[i] << endl;
    }
}

void reform_nums(int *array){
    int carry = 0;
    for (int i = 301; i >= 0; i--){
        if (array[i]+carry < 10){
            array[i] = array[i] + carry;
            carry = 0;
        }
        else{
            array[i] = (array[i] + carry) % 10;
            carry = 1;
        }
        //cout << i << ": " << array[i] << endl;
    }
}

int main(){
    int numbers[302] = { 0 };
    int length = 10;
    numbers[301] = 2;
    
    for (int i = 1; i < 1000; i++){
        //cout << "2 raised to the " << i+10 << " power: " << endl;
        raise_2(numbers);
        reform_nums(numbers);
    }
    int sum = 0;
    for (int i = 0; i<=302; i++){
        cout << i << ": " << numbers[i] << endl;
        sum += numbers[i];
    }
    cout << "The sum of the digits of 2^1000 is " << sum << endl;
}










/*

void doublearray(int *array, int size){
    for (int i = 0; i < size; i++) array[i] *= 2;
}

void printarray(int *array, int size){
    for (int i = 0; i < size; i++) cout << array[i] << endl;
}

void remainders(int *array, int size){
    for (int i = 0; i < size; i++) array[i] %= 10;
}

void carries(int *array, int size){
    for (int i = 0; i < size; i++){
        if(array[i] < 10) array[i] = 0;
        else array[i] = 1;
    }
}

void add(int *remainder, int *carry, int *array, int size){
    for (int i = 0, j =; i < size; i++){
        
    }
}

int main(){
    int sum[3] = {2,5,6};
    doublearray(sum,3);
    int remainder[3] = {4,10,12}, carry[3] = {4,10,12};
    remainders(remainder,3);
    carries(carry,3);

    printarray(sum,3);
    cout << "-----" << endl;
    printarray(remainder,3);
    cout << "-----" << endl;
    printarray(carry,3);

    
}

*/



/*
inline int findcarry(int n) { return (n-(n%10))/10;}

int main(){
    int sum[500];
    int length = 1;
    int carry = 0;
    sum[0] = 2;
    for (int i = 0; i<=length; i++){
        cout << sum[0] << endl;
        cout << sum[0] * 2 << endl;
        carry =
        cout << "carry: " <<

    }
}

*/





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

/*
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
    raise(10);
}

*/
