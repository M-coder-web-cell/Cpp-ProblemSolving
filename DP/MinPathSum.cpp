#include <bits/stdc++.h>

using namespace std;

//Using Top down approach
int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid){
    if(i==0 && j==0) return grid[0][0];
    if(i<0 || j<0) return 1e9;
    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = grid[i][j] + min(solve(i-1, j, dp, grid), solve(i, j-1, dp, grid));
}

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int> (n, -1));
    return solve(m-1, n-1, dp, grid);
}

//using bottom up tabulation
int minPathSumTab(vector<vector<int>>& grid){

    int m = grid.size();
    int n = grid[0].size();
    for(int i = 0; i < m; i++){
        for(int j = 0; j<n; i++){
            if(i-1 < 0 && j-1 <0) continue;
            else if(i-1 < 0) grid[i][j] += grid[i][j-1];
            else if(j-1 < 0) grid[i][j] += grid[i-1][j];
            else {
                grid[i][j] = grid[i][j] + min(grid[i-1][j], grid[i][j-1]);
            }
        }
    }
    return grid[m-1][n-1];
}