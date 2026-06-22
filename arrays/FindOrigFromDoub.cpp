//LC - 2007
#include <bits/stdc++.h>

using namespace std;

vector<int> findOriginalArray(vector<int>& changed) {
    int n = changed.size();
    unordered_map <int, int> seen;
    vector<int> res;
    int count = 0;
    for(int i = 0; i<n; i++){

        if(changed[i]%2 == 0){
            if(seen.find(changed[i]/2) != seen.end()){
                count++;
                res.push_back(seen[changed[i]/2]);
            }else if (seen.find(changed[i]*2) != seen.end()){
                count++;
                res.push_back(seen[changed[i]*2]);
            }
        }else {
            if (seen.find(changed[i]*2) != seen.end()){
                count++;
                res.push_back(seen[changed[i]*2]);
            }           
        }
    }
    if(float(count) != n/2.0)return {};

    return res;
}
