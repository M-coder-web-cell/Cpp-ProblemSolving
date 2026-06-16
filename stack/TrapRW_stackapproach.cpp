#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> nextgreater(vector<int>& nums){
    stack<int> st;
    vector<int> res(nums.size());

    int n = nums.size();

    vector<int> suffix_maxidx;
    if(n>0){
        suffix_maxidx[n-1] = n-1;
        for(int i = n-2; i>=0; i--){
            if(nums[i] >= nums[suffix_maxidx[i+1]]){
                suffix_maxidx[i] = i;
            }else suffix_maxidx[i] = suffix_maxidx[i+1];
        }
    }
    for(int i = nums.size() - 1; i>=0; i--){

        while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();

        if(st.empty()){
            if(i = n-1) res[i] = -1;
            else res[i] = suffix_maxidx[i+1];
        }
        else {
            res[i] = st.top();
        }

        st.push(i);
    }

    return res;
}
int trap(vector<int>& height) {
    int lbound = height[0];
    vector<int> nextg = nextgreater(height);
    int i = 0;
    int total = 0;
    while(i<height.size()){

        if(nextg[i] == -1) break;
        int temp = i+1;
        int rboundidx = nextg[i] -1;

        int maxh = min(height[i], height[nextg[i]]);

        while(rboundidx >= temp){
            total += maxh - height[rboundidx];
            rboundidx--;
        }
        i = nextg[i];
    }
    return total;

}

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout<< trap(height) << endl;
    return 0;
}