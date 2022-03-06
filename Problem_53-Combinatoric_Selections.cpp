#include <iostream>
using namespace std;

bool nCr_greater_than_a_milly(int n, int r){
    int num = n, den = n-r;
    double newer, result = num/double(den);
    while (num > r+1){
        num--, den--;
        result *= num/double(den);
        if (result > 1000000) return true;
        }
    return false;
}

int main(){
    int count = 0;
     for (int n = 2; n <= 100; n++){
        for (int r = 1; r < n; r++){
            if (nCr_greater_than_a_milly(n,r)) count++;
        }
    }
    cout << "There are " << count <<" nCrs where n is less than or equal to 100." << endl;
}
