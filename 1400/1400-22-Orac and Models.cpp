// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1350/B

#include <bits/stdc++.h>
using namespace std;

// Use sieve of eranthonsis method with dp table to find longest chain possible
// Time Complexity - O(nlogn)

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

template<typename T>
void print(const vector<T> &v) {
    for (const auto &el : v) {
        cout << el << " ";
    }
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    vector<int> array(n+1);
    for (int i=1; i<=n; i++) {
        cin >> array[i];
    }   
    vector<int> dp(n+1, 1);
    int ans = 1;
    for (int i=1; i<=n; i++) {
        for (int j=2*i; j<=n; j+=i) {
            if (array[j]>array[i]) {
                dp[j] = max(dp[j], dp[i]+1);
                ans = max(ans, dp[j]);
            }
        }
    }
    // print(dp);
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