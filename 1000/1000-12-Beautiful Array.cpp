// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1715/B

#include <bits/stdc++.h>
using namespace std;

// min s = k*b & max s = (k*(b+1)-1) + (k-1)*(n-1)
// & then accordingly assign <=(k*(b+1)-1) to last and remaining to n-1

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

inline int ceil(int a, int b) {
    return (a + b - 1) / b;
}

template<typename T>
void print(const vector<T> &v) {
    for (const auto &el : v) {
        cout << el << " ";
    }
    cout << endl;
}

void solve() {
    int n, k, b, s;
    cin >> n >> k >> b >> s;
    int maxResult = k*(b+1) - 1;
    maxResult += ((k-1)*(n-1));
    int minResult = k*b;
    if (s>maxResult || s<minResult) cout << -1 << endl;
    else {
        if (s<=(k*(b+1)-1)) {
            // give all to last & rest 0
            for (int i=0; i<n-1; i++) {
                cout << 0 << " ";
            }
            cout << s << endl;
        }
        else {
            // give (k*(b+1)-1) to last and distribute left to n-1
            s-=(k*(b+1)-1);
            int m = s/(k-1); // (k-1) to m
            int left = s%(k-1); // left to 1
            int zeroes = n-m-2;
            for (int i=0; i<zeroes; i++) {
                cout << 0 << " ";
            }
            if (left!=0 || m!=n-1) cout << left << " ";
            // cout << left << " ";
            for (int i=0; i<m; i++) {
                cout << k-1 << " ";
            }
            cout << (k*(b+1)-1) << endl;

        }

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
