// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1634/B

#include <bits/stdc++.h>
using namespace std;

// As x & (x+3) have different parity
// And whether we add or xor, they have the same effect on the parity of the resultant
// So, after applying the series of operations, if the resultant's parity is equal to y's parity.
// then that starting d is possible

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> array(n);
    int last_bit = (x&1) ? 1 : 0;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        if (array[i]&1) last_bit = 1 - last_bit;
    } 
    int ans_bit = (y&1) ? 1 : 0;
    if (last_bit == ans_bit) cout << "Alice" << endl;
    else cout << "Bob" << endl;
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