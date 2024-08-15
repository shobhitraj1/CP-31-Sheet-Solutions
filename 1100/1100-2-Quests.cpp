// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1914/C

#include <bits/stdc++.h>
using namespace std;

// Do it till ith day, and then (k-i)*(max. till bi)

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
    int n, k;
    cin >> n >> k;
    vector<int> A(n), B(n);
    for (int i=0; i<n; i++) {
        cin >> A[i];
        if (i>0) A[i] += A[i-1];
    }
    for (int i=0; i<n; i++) {
        cin >> B[i];
        if (i>0) B[i] = max(B[i-1], B[i]);
    }
    int sum = 0;
    for (int i=0; i<min(n,k); i++) {
        sum = max(sum, A[i] + (k-i-1)*B[i]);
    }
    cout << sum << endl;    

    
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