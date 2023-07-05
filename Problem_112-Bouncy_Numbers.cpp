/*
 Working from left-to-right if no digit is exceeded by the digit to its left it is called an increasing number; for example, 134468.
 Similarly if no digit is exceeded by the digit to its right it is called a decreasing number; for example, 66420.
 We shall call a positive integer that is neither increasing nor decreasing a "bouncy" number; for example, 155349.
 Clearly there cannot be any bouncy numbers below one-hundred, but just over half of the numbers below one-thousand (525) are bouncy.
 In fact, the least number for which the proportion of bouncy numbers first reaches 50% is 538.
 Surprisingly, bouncy numbers become more and more common and by the time we reach 21780 the proportion of bouncy numbers is equal to 90%.
 Find the least number for which the proportion of bouncy numbers is exactly 99%.
 */

#include <bits/stdc++.h>
using namespace std;

//Check if a positive integer is bouncy by checking if its neither increasing nor decreasing
bool isBouncy(int n){
    //store digits of the number in reverse order in an array
    vector<int> digits;
    while (n){
        digits.push_back(n % 10);
        n /= 10;
    }
    
    bool increasing = true, decreasing = true;
    for (int i = 1; i < digits.size(); ++i){
        //since numbers are in reverse order, logic is inverted
        if (digits[i - 1] > digits[i]){
            decreasing  = false;
        }
        else if (digits[i - 1] < digits[i]){
            increasing = false;
        }
        
        if (!(decreasing || increasing)){
            //equivalent to (!decreasing && !increasing)
            return true;
        }
    }
    return false;
}

int main(){
    //proportion = 99%
    int i = 0, bouncy = 0, proportion = 99;
    do{
        if (isBouncy(++i)){
            ++bouncy;
        }
    } while (100 * bouncy != proportion * i);
    //equivalent to (bouncy / double(i) != proportion / double(100))
    
    cout << i;
    return 0;
}
