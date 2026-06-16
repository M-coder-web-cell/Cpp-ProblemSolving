#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    int n = nums.size();
    
    // Sort the array to use the two-pointer approach
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 1; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int l = i + 1;
        int r = n - 1;

        while (l < r) {
            int currsum = nums[i] + nums[l] + nums[r];

            if (currsum < 0) {
                l++; 
            } else if (currsum > 0) {
                r--; 
            } else {
                res.push_back({nums[i], nums[l], nums[r]});

                while (l < r && nums[l] == nums[l + 1]) l++;
                while (l < r && nums[r] == nums[r - 1]) r--;

                l++;
                r--;
            }
        }
    }
    return res;
}
