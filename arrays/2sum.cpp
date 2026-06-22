#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> twosum(vector<int>& nums, int target){
    int n = nums.size();
    vector<pair<int, int>> res;
    unordered_map<int, int> hash;

    for(int i = 0; i<n; i++){
        int req = target - nums[i];
        if(hash.find(req) != hash.end()){
            res.push_back({hash[req], i});
        }
        hash[nums[i]] = i;
    }

    return res;
}

int main(){
    vector<int> nums = {2, 7, 2, 15, 4, 5};
    int target = 9;

    vector<pair<int, int>> res = twosum(nums, target);

    for(auto& it : res){
        cout << "{ "<< it.first << " , "<< it.second<< " }"<<endl;
    }
    return 0;
}