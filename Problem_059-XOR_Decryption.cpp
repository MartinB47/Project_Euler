/*
 Each character on a computer is assigned a unique code and the preferred standard is ASCII (American Standard Code for Information Interchange). For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.

 A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR each byte with a given value, taken from a secret key. The advantage with the XOR function is that using the same encryption key on the cipher text, restores the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65.

 For unbreakable encryption, the key is the same length as the plain text message, and the key is made up of random bytes. The user would keep the encrypted message and the encryption key in different locations, and without both "halves", it is impossible to decrypt the message.

 Unfortunately, this method is impractical for most users, so the modified method is to use a password as a key. If the password is shorter than the message, which is likely, the key is repeated cyclically throughout the message. The balance for this method is using a sufficiently long password key for security, but short enough to be memorable.

 Your task has been made easy, as the encryption key consists of three lower case characters. Using p059_cipher.txt (right click and 'Save Link/Target As...'), a file containing the encrypted ASCII codes, and the knowledge that the plain text must contain common English words, decrypt the message and find the sum of the ASCII values in the original text.
 */

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
