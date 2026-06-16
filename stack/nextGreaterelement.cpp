#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> nextgreater(vector<int>& nums){

    stack<int> st;
    vector<int> res(nums.size());

    for(int i = nums.size() - 1; i>= 0; i--){

        int x = nums[i];

        while(!st.empty() && st.top() <= x){
            st.pop();
        }
        //if no greater element exists
        if(st.empty()) res[i] = -1;
        else res[i] = st.top();

        st.push(x);
    }
    return res;
}

int main(){
    vector<int> arr = {1, 3, 2, 4};
    vector<int> res = nextgreater(arr);

    for(int num : res){
        cout<< num << " ";
    }

    return 0;

}