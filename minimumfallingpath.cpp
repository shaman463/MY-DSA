#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        int n = matrix.size();
        if(j<0 || j>=n){
            return INT_MAX;
        }

        if(i == 0){
            return matrix[0][j];
        }
        if(dp[i][j] != INT_MAX) return dp[i][j];

        int up = solve(i - 1, j, matrix, dp);
        int leftDiag = solve(i - 1, j - 1, matrix, dp);
        int rightDiag = solve(i - 1, j + 1, matrix, dp);

    // Current cell value + minimum of the 3 possible previous moves
        return dp[i][j] = matrix[i][j] + min({up, leftDiag, rightDiag});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n,INT_MAX));
        int mini = INT_MAX;
        for(int i = 0; i<n; i++){
            mini = min(mini, solve(n-1,i,matrix,dp));
        }
        return mini;
    }
};

int main() {
    
    return 0;
}