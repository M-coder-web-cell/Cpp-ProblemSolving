#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> rightgreatest(vector<int>& nums){
    int n = nums.size();
    vector<int> rgreat(n);

    rgreat[n-1] = nums[n-1];

    for(int i = n-2; i>=0; i--){
        if(nums[i] >= rgreat[i+1]){
            rgreat[i] = nums[i];
        }else rgreat[i] = rgreat[i+1];
    }

    return rgreat;
}

vector<int> leftgreatest(vector<int>& nums){
    int n = nums.size();
    vector<int> lgreat(n);

    lgreat[0] = nums[0];

    for(int i = 1; i<n; i++){
        if(nums[i] >= lgreat[i-1]){
            lgreat[i] = nums[i];
        }else lgreat[i] = lgreat[i-1];
    }

    return lgreat;
}


int trap(vector<int>& height){

    int total = 0;
    vector<int> lgreat = leftgreatest(height);
    vector<int> rgreat = rightgreatest(height);

    for(int i = 1; i<height.size()-1; i++){
        if(lgreat[i-1]>=height[i] && rgreat[i+1]>=height[i]){
            total += min(lgreat[i-1], rgreat[i+1]) - height[i];
            cout<<"idx: "<< i <<" total: "<< total<< endl;
            
        } 
    }

    return total;
}

int main(){

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout<< trap(height) << endl;
    return 0;
}