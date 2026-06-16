#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> nextgreater(vector<int>& nums){


    stack<int> st;
    vector<int> res(nums.size());

    for(int i = nums.size() - 1; i>= 0; i--){
        int x = nums[i];

        while(!st.empty() && nums[st.top()] <= x){
            st.pop();
        }
        if(st.empty()) res[i] = -1;
        else res[i] = st.top();

        st.push(i);
    }
    return res;
}

vector<int> nextsmaller(vector<int>& nums){

    stack<int> st;
    vector<int> res(nums.size());

    for(int i = nums.size() - 1; i>= 0; i--){
        int x = nums[i];

        while(!st.empty() && nums[st.top()] >= x){
            st.pop();
        }
        if(st.empty()) res[i] = -1;
        else res[i] = st.top();

        st.push(i);
    }
    return res;
}

vector<int> prevgreater(vector<int>& nums){

    stack<int> st;
    vector<int> res(nums.size());

    for(int i = 0; i <nums.size(); i++){
        int x = nums[i];

        while(!st.empty() && nums[st.top()] < x){
            st.pop();
        }
        if(st.empty()) res[i] = -1;
        else res[i] = st.top();

        st.push(i);
    }
    return res;
}

vector<int> prevsmaller(vector<int>& nums){

    stack<int> st;
    vector<int> res(nums.size());

    for(int i = 0; i <nums.size(); i++){
        int x = nums[i];

        while(!st.empty() && nums[st.top()] > x){
            st.pop();
        }
        if(st.empty()) res[i] = -1;
        else res[i] = st.top();

        st.push(i);
    }
    return res;
}

long long subArrayRanges(vector<int>& nums){
    long long total = 0;
    vector<int> nextg = nextgreater(nums);
    vector<int> nexts = nextsmaller(nums);
    vector<int> prevg = prevgreater(nums);
    vector<int> prevs = prevsmaller(nums);

    for(int i = 0; i<nums.size(); i++){
        int gl = prevg[i];
        int gr = (nextg[i] == -1)? nums.size() : nextg[i];

        total += (i-gl)*(gr - i)*nums[i];

        int sl = prevs[i];
        int sr = (nexts[i] == -1)? nums.size() : nexts[i];

        total -= (i-sl)*(sr-i) * nums[i];
    }
    return total;
}

int main(){
    vector<int> nums = {4,-2,-3,4,1};
    cout << subArrayRanges(nums);

    return 0;
}