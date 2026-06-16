#include <bits/stdc++.h>

using namespace std;


string kDistinctChar(string& s, int k) {

    unordered_map<char, int> mpp;

    int l = 0;
    int r = 0;
    int n = s.size();
    string str = "";

    while(r < n){
        if(!mpp[s[r]]) mpp[s[r]] = 1;
        else mpp[s[r]]++;

        while(mpp.size() > k){
            mpp[s[l]]--;
            if(mpp[s[l]] == 0) mpp.erase(s[l]);
            l++;
        }

        if(r-l+1 > str.size() && mpp.size() <= k) str = s.substr(l, r-l+1);
        r++;
    }
    return str;

}

int main(){
    string s = "abcddefg";
    int k = 3;

    cout << kDistinctChar(s, k)<<endl;
    return 0;
}