#include <iostream>
using namespace std;

bool abundant(int n) {
    int sum = 1;
    for (int i = 2; i <= (n / 2); i++){
        if (n % i == 0) sum += i;
        if (sum > n) return true;
    }
    return false;
}

bool sum_of_two_abundants(int n){
    for (int a = 1; a<= n/2; a++){
        if (abundant(a)){
            if (abundant(n-a)) return true;
        }
    }
    return false;
}


int main(){
    long totalsum = 0;
    long abundantsum = 0;
    for (int i = 1; i<=28123; i++){
        totalsum += i;
        if (sum_of_two_abundants(i)) abundantsum += i;
    }
    cout << totalsum - abundantsum << endl;
}

