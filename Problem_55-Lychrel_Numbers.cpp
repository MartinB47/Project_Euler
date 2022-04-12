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

#include <iostream>
#include <cmath>
using namespace std;

int countdigits(int n) {
    if (n == 0) return 1;
    double x;
    x = 1 + floor (log10(abs(n)));
    return x;
}

int reverse(int n){
    int num = n;
    int digits = countdigits(num);
    int digit;
    int index = 1;
    int reversed = 0;
    while (num>=1){
        digit = num % 10;
        reversed += digit*pow(10,digits-index);
        num = (num-digit)/10;
        index++;
    }
    return reversed;
}


bool palindrome(int n) {
    int current, reversed = 0;
    int copy = n;
    do
    {
        current = copy % 10;
        reversed = current + (reversed * 10);
        copy /= 10;
    } while (copy != 0);
    if (n == reversed) return true;
        else return false;
}


bool lychrel(int n){
    long long int result = n;
    int count = 0;
    while (count < 50){
        result += reverse(result);
        if (palindrome(result)) return false;
        count++;
    }
    return true;
}

int main(){
    int count = 0;
    for (int i = 0; i<10000; i++) if ((lychrel(i))) count++;
    cout << "There are " << count << " lychrel numbers" << endl;
}
