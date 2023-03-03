#include <iostream>
#include <vector>
using namespace std;

int main() {
    //input the triangle
    vector<vector<int>> triangle;
    int rows = 15;
    triangle.reserve(rows);
    for (int i = 0; i < rows; i++) {
        triangle.emplace_back(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }
    
    //initialize dp with the bottom row filled out
    vector<vector<int>> dp(rows, vector<int>(rows, 0));
    for (int j = 0; j < rows; j++) {
        dp[rows - 1][j] = triangle[rows - 1][j];
    }
    
    //start woarking our way up from the 2nd to last row
    //We'll update dp as we go up.
    for (int i = rows - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = triangle[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    
    //print maximum path sum
    cout << dp[0][0] << endl;

    return 0;
}
