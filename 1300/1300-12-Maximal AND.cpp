// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1669/H

#include <bits/stdc++.h>
using namespace std;

// try to set the MSB of all the numbers so that their AND has that msb set
// Set MSB from 30 to 0 if possible using the k

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }   
    vector<int> bitset(31, 0);
    int ans = array[0];
    for (int i=0; i<n; i++) {
        for (int j=0; j<31; j++) {
            if (array[i]&(1<<j)) bitset[j]++;
        }
        if (i>0) ans &= array[i];
    }
    for (int j=30; j>=0; j--) {
        if (n-bitset[j]<=k) {
            k -= (n-bitset[j]);
            ans |= (1<<j);
        }
    }
    cout << ans << endl;
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    //     freopen("output.txt","w",stderr);
    // #endif

    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}