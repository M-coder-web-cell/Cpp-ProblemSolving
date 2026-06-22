//LC 523
#include <bits/stdc++.h>

using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    vector<int> prefix;
    int pre = 0;
    for(int num : nums){
        pre+=num;
        prefix.push_back(pre);
    }

    unordered_map<int, int> hash;
    for(int i = 0; i<prefix.size(); i++){
        if(hash[prefix[i]%k]){
            if(i - hash[prefix[i]%k]>= 2)return true;
        }else hash[prefix[i]%k] = i;
    }
    return false;
}