#include <bits/stdc++.h>

using namespace std;

vector<int> firstNegInt(vector<int>& arr, int k) {
    queue<int> q;
    vector<int> res;

    for(int i = 0; i<arr.size(); i++){
        if(arr[i] < 0) q.push(i);

        if(!q.empty() && q.front() < i-k+1 ){
            q.pop();
        }
        if(i>=k-1){
            if (!q.empty()) {
                res.push_back(arr[q.front()]);
            } else {
                res.push_back(0); // No negative number in this window
            }            
        }

    }
    return res;
}

int main(){
    vector<int> nums = {-8, 2, 3, -6, 10};

    vector<int> res = firstNegInt(nums, 2);

    for(int r : res){
        cout << r << " ";
    }

    return 0;
}