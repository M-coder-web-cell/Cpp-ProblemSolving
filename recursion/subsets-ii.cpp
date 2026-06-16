#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void backtrack(vector<int>& nums, int idx, vector<int>& subset, vector<vector<int>>& allsubsets, map<vector<int>, int>& mpp){
    if(idx == nums.size()){
        if(!mpp[subset]) {
            mpp[subset] = 1;
            allsubsets.push_back(subset);
        }
        return;

    }
    //take or not-take decision

    //if we dont take the el at idx -
    backtrack(nums, idx+1, subset, allsubsets, mpp);

    //if we take the el at idx
    subset.push_back(nums[idx]);
    backtrack(nums, idx+1, subset, allsubsets, mpp);
    subset.pop_back();

}

int main(){

    vector<vector<int>> numsarr = {{1, 2, 2}, {0}, {4, 4, 4, 1, 4}};

    for( auto nums : numsarr){
        
        //check the 3rd input of numsarr [4,4,4,1,4] , here it will cause error without sortng because 1,4 and 4,1 will be flagged as 
        //different by mpp, but according to question constraints we have to consider them same 
        sort(nums.begin(), nums.end());

        vector<int> subset = {};
        vector<vector<int>> allsubsets = {};
        map <vector<int>, int> mpp;

        backtrack(nums, 0, subset, allsubsets, mpp);
        for (const auto& sub : allsubsets) {
            cout << "[ ";
            for (int num : sub) {
                cout << num << " ";
            }
            cout << "] ";
        }

        cout << "\n";
    }

}