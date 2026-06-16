#include <iostream>
#include <vector>
#include <math.h>
#include <queue>


using namespace std;

int cutRod(vector<int> prices, int n, vector<int>dp){
    if(n==0) return dp[0]=0;
    if(dp[n] != -1) return dp[n];
    int q = INT_MIN;

    for(int i = 1; i<=n; i++){
        q = max(q, prices[i-1] + cutRod(prices, n-i, dp));
    }

    return dp[n] = q;
}

int main(){
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

    int n = prices.size();
    vector<int> dp(n, -1);

    cout<< "optimal price of length i is "<<cutRod(prices, 4, dp);
}