#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//void backtrack(int idx, int total, vector<int>& elements, vector<vector<int>>& subsets, vector<int>& candidates, int target, vector<int>& hash, map<vector<int>, int>& map){
//
//    if(total > target) return;
//    if(total == target){
//        if(!map[hash]){
//            subsets.push_back(elements);
//            map[hash] = 1;
//        }
//        return;
//    }
//    if(idx > candidates.size() - 1) return;
//
//    //non take
//    backtrack(idx+1, total, elements, subsets, candidates, target, hash, map);
//
//    //take
//    elements.push_back(candidates[idx]);
//    hash[candidates[idx]]++;
//    backtrack(idx+1, total+candidates[idx], elements, subsets, candidates, target, hash, map);
//    hash[candidates[idx]]--;
//    elements.pop_back();
//}

void backtrack(int idx, int total, vector<int>& elements, vector<vector<int>>& subsets, vector<int>& candidates, int target){

    if(total > target) return;
    if(total == target) {
        subsets.push_back(elements);   
        return;
    }
    if(idx > candidates.size() - 1) return;

    //take
    elements.push_back(candidates[idx]);
    backtrack(idx+1, total+candidates[idx], elements, subsets, candidates, target);
    elements.pop_back();

    //non take
    while(idx+1 <candidates.size() && candidates[idx] == candidates[idx+1]){
        idx++;
    } 
    backtrack(idx+1, total, elements, subsets, candidates, target);
}

int main(){
    vector<int> candidates = {2,5,2,1,2};

    sort(candidates.begin(), candidates.end());
    int target = 5;
    vector<int> el;
    vector<vector<int>> subsets;
    vector<int> hash(51, 0);
    map<vector<int>, int> map;
    int total = 0;

    backtrack(0, total, el, subsets, candidates, target);

    for(auto it = subsets.begin(); it != subsets.end(); it++){
        // *it is the current row (a 1D vector)
        for(auto elementIt = it->begin(); elementIt != it->end(); elementIt++){
            cout << *elementIt << " ";
        }
        cout << "\n"; 
    }

    return 0;
}