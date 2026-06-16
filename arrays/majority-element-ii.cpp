#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> majorityelement(vector<int>& nums){
    unordered_map <int, int> hash;

    for(int num : nums){
        if(!hash[num]) hash[num]=1;
        else hash[num]++;
    }

    int n = nums.size();
    vector<int> res;
    for(auto it = hash.begin(); it!=hash.end(); it++){
        if(it->second > n/3) res.push_back(it->first);
    }

    return res;

}

int main(){
    vector<int> arr = {3,2,3};
    vector<int> out = majorityelement(arr);

    for(int n : out){
        cout<< n << " ";
    }
    return 0;
}