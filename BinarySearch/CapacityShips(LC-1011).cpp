#include <bits/stdc++.h>

using namespace std;

int isFeasible(vector<int>& weights, int target, int days){
    int subsets = 1;
    int total = 0;
    for(int w : weights){
        if(total + w > target){
            total = w;
            subsets++;

            if(subsets > days) return false;
        }else {
            total += w;
        }
    }
    return true;
}

int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    int ans = high;
    while(low <= high){
        int mid = low + (high - low)/2;

        if(isFeasible(weights, mid, days)){
            ans = mid;
            high = mid -1;
        }else {
            low = mid + 1;
        }
    }
    return ans;
}