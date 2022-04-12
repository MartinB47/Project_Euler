/*
 Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

 (21) 22 23 24 (25)
 20  (7)  8  (9) 10
 19  6  (1)  2 11
 18  (5)  4  (3) 12
 (17) 16 15 14 (13)

 It can be verified that the sum of the numbers on the diagonals is 101.

 What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
 */

#include <iostream>
#include <cmath>
using namespace std;

int layernums(int layer){
    if (layer == 1) return 1;
    int nums = layer * 2;
    return (nums - 1) * 2 + (nums - 3) * 2;
}

long diagonalsum(int layer){
    if (layer == 1) return 1;
    int largest = 0;
    for (int i = 1; i<=layer; i++) largest += layernums(i);
    int sum = 0;
    for (int i = 0; i<=3; i++) sum += largest - i*(2*layer-2);
    return sum;
}

int main(){
    long diagonalsums = 0;
    int layer;
    for (int i = 1; i<=1001; i+=2){
        layer = (float(i)/2)+0.5;
        cout << layer << "th layer: " <<  endl;
        cout << i << " x " << i << ": " << diagonalsum(layer) << endl;
        diagonalsums += diagonalsum(layer);
    }
    cout << "Sum of numbers on the diagonals of a 1001 by 1001: " << diagonalsums << endl;
}





