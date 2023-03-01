/*
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

#include <bits/stdc++.h>
using namespace std;

int alphapos(string name){
    int sum = 0;
    for (char ch: name){
        sum += ch - 'A' + 1;
    }
    return sum;
}

int main(){
    ifstream file("names.txt");
    string name;
    vector<string> names;
    while (getline(file, name, ',')){
        name.erase(0, 1);
        name.erase(name.size() - 1);
        names.push_back(name);
    }
    sort(names.begin(), names.end());
    long long sum = 0;
    for (int i = 0; i < names.size(); i++){
        sum += alphapos(names[i]) * (i + 1);
    }
    cout << sum;
    return 0;
}
