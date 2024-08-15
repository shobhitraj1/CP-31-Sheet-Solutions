// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1669/F

#include <bits/stdc++.h>
using namespace std;

// Use prefix sum for both
// Check if both elements exist in same arrays such that (i+j<=n) 
// where i, j are indices of the same element

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

template<typename T1, typename T2>
void print(const vector<pair<T1, T2>> &v) {
    for (const auto &el : v) {
        cout << "(" << el.first << ", " << el.second << ") ";
    }
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);

    for (int i=0; i<n; i++) {
        cin >> A[i];
        B[n-1-i] = A[i];
    }  
    for (int i=1; i<n; i++) {
        A[i]+=A[i-1];
        B[i]+=B[i-1];
    }
    // print(A);
    // print(B);
    int max = 0;
    for (int i=0; i<n; i++) {
        int elem  = A[i];
        auto it = lower_bound(B.begin(), B.end(), elem);
        if (it != B.end() && *it == elem) {
            int j = distance(B.begin(), it);
            if (i+j+2<=n && i+j+2>max) max = i+j+2;
        }
    }
    cout << max << endl;
    
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