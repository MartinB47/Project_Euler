#include <iostream>
using namespace std;


void numbers_below_left(int step, int column){
    cout << ++step << " " << column << endl;
}
void numbers_below_right(int step, int column){
    cout << ++step << " " << ++column << endl;
    
}





int main(){
    numbers_below_left(4,3);
    cout << "-----------" << endl;
    numbers_below_right(4,3);
}
    
    
    
    string s = "03070402040608050903";
    /*
    int num = 1;
    int tens = 1;
    int ones = 0;
    for (int i = 1; i<=15; i++){
        cout << i << ": " << ones << "," << tens << endl;
        cout << "num is " << num << endl;
        cout << "------" << endl;
        tens+=2, ones += 2;
        num += i;
    }
     */
    
    
    /*
    int first = 0;
    int last = 1;
    int num = 0;
    int step = 1;
    for (int i = 1; i<=15; i++){
        for (int j = 0; j<step; j++){
            
            //cout << s[first] << s[last] << " ";
            cout << first << last << " ";

            first+=2, last+=2;
            //cout << "s: " << step <<" ";
            
        }
        cout << endl;

        step++;

    }
     */
