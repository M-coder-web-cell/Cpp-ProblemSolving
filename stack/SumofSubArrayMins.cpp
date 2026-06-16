#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> nextsmaller(vector<int>& nums){
    vector<int> res(nums.size());
    stack<int> st;

    for(int i = nums.size() - 1; i>=0; i--){

        while(!st.empty() && nums[st.top()] >= nums[i]){
            st.pop();
        }

        if(st.empty()) res[i] = nums.size();
        else res[i] = st.top();

        st.push(i);
    }
    return res;
}

vector<int> prevsmaller(vector<int>& nums){
    vector<int> res(nums.size());
    stack<int> st;
    
    for(int i = 0; i<nums.size(); i++){
        while(!st.empty() && nums[st.top()] > nums[i]){
            st.pop();
        }

        if(st.empty()) res[i] = -1;
        else res[i] = st.top();

        st.push(i);
    }
    return res;
}

long long MOD = 1e9 + 7;
int sumSubarrayMins(vector<int>& arr) {
    vector<int> nexts = nextsmaller(arr);
    vector<int> prevs = prevsmaller(arr);

    long long total = 0;

    for(int i = 0; i<arr.size(); i++){
        int sl = prevs[i];
        int sr = nexts[i];

        total += (i-sl)*(sr - i)*(long long)arr[i];
    }
    return total%MOD;
}

int main(){
    int n;
    cout<<"Enter No of input samples : ";
    cin >> n;
    
    while(n--){
        int t;
        cout<<"enter No of input elements in your vector: ";
        cin>>t;
        vector<int> nums;
        while(t--){
            int k;
            cin>>k;
            cout<<" ";
            nums.push_back(k);
        }
        cout << "answer of input sample " << n+1 << " is : "<< sumSubarrayMins(nums)<<endl;
    }


    return 0;
}