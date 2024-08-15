// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1366/B

#include <bits/stdc++.h>
using namespace std;

// maintain the interval after each interval which tracks how many elements can be converted to 1
// if any element in the range is already 1, then all the elements in the range can be converted to 1
// at the end, calculate the length of the range

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, x, m, l, r;
    cin >> n >> x >> m;
    int start = x, end = x;
    for (int i=0; i<m; i++) {
        cin >> l >> r;
        if ((start>=l && start <=r) || (end>=l && end<=r)) {
            start = min(start, l);
            end = max(end, r);
        }
    }
    cout << end-start+1 << endl;
    
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