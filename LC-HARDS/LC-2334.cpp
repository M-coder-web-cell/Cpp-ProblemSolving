//Subarray with elements greater than varying threshold
#include <bits/stdc++.h>

using namespace std;

class DSU{
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i){
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j){
        int rootI = find(i);
        int rootJ = find(j);

        if(rootI != rootJ){
            if(size[rootI] < size[rootJ]) {
                swap(rootI, rootJ);
            }
            parent[rootJ] = rootI;
            size[rootI] += size[rootJ];
            
        }
    }
    int getSize(int i) {
        return size[find(i)];
    }
};

int validSubarraySize(vector<int>& nums, int threshold){
    int n = nums.size();
        
    vector<pair<int, int>> sortedNums(n);
    for (int i = 0; i < n; ++i) {
        sortedNums[i] = {nums[i], i};
    }
    
    sort(sortedNums.rbegin(), sortedNums.rend());   
    DSU dsu(n);
    vector<bool> active(n, false);

    for(int i = 0; i<n; ++i){
        int val = sortedNums[i].first;
        int idx = sortedNums[i].second;

        active[idx] = true;

        if(idx > 0 && active[idx - 1]) dsu.unite(idx, idx-1);
        if(idx < n- 1 && active[idx+1]) dsu.unite(idx, idx+1);

        long long k = dsu.getSize(idx);

        if (1LL * val * k > threshold) {
            return k;
        }
    }
    return -1;
}
