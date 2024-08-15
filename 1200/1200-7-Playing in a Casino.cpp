// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1808/B

#include <bits/stdc++.h>
using namespace std;

// In each column, sort the column and then traverse through and compute the modulus diff

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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> array(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> array[i][j];
        }
    }  
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            grid[i][j] = array[j][i];
        }
    }
    int sum = 0;
    for (auto& vec : grid) {
        sort(all(vec));
        // print(vec);
        int cur = vec[0];
        for (int i=1; i<n; i++) {
            sum += (vec[i]*i - cur);
            cur += vec[i];
        }
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