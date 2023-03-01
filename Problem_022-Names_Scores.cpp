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
