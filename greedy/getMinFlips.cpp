#include <bits/stdc++.h>

using namespace std;

int getMinFlips(string password){
    int n = password.size();

    vector<int> pre (n+1, 0);

    for(int i = 0; i < n; i++){
        pre[i+1] = pre[i] + (password[i] == '1');
    }
    int ans = INT_MAX;

    for(int i = 2; i <=n-2; i+=2){
        int leftones = pre[i];
        int leftzeros = i -leftones;

        int rightones = pre[n] - pre[i];
        int rightzeros = (n - split) - rightones;

        int opt1 = leftzeros + rightones;
        int opt2 = leftones + rightzeros;

        ans = min(ans, min(opt1, opt2));
    }
}