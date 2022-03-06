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
