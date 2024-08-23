// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/414/B

#include <bits/stdc++.h>
using namespace std;

// Standard Memoization DP problem
// dp[i][j] = no. of sequences possible if there is i on jth element of the sequence

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

int n, k;

// Memoization
int countSeq(int i, int j, vector<vector<int>>& dp) {
    if (j==k) return 1;
    if (dp[i][j]!=-1) return dp[i][j];
    int ans = 0;
    for (int l=i; l<=n; l+=i) {
        ans = (ans + countSeq(l, j+1, dp))%MOD;
    }
    return dp[i][j] = ans;
}

void solve() {
    cin >> n >> k;
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    int ans = 0;
    for (int i=1; i<=n; i++) {
        ans = (ans + countSeq(i, 1, dp))%MOD;
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
    // cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}