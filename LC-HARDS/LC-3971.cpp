#include <bits/stdc++.h>

using namespace std;

//int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
//    long long MOD = 1e9 + 7;
//    int n = value.size();//
//    priority_queue<pair<long long, int>> pq;
//    vector<int> picked_count(n, 0);//
//    for(int i = 0; i<n; i++){
//        pq.push({(long long)value[i], i});
//    }//
//    long long total = 0;
//    for(auto j = 0; j<m; j++){
//        pair<long long, int> top = pq.top();
//        pq.pop();
//        long long gain = top.first;
//        int i = top.second;//
//        if(gain <= 0) break;
//        total = (total + gain)%MOD;//
//        picked_count[i]++;
//        long long next_gain = (long long)value[i] - (long long)picked_count[i] * decay[i];
//        pq.push({next_gain, i});
//    }
//    return (int)total;
//    
//}

int maxTotalValue(vector<int>& value, vector<int>& decay, int m){

    int MOD = 1e9+7;
    long long low = 1;
    long long high = *max_element(value.begin(), value.end());

    while(low <= high){
        long long mid = low + (high-low)/2;
        long long cnt = 0;
        for(int i = 0; i<value.size(); i++){
            cnt += (value[i] - mid)/decay[i] + 1;
        }

        if(cnt >= m){
            low = mid + 1;
        }else high = mid - 1;
    }

    int threshold = high;

    long long ans = 0;
    long long cnt = 0;
    long long inv2 = 500000004;

    for(int i = 0; i<value.size(); i++){
        if(value[i] > threshold){
            long long k = (value[i] - threshold)/decay[i] + 1;
            cnt += k;
            
            long long first = value[i];
            long long last = value[i] - (k - 1) * (long long)decay[i];
            
            // Sum = k * (first + last) / 2
            long long sum = (k % MOD) * (((first + last) % MOD)) % MOD;
            sum = (sum * inv2) % MOD;
            
            ans = (ans + sum) % MOD;
        }
    }
        if (cnt < m) {
            ans = (ans + ((m - cnt) % MOD) * (threshold % MOD)) % MOD;
        }

        return (int)ans;
}