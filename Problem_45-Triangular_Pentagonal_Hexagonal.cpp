#include <iostream>
#include <cmath>
using namespace std;

bool quadratic_solution(int a, int b, long long int c){
    double solution_p = ( (-1*b) + sqrt( b*b-4*a*c) ) / (2*a) ;
    //double solution_n = ( (-1*b) - sqrt( b*b-4*a*c) ) / (2*a);
    if (solution_p == int(solution_p)) return true;
    return false;
}
bool triangular(long long int num){
    return (int (quadratic_solution(1, 1, -2*num)));
}
bool pentagonal(long long int num){
    return (quadratic_solution(3, -1, -2*num));
}
bool hexagonal(long long int num){
    return (quadratic_solution(2, -1, -1*num));
}

int main(){
    long long int num = 40755;
    while (true){
        num++;
        if (triangular(num) && pentagonal(num) && hexagonal(num)) break;
    }
    cout << "The next triangular, pentagonal, and hexagonal number after 40755 is " << num << endl;
}

