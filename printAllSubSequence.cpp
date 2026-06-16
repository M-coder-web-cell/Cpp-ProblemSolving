#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void subseq(vector<int> nums, int idx,int n, vector<int> temp, vector<vector<int>> &ans){

    if(idx == n){
        ans.push_back(temp);
        return;
    } 
    subseq(nums, idx+1, n, temp, ans);

    temp.push_back(nums[idx]);
    subseq(nums, idx+1, n, temp, ans);


}
int main(){
    vector<int> nums = {1,2,3};

    vector<vector<int>> ans;
    vector<int> temp;
    int n = nums.size();
    subseq(nums, 0, n, temp, ans);
        
}