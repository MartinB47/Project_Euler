#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


bool prime(int num) {
    if (num == 1) return false;
    for (int i = 2; i <= int(num / 2); i++) if (num % i == 0) return false;
    return true;
}


int duplicates(int array[], int size){
    int count = 0;
    for(int i=0; i<size; i++){
       for(int j=i+1; j<size; j++){
           if(array[i] == array[j]){
                   count++;
                   break;
            }
        }
    }
    return count;
}
int * prime_power_triple(int num){
    int index = 0;
    static int power_triples[1139575];
    for (int square = 2; square <= 7072; square++){
        int result = 0;
        if (prime(square)){
            for (int cube = 2; cube <= 369; cube++){
                if (prime(cube)){
                    for (int fourth = 2; fourth <= 85; fourth++){
                        if (prime(fourth)){
                            result = pow(square,2) + pow(cube,3) + pow(fourth,4);
                            if (result <= num){
                                power_triples[index++] = result;
                                //cout << result << endl;
                                //cout << " = " << square << " " << cube << " " << fourth << endl;
                            }
                        }
                    }
                }
            }
        }
    }
    return power_triples;
}
    
int main(){
    int *numbers;
    int size = 1139575;
    numbers = prime_power_triple(50000000);
    sort(numbers, numbers + 1139575);
    
    for (int i = 0; i<size; i++){
        cout << numbers[i] << endl;
    }
    
    //cout << "Duplicates: " << duplicates(numbers, 1139575);
}
