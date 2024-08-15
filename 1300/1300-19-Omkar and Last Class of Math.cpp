// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1372/B

#include <bits/stdc++.h>
using namespace std;

// Similar to Minimum LCM problem - https://codeforces.com/problemset/problem/1765/M

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

int smallestFactor(int n) {
    int max = 1;
    for (int i=3; i<=sqrt(n); i+=2) {
        if (n%i==0) return i;
    }
    return max;
}

void solve() {
    int n;
    cin >> n;
    if (n%2==0) cout << n/2 << " " << n/2 << endl;
    else {
        int m = smallestFactor(n);
        if (m==1) cout << 1 << " " << n-1 << endl;
        else cout << n/m << " " << n-(n/m) << endl;
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

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}