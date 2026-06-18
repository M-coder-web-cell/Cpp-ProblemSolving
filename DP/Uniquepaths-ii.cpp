#include <bits/stdc++.h>
using namespace std;

int solve(int i,int j, vector<vector<int>>& dp, vector<vector<int>>& grid){
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;
    if(grid[i][j] == 1) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = solve(i-1, j, dp, grid) + solve(i, j-1, dp, grid);
}