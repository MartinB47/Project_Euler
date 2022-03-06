#include <iostream>
#include <cmath>
using namespace std;

bool prime(int num) {
    if (num == 1 || num == 0) return false;
    for (int i = 2; i <= int(num / 2); i++) if (num % i == 0) return false;
    return true;
}

int prime_sums(int n){
    int diff;
    int count = 0;
    for (int i = n; i>=n/2; i--){
        if (prime(i)){
            diff = n-i;
            if (diff<=i){
                if (prime(diff)){
                    count += prime_sums(i);
                    count++;
            
                }
            }
        }
    }
    return count;
}



int main(){
    int max = 0;
    int sum = 0;
    int result = 0;
    int diff = 0;
    int diff2 = 0;
    for (int i = 0; i<=15000; i++){
        if (!prime(i)){
            result = prime_sums(i);
            if (result > max){
                max = result;
                cout << i << ": " << prime_sums(i) << endl;
                sum += result;
            }
        }
    }
    cout << "total: " << sum <<endl;
}

