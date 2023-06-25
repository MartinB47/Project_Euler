/*
 A common security method used for online banking is to ask the user for three random characters from a passcode. For example, if the passcode was 531278, they may ask for the 2nd, 3rd, and 5th characters; the expected reply would be: 317.

 The text file, keylog.txt, contains fifty successful login attempts.

 Given that the three characters are always asked for in order, analyse the file so as to determine the shortest possible secret passcode of unknown length.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    fstream infile("keylog.txt");
    //map digits to a set of digits that come after it
    unordered_map<char, unordered_set<char>> after;
    string num;
    while (infile >> num){
        //the 2nd and 3rd digits comes after the first
        after[num[0]].insert(num[1]);
        after[num[0]].insert(num[2]);
        
        //the 3rd digit comes after the second
        after[num[1]].insert(num[2]);
    }
    infile.close();
    
    //convert map to a vector so it can be sorted by the size of the sets
    vector<pair<char, unordered_set<char>>> after_sorted(after.begin(), after.end());
    
    //sort the vector based on the size of the unordered_set in descending order
    sort(after_sorted.begin(), after_sorted.end(), [](const auto &a, const auto &b){ return (a.second).size() > (b.second).size();});
    
    //print passcode digits
    for (const auto &p: after_sorted){
        cout << p.first;
    }
    
    //print the last digit. This step is much needed because the last digit of the
    //passcode doesn't have any subsequent digits, so it never appears in the vector.
    //this is done by printing what what follows the last digit in the set.
    //I hope I explained that correctly!
    cout << *after_sorted.back().second.begin();
}
