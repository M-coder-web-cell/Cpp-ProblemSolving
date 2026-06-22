#include <bits/stdc++.h>

using namespace std;

vector<int> rearrangeArray(vector<int>& nums){
    int posidx = 0;
    int negidx = 1;
    int n = nums.size();

    vector<int> res(n);

    for(int i = 0; i< n; i++){
        if(nums[i] < 0){
            res[negidx] = nums[i];
            negidx+=2;
        }
        else {
            res[posidx] = nums[i];
            posidx +=2;
        }
    }
    return res;
}

int main(){
    vector<int> nums = {3, 1, -2, -5, 2, -4};

    vector<int> res = rearrangeArray(nums);

    for(int num : res){
        cout << num << " ";
    }
    return 0;
}
