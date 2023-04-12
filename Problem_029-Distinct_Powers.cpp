#include<bits/stdc++.h>
using namespace std;

//returns the distinct prime factors of a number, along with
//their power.
vector<pair<int, int>> prime_factorization(int n){
    vector<pair<int, int>> factors;
    int p = 2;
    while (n > 1){
        int power = 0;
        while (n % p == 0){
            n /= p;
            power++;
        }
        if (power){
            factors.push_back({p, power});
        }
        p++;
    }
    return factors;
}

//raises the number to a 'power'.
void raise(vector<pair<int, int>> &factors, int power){
    for (auto &f: factors){
        f.second *= power;
    }
}

//checks if two numbers are equal by using their prime factorization
bool isEqual(const vector<pair<int, int>> &factors1, const vector<pair<int, int>> &factors2){
    if (factors1.size() != factors2.size()) return false;
    for (int i = 0; i < factors1.size(); i++){
        if (factors1[i] != factors2[i]){
            return false;
        }
    }
    return true;
}

int main(){
    vector<vector<pair<int, int>>> nums;
    for (int a = 2; a <= 100; a++){
        for (int b = 2; b <= 100; b++){
            auto factors = prime_factorization(a);
            raise(factors, b);
            bool found = false;
            //determine whether the number has already been added to nums.
            for (const auto &f: nums){
                if (isEqual(factors, f)){
                    found = true;
                    break;
                }
            }
            if (!found){
                nums.push_back(factors);
            }
        }
    }
    cout << nums.size();
}
