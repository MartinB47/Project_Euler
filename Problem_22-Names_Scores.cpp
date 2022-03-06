#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int alphabetical_value(string s) {
	int sum = 0;
	for (int i = 0; i <= s.length() - 1; i++) sum += s[i] - 64;
	return sum;
}

int main(){
    ifstream file(".txt");
    string data = "";
    while(getline(file, data,','))
    {
      cout << data << endl;
    }
    file.close();
}
