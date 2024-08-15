// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1797/B

#include <bits/stdc++.h>
using namespace std;

// Just check how many d/f after rotating
// But if odd, check only half of the middle row
// If after changing, even changes left OR if n is odd => keep changing the middlemost element as many times

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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> array(n, vector<int>(n, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> array[i][j];
        }
    }
    int count = 0;
    for (int i=(n+1)/2; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (array[i][j]!=array[n-1-i][n-1-j]) count+=1;
        }
    }
    if (n%2!=0) {
        for (int i=0; i<n/2; i++) {
            if (array[n/2][i]!=array[n/2][n-1-i]) count+=1;
        }
    }
    // cout << count << endl;
    if (count>k) cout << "NO" << endl;
    else {
        k-=count;
        if (k%2==0 || n%2!=0) cout << "YES" << endl;
        else cout << "NO" << endl;
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