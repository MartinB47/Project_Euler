#include <iostream>
#include <algorithm>
using namespace std;

int *add_arrays(int *arr1, int *arr2, int size){
    int *res = new int[size];
    int carry = 0;
    for (int i = size - 1; i >= 0; i--){
        int sum = arr1[i] + arr2[i] + carry;
        res[i] = sum % 10;
        carry = (sum > 9) ? 1 : 0;
    }
    return res;
}

int main() {
    int size = 1001;
    int count = 3;
    int arr1[size], arr2[size];

    fill_n(arr1, size, 0);
    fill_n(arr2, size, 0);

    arr1[size - 1] = arr2[size - 1] = 1;
    int *sum = add_arrays(arr1, arr2, size);
    while (sum[1] == 0){
        sum = add_arrays(arr1, arr2, size);
        count++;
        for (int i = 0; i < size; i++){
            arr1[i] = arr2[i];
            arr2[i] = sum[i];
        }
    }
    delete[] sum;
    cout << count - 1 << endl;
}
