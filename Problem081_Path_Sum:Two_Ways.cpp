/*
 In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by only moving to the right and down, is indicated in bold red and is equal to 2427.
 
    {*131, 673, 234 , 103 , 18  }
    {*201, *96, *342, 965 , 150 }
    {630 , 803, 746 , *422, 111 }
    {537 , 699, 497 , *121, 956 }
    {805 , 732, 524 , *37 , *331}
 
 Find the minimal path sum from the top left to the bottom right by only moving right and down in matrix.txt (right click and "Save Link/Target As..."), a 31K text file containing an 80 by 80 matrix.
 */

#include <bits/stdc++.h>
using namespace std;

//set the size of the matrix
const int matrix_size = 80;
vector<vector<int>> dp;
//finds minimal path sum of matrix using bottom-up dynamic programming.
int minPath(const vector<vector<int>> &matrix) {
    dp[0][0] = matrix[0][0];
    
    //initialize the first row and column of the dp matrix
    for (int i = 1; i < matrix_size; i++) {
        dp[i][0] = dp[i - 1][0] + matrix[i][0];
        dp[0][i] = dp[0][i - 1] + matrix[0][i];
    }
    
    //fill the dp matrix with the minimum path sums
    for (int i = 1; i < matrix_size; i++) {
        for (int j = 1; j < matrix_size; j++) {
            dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[matrix_size - 1][matrix_size - 1];
}

int main() {
    vector<vector<int>> matrix(matrix_size, vector<int>(matrix_size));
    dp.assign(matrix_size, vector<int>(matrix_size));
    
    //read the matrix from the input file
    ifstream infile("p081_matrix.txt");
    string line;
    for (int i = 0; i < matrix_size; i++) {
        getline(infile, line);
        stringstream ss(line);
        string num;
        for (int j = 0; j < matrix_size; j++) {
            getline(ss, num, ',');
            matrix[i][j] = stoi(num);
        }
    }
    infile.close();

    cout << minPath(matrix);
    return 0;
}
