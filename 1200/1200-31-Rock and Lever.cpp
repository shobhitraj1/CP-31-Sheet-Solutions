// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1420/B

#include <bits/stdc++.h>
using namespace std;

// a_i & a_j >= a_i ^ a_j by considering the bits from highest to lowest
// resultant will be greater for which highest msb is 1
// AND will be greater than XOR when that msb position in both nos. have 1 (same MSB set)
// & msb is basically the number of bits in binary representation (so if length same) 

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, input;
    cin >> n;
    map <int, int> mp;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        cin >> input;
        int bin = (int)(log2(input)+1);
        cnt += mp[bin];
        mp[bin]++;
    }   
    cout << cnt << endl;

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