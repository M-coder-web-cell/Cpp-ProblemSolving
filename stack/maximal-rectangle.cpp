#include<bits/stdc++.h>

using namespace std;

vector<int> nextsmaller(vector<int>& height){

    stack<int> st;
    int n = height.size() - 1;
    vector<int> res(height.size(), 0);

    for(int i = n; i>=0; i--){

        while(!st.empty() && height[st.top()] >= height[i]){
            st.pop();
        }
        if(st.empty()) res[i] = height.size();
        else res[i] = st.top();

        st.push(i);
    }
    return res;
}

vector<int> prevsmaller(vector<int>& height){

    stack<int> st;
    int n = height.size() - 1;
    vector<int> res(height.size(), 0);

    for(int i = 0; i<=n; i++){

        while(!st.empty() && height[st.top()] >= height[i]){
            st.pop();
        }
        if(st.empty()) res[i] = -1;
        else res[i] = st.top();

        st.push(i);
    }
    return res;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    int col = matrix[0].size();
    int row = matrix.size();
    vector<int> height(col, 0);
    vector<int> nexts;
    vector<int> prevs;

    int maxarea= 0;
    for(int r = 0; r<row; r++){
        for(int c = 0; c<col; c++){
            if(matrix[r][c] == '1') height[c]++;
            else height[c] = 0;
        }
        
        nexts = nextsmaller(height);
        prevs = prevsmaller(height);

    
        for(int c = 0; c<col; c++){
            maxarea = max(maxarea, height[c]*(nexts[c] - prevs[c] - 1));
        }
    }
    return maxarea;
}

int main(){
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    cout << maximalRectangle(matrix)<< endl;

    return 0;
}