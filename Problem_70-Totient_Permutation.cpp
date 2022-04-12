/*
 Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of positive numbers less than or equal to n which are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.
 The number 1 is considered to be relatively prime to every positive number, so φ(1)=1.

 Interestingly, φ(87109)=79180, and it can be seen that 87109 is a permutation of 79180.

 Find the value of n, 1 < n < 107, for which φ(n) is a permutation of n and the ratio n/φ(n) produces a minimum.
 */

#include <string>
#include <iostream>
using namespace std;
 
void permute(string s , string answer)
{
    if(s.length() == 0)
    {
        cout<<answer<<"  ";
        return;
    }
    for(int i=0 ; i<s.length() ; i++)
    {
        char ch = s[i];
        string left_substr = s.substr(0,i);
        string right_substr = s.substr(i+1);
        string rest = left_substr + right_substr;
        permute(rest , answer+ch);
    }
 
}
 
int main()
{
    string s;
    string answer="";
 
    cout<<"Enter the string : ";
    cin>>s;
 
    cout<<"\nAll possible strings are : ";
    permute(s , answer);
    return 0;
}
