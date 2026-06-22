#include <bits/stdc++.h>

using namespace std;

int dp[20001][4];
int Helper(vector<int>& subarray, int count, int i, int k){
    if(count == 0) return 0;
    if(i >= subarray.size()){
        return INT_MIN;
    }
    if(dp[i][count] != -1) return dp[i][count];

    int take = subarray[i] + Helper(subarray, count - 1, i+k, k);
    int not_take = Helper(subarray, count, i+1, k);

    return dp[i][count] = max(take, not_take);

}
void solve(vector<int>& subarray, int count, int i, int k, vector<int>& res){
    if(count == 0) return;
    if(i >= subarray.size()) return;

    int start_sub_i = subarray[i] + Helper(subarray, count-1, i+k, k);
    int notstart_sub_i = Helper(subarray, count, i+1, k);

    if(start_sub_i >= notstart_sub_i){
        res.push_back(i);
        solve(subarray, count-1, i+k, k, res);
    }else {
        solve(subarray, count, i + 1, k, res);
    }

}
vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k){
    memset(dp, -1, sizeof(dp));
    int n = nums.size();
    int i = 0;
    int j = 0;
    vector<int> subarray;
    int sum = 0;

    //getting the sums for k-length sybarray according to starting index;
    while(j < n){
        sum += nums[j];
        if(j-i+1 == k){
            subarray.push_back(sum);
            sum -= nums[i];
            i++;
        }
        j++;
    }

    vector<int> res;
    solve(subarray, 3, 0, k, res);

    return res;
}