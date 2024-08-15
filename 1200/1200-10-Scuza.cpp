// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1742/E

#include <bits/stdc++.h>
using namespace std;

// Use binary search (upper bound) to find upto which stair it can climb
// it can climb upto a stair if it can climb every stair below it (so keep max diff)
// And add up the stairs upto that stair to compute the total climb

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
    int n, q;
    cin >> n >> q;
    vector<int> stairs(n);
    vector<int> uptill(n);
    for (int i=0; i<n; i++) {
        cin >> stairs[i];
        if (i>0) {
            uptill[i] = max(stairs[i], uptill[i-1]);
            stairs[i] += stairs[i-1];
        }
        else uptill[i] = stairs[i];
    }
    for (int i=0; i<q; i++) {
        int k; cin >> k;
        auto it = upper_bound(all(uptill), k);
        int index = distance(uptill.begin(), it)-1;
        if (index>=0) {
            cout << stairs[index] << " ";
        }
        else cout << 0 << " ";
    }
    cout << endl;    
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