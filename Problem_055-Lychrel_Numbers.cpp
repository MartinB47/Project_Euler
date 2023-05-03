/*
 If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

 Not all numbers produce palindromes so quickly. For example,

 349 + 943 = 1292,
 1292 + 2921 = 4213
 4213 + 3124 = 7337

 That is, 349 took three iterations to arrive at a palindrome.

 Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome. A number that never forms a palindrome through the reverse and add process is called a Lychrel number. Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise. In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome. In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).

 Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.

 How many Lychrel numbers are there below ten-thousand?

 NOTE: Wording was modified slightly on 24 April 2007 to emphasise the theoretical nature of Lychrel numbers.
 */

#include <bits/stdc++.h>
using namespace std;

//checks if num is read the same backwards
bool isPalindrome(const vector<int> &num){
    for (int i = 0; i < num.size() / 2; i++){
        if (num[i] != num[num.size() - 1 - i]){
            return false;
        }
    }
    return true;
}

//adds the reverse of num to itself
void addReverse(vector <int> &num){
    const vector<int> num1(num);
    int carry = 0;
    for (int i = num1.size() - 1; i >= 0; i--){
        num[i] += carry + num1[num1.size() - 1 - i];
        carry = num[i] / 10;
        num[i] %= 10;
    }
    if (carry) num.insert(num.begin(), 1);
}

//check if number is Lychrel after less than 50 iterations
bool isLychrel(vector<int> num){
    int i = 50;
    while (--i){
        addReverse(num);
        if (isPalindrome(num)){
            return false;
        }
    }
    return true;
}

//converts integers to a vector of their digits
vector<int> initialize(int n){
    vector<int> res;
    while (n > 0){
        res.push_back(n % 10);
        n /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    int count = 0;
    for (int i = 0; i < 10000; i++){
        if (isLychrel(initialize(i))){
            cout << i << "\n";
            count++;
        }
    }
    cout << count;
}
