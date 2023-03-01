#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> nums;
    for (int i = 0; i < 10; i++){
        nums.push_back(i);
    }
    
    for (int i = 0; i < 1000000 - 1; i++){
        next_permutation(nums.begin(), nums.end());
    }
    
    for (int num: nums){
        cout << num;
    }

    return 0;
}
