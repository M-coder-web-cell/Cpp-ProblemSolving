#include <bits/stdc++.h>

using namespace std;

string removeLeadingzeroes(string s){
    int n = s.size();
    bool flag = 1;
    int i = 0;
    string str = ""; 

    while(i<n){
        if(flag == 1 && s[i] == '0') continue;
        else {
            flag = 0;
            str+=s[i];
        }
        i++;
    }
}