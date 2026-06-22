#include <bits/stdc++.h>

using namespace std;


void nextPermutation(vector<int>& nums) {
    int n = nums.size();

    int gola_idx = -1;

    for(int i = n-1; i>0; i--){
        if(nums[i-1] < nums[i]){
            gola_idx = i - 1;
            break;
        } 
    }
    if(gola_idx == -1){
        reverse(nums.begin(), nums.end());
        return;
    } 

    for(int j = n-1; j>gola_idx; j--){
        if(nums[j] >nums[gola_idx]){
            swap(nums[gola_idx], nums[j]);
            break;
        }
    }
    reverse(nums.begin() + gola_idx + 1, nums.end());
}

int main(){

    vector<int> arr = {1, 2, 3};
    nextPermutation(arr);
    for(int num : arr){
        cout << num << " ";
    }
    return 0;
}