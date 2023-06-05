/*
 It is possible to show that the square root of two can be expressed as an infinite continued fraction.
 √ 2 = 1 + 1/(2 + 1/(2 + 1/(2 + ... ))) = 1.414213...
 By expanding this for the first four iterations, we get:
 1 + 1/2 = 3/2 = 1.5
 1 + 1/(2 + 1/2) = 7/5 = 1.4
 1 + 1/(2 + 1/(2 + 1/2)) = 17/12 = 1.41666...
 1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29 = 1.41379...
 The next three expansions are 99/70, 239/169, and 577/408, but the eighth expansion, 1393/985, is the first example where the number of digits in the numerator exceeds the number of digits in the denominator.
 In the first one-thousand expansions, how many fractions contain a numerator with more digits than denominator?
 */

#include <bits/stdc++.h>
using namespace std;

//function to add two vectors, treating each as the digits of an integer
vector<int> add(const vector<int> &nums1, const vector<int> &nums2){
    int i = nums1.size() - 1, j = nums2.size() - 1;
    int carry = 0;
    vector<int> res;
    
    while (i >= 0 || j >= 0 || carry){
        int sum = carry;
        
        //add value of digit to sum if that digit of the number exists
        if (i >= 0){
            sum += nums1[i--];
        }
        if (j >= 0){
            sum += nums2[j--];
        }
        
        res.push_back(sum % 10);
        carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    int count = 0;
    //initial fraction (ignoring the +1)
    vector<int> numerator = {1};
    vector<int> denominator = {2};
    
    for (int i = 2; i <= 1000; i++){
        //to add 2, add 2*denominator to the numerator
        vector<int> two = add(denominator, denominator);
        numerator = add(numerator, two);
        
        //to evaluate 1 / (num / den), swap top and bottom.
        swap(numerator, denominator);
        
        //to add 1, add denominator to numerator
        vector<int> oneAdded_numerator = add(numerator, denominator);
        
        if (oneAdded_numerator.size() > denominator.size()){
            ++count;
        }
    }
    cout << count;
}
