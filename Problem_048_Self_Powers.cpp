#include <bits/stdc++.h>
using namespace std;

//multiply a vector of length 10 by mult.
void multiply(vector<int> &nums, int mult){
    int carry = 0;
    for (int i = 9; i >= 0; i--){
        nums[i] = nums[i] * mult + carry;
        carry = nums[i] / 10;
        nums[i] %= 10;
    }
}

//returns the last 10 digits of n^n
vector<int> raise(int exp){
    vector<int> res(10);
    res[9] = 1;
    for (int i = 0; i < exp; i++){
        multiply(res, exp);
    }
    return res;
}

//returns the last 10 digits of nums1 + nums2
vector<int> add(const vector<int> &nums1, const vector<int> &nums2){
    vector<int> res(10);
    int carry = 0;
    for (int i = 9; i >= 0; i--){
        res[i] = nums1[i] + nums2[i] + carry;
        carry = (res[i] < 10) ? 0 : 1;
        res[i] %= 10;
    }
    return res;
}

int main(){
    vector<int> sum(10);
    for (int i = 1; i <= 1000; i++){
        sum = add(sum, raise(i));
    }
    for (const int &n: sum){
        cout << n;
    }
}
