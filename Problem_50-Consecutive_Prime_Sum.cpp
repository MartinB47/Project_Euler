#include <iostream>
using namespace std;



bool prime(int num) {
    if (num == 1) return false;
    for (int i = 2; i <= int(num / 2); i++) if (num % i == 0) return false;
    return true;
}


int nextprime(int num) {
    int next_prime = ++num;
    while (!prime(next_prime)) next_prime++;
    return next_prime;
}

int main(){
    long sum = 0;
    long num;
    long current_prime = 2;
    int count = 0;
    int max_count = 0;
    int max_prime = 0;
    
    
    
    
    for (int num = 1000000; num>=1; num--){
        if (prime(num)){
            
            
            sum = 0;
            current_prime = 7; // Problem was solved by manually changing the starting prime number. Adjust the program so that it gives you the prime that sums the most consecutive primes starting at every prime number until current_prime = num.
            count = 0;
            while (sum < num){
                sum += current_prime;
                //cout << "current prime: " << current_prime << endl;
                current_prime = nextprime(current_prime);
                //cout << "sum is now: " << sum << endl;
                //cout << " -------- " << endl;
                count++;
            }
        }
        
        if (sum == num){
            cout << "The number " << num << " sums " << count << " prime numbers." << endl;
        }
    }
            
            
            
            
/*
            if (count > max_count){
                max_count = count;
                max_prime = num;
            }
 */
            
    
    cout << max_prime << " sums " << max_count << " consecutive primes." << endl;
}

