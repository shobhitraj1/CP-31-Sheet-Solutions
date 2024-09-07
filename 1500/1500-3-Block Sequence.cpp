// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1881/E

#include <bits/stdc++.h>
using namespace std;

// Standard DP problem - both memoization and tabulation approach
// minDeletions(index) or dp[index] => return minimum no. of deletions from array[index : n]
// Time Complexity = O(n) as fill n entries in dp table

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

// Memoization
int minDeletions(int index, vector<int>& array, vector<int>& dp) {
    if (index==array.size()) return 0;
    if (index > array.size()) return INT_MAX;
    if (dp[index]!=-1) return dp[index];
    int include = minDeletions(index+array[index]+1, array, dp);
    int notInclude = 1 + minDeletions(index+1, array, dp);
    return dp[index] = min(include, notInclude);    
}

void solve() {
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }   

    // vector<int> dp(n, -1);
    // cout << minDeletions(0, array, dp) << endl;

    // Tabulation
    vector<int> dp(n+1, INT_MAX);
    dp[n] = 0;
    for (int i=n-1; i>=0; i--) {
        dp[i] = min(dp[i], 1+dp[i+1]); // not include case
        if (i+array[i]+1 <= n) dp[i] = min(dp[i], dp[i+array[i]+1]); // include case
    }
    cout << dp[0] << endl;
    
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