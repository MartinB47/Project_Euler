#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool prime(int num){
    for (int i = 2; i < num/2; i++){
        if (num % i == 0) return false;
    }
    return true;
}

int sortNumber(int n){
    string s = to_string(n);
    sort(s.begin(), s.end());
    int y = stoi(s);
    return y;
}

bool permutations(int a, int b){
    if (sortNumber(a) == sortNumber(b)) return true;
    return false;
}

int main(){
    for (int i = 1000; i < 10000; i++){
        if (prime(i)){
            int first = i;
            int max = ((10000 - first) / 2);
            for (int j = 1; j <= max; j++){
                int second = first + j;
                if (permutations(first, second)){
                    if (prime(second)){
                        int third = second + j;
                        if (permutations(second, third)){
                            if (prime(third)){
                                cout << first << ", " << second << ", " << third << endl;
                            }
                        }
                    }
                }
            }
        }
    }
}
