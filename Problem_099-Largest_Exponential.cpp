/*
 Comparing two numbers written in index form like 2^11 and 3^7 is not difficult, as any calculator would confirm that (2^11 = 2048) < (3^7 = 2187).

 However, confirming that 632382^518061 > 519432^525806 would be much more difficult, as both numbers contain over three million digits.

 Using base_exp.txt (right click and 'Save Link/Target As...'), a 22K text file containing one thousand lines with a base/exponent pair on each line, determine which line number has the greatest numerical value.

 NOTE: The first two lines in the file represent the numbers in the example given above.
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    fstream infile("p099_base_exp.txt");
    double largest = 0;
    int line_number = 0;

    string num;
    for (int i = 1; getline(infile, num); ++i){
        size_t separator = num.find(',');
        int base = stoi(num.substr(0, separator));
        int exp = stoi(num.substr(separator + 1));
        //perform log on the number to scale it down.
        double number = exp * log10(base);
        if (number > largest){
            largest = max(number, largest);
            line_number = i;
        }
    }
    infile.close();
    cout << line_number;
}
