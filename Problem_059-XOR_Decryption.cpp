#include <bits/stdc++.h>
using namespace std;

//text is english if alphanumeric and space characters comprise >87% of the text.
bool is_english(const string &text, double threshold = 0.87){
    int english = 0;
    for (const char ch: text){
        if (isalnum(ch) || ch == ' ') english++;
    }
    return (static_cast<double> (english) / text.size() >= threshold);
}

//function prototype
void decrypt(const vector<int> &encrypted, int k, string key);

int main(){
    fstream infile("p059_cipher.txt");
    string num;
    vector<int> encrypted;
    while (getline(infile, num, ',')){
        encrypted.push_back(stoi(num));
    }
    infile.close();
    
    decrypt(encrypted, 3, "");
}

//generate keys of length k and decrypt the encrypted file into a string.
void decrypt(const vector<int> &encrypted, int k, string key = ""){
    if (key.size() == k){
        string decrypted;
        int index = 0;
        for (const int &code: encrypted){
            decrypted += char(code ^ int(key[index++ % k]));;
        }
        
        //sums all ASCII codes of decrypted.
        if (is_english(decrypted)){
            int sum = 0;
            for (const char &ch: decrypted){
                sum += ch;
            }
            cout << sum;
            exit(0);
        }
    }
    else{
        for (char ch = 'a'; ch <= 'z'; ch++){
            decrypt(encrypted, k, key + ch);
        }
    }
}
