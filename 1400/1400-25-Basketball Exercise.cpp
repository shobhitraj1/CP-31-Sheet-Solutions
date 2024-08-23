// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1195/C

#include <bits/stdc++.h>
using namespace std;

// Used DP with space optimization
// Recursive relation :-
// Choose previous A and current B, or don't choose any 

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i=0; i<n; i++) {
        cin >> A[i];
    }   
    for (int i=0; i<n; i++) {
        cin >> B[i];
    }   
    // vector<vector<int>> dp(2, vector<int> (n, 0));
    // dp[0][0] = A[0];
    // dp[1][0] = B[0];
    int prev0 = A[0], prev1 = B[0];
    int cur0 = prev0, cur1 = prev1;
    for (int i=1; i<n; i++) {
        // dp[0][i] = max(dp[0][i-1], dp[1][i-1]+A[i]);
        // dp[1][i] = max(dp[1][i-1], dp[0][i-1]+B[i]);
        cur0 = max(prev0, prev1 + A[i]);
        cur1 = max(prev1, prev0 + B[i]);
        prev0 = cur0; prev1 = cur1;
        
    }
    // cout << max(dp[0][n-1], dp[1][n-1]) << endl;
    cout << max(cur0, cur1) << endl;

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
    // cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}