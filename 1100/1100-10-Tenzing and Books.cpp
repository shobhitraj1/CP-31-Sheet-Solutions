// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1842/B

#include <bits/stdc++.h>
using namespace std;

// Once, a bit changes to 1, can't be made 0 as bitwise OR
// Try the prefixes of the stacks till within range 
// [as nothing extra will come if that bit is made 1, no loss]

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

inline int ceil(int a, int b) {
    return (a + b - 1) / b;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> A(n), B(n), C(n);
    for (int i=0; i<n; i++) cin >> A[i];
    for (int i=0; i<n; i++) cin >> B[i];
    for (int i=0; i<n; i++) cin >> C[i];
    int output = 0;
    for (int i=0; i<n; i++) {
        if ((x | A[i]) != x) break; // unset bit being set
        output |= A[i];
    }
    for (int i=0; i<n; i++) {
        if ((x | B[i]) != x) break;
        output |= B[i];
    }
    for (int i=0; i<n; i++) {
        if ((x | C[i]) != x) break;
        output |= C[i];
    }
    if (output == x) cout << "Yes" << endl;
    else cout << "No" << endl;
    
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