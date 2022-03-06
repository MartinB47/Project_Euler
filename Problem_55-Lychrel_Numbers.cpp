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
