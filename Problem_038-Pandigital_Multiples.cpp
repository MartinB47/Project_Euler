/*
 Take the number 192 and multiply it by each of 1, 2, and 3:

 192 × 1 = 192
 192 × 2 = 384
 192 × 3 = 576
 By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)

 The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

 What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?
 */

#include <bits/stdc++.h>
using namespace std;

//check if a string is a 1 - 9 pandigital
bool pandigital(string s){
    unordered_set<char> digits;
    for (const char &d: s){
        if (d != '0'){
            digits.insert(d);
        }
    }
    return (digits.size() == 9);
}

//concatenate n * {1, 2, ..., k} until its size becomes 9.
string concatenated_product(int n){
    string res;
    int i = 1;
    while (res.size() < 9){
        res += to_string(n * i++);
    }
    return ((res.size() == 9) ? res: "");
}

int main(){
    string max_res;
    for (int i = 9000; i <= 9999; i++){
        string s = concatenated_product(i);
        if (!s.empty() && pandigital(s)){
            max_res = max(max_res, s);
        }
    }
    cout << max_res;
}
