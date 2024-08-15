// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1360/D

#include <bits/stdc++.h>
using namespace std;

// find smallest divisor of n such that n/divisor <= k
// Time Complexity = O(√n)

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, k;
    cin >> n >> k;
    // stack<int> st;
    // for (int i=1; i*i<=n; i++) {
    //     if (n%i==0) {
    //         if (n/i<=k) {
    //             cout << i << endl;
    //             return;
    //         }
    //         else st.push(n/i);
    //     }
    // }
    // while (!st.empty()) {
    //     int i = st.top(); st.pop();
    //     // cout << i << endl;
    //     if (n/i <= k) {
    //         cout << i << endl;
    //         return;
    //     }
    // }
    int ans = n;
    for (int i=1; i*i<=n; i++) {
        if (n%i==0) {
            if (n/i<=k) {
                ans = min(ans, i);
            }
            if (i<=k) {
                ans = min(ans, n/i);
            }
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