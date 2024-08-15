// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1294/C

#include <bits/stdc++.h>
using namespace std;

// Brute force check all triplets 
// i, m=n/i => i, j, k=m/j => here i>1, hence as j>i, j>1 & as k>j, k>1 (and check if not equal)
// j>i & k>j since iterated for i*i<n & j*j<m, so second factor greater than current

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n;
    cin >> n;
    for (int i=2; i*i<n; i++) {
        if (n%i==0) {
            int m = n/i;
            for (int j=i+1; j*j<m; j++) {
                if (m%j==0 && m/j!=j && m/j!=i) {
                    cout << "YES" << endl;
                    cout << i << " " << j << " " << m/j << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
    
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