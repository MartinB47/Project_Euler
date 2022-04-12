/*
 Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
 How many such routes are there through a 20×20 grid?
 */
#include <iostream>
using namespace std;

long long int factorial(int num){
    long long int product = 1;
    for (int i = 1; i<=num; i++) product *= i;
    return product;
}

long long int n_choose_k(int n, int k){
    return factorial(n) / (factorial(k) * factorial(n-k));
}

int main(){
    cout << n_choose_k(40, 20) << endl;
}
