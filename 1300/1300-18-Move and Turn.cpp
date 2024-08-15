// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1459/B

#include <bits/stdc++.h>
using namespace std;

// If n = even, ans = (n/2+1)^2
// If n = odd, ans = 2(k+1)(k+2), where k=n/2 rounded down.

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n;
    cin >> n;
    if (n&1) {
        cout << ((n+3)/2)*(n+1) << endl;
    }
    else {
        cout << ((n+2)/2)*((n+2)/2) << endl;
    }    
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