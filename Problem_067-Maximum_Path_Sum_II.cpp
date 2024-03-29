/*
 By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

 3
 7 4
 2 4 6
 8 5 9 3

 That is, 3 + 7 + 4 + 9 = 23.

 Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.

 NOTE: This is a much more difficult version of Problem 18. It is not possible to try every route to solve this problem, as there are 299 altogether! If you could check one trillion (1012) routes every second it would take over twenty billion years to check them all. There is an efficient algorithm to solve it. ;o)
 */

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> triangle;
    int rows = 100;
    triangle.reserve(rows);
    for (int i = 0; i < rows; i++){
        triangle.emplace_back(i + 1);
    }
    
    fstream infile("triangle.txt");
    for (int i = 0; i < rows; i++){
        for (int j = 0; j <= i; j++){
            int num;
            infile >> num;
            triangle[i][j] = num;
        }
    }
    infile.close();
    
    vector<vector<int>> dp(rows, vector<int>(rows, 0));
    for (int j = 0; j < rows; j++){
        dp[rows -1][j] = triangle[rows - 1][j];
    }
    
    for (int i = rows - 2; i >= 0; i--){
        for (int j = 0; j <= i; j++){
            dp[i][j] = triangle[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    
    cout << dp[0][0];
}
