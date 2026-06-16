#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int nextgreater(vector<int>& nums){
    int idx = -1;
    int rmin = nums[nums.size()-1];
    for(int i = nums.size() - 2; i>=0; i--){
        if(nums[i] < rmin) {
            idx = i;
            break;
        }
    }
    return idx;
}

int nextel(int n){
    stack<int> st;

    while(n>0){
        st.push(n%10);
        n/=10;
    }
    vector<int> nums;

    while(!st.empty()){
        nums.push_back(st.top());
        st.pop();
    }

    int res = nextgreater(nums);

    if(res != -1) {
        int temp = nums[res];
        nums[res] = nums[nums.size() - 1];
        nums[nums.size() - 1] = temp;
    }else return -1;
    
    string s = "";

    for(int i = 0; i<nums.size(); i++){
        s+=to_string(nums[i]);
    }

    return stoi(s);
}

int main(){
    cout << nextel(12) << endl;
    return 0;
}