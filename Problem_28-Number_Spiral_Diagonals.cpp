#include <iostream>
#include <cmath>
#include<stdio.h>
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





