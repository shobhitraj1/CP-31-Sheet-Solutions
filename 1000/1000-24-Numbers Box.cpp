// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1447/B

#include <bits/stdc++.h>
using namespace std;

// 1. If even number of negative --> all can be made positive => max sum = All summation
// 2. If odd number of negative --> Least element should be made negative => max sum accordingly
// Keep count of zero too and adjust accordingly - zero will be automatically taken care of in min

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
    int array[n][m];
    int min = 101;
    int negative = 0;
    int sum = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> array[i][j];
            if (array[i][j]<0) negative+=1;
            sum += abs(array[i][j]);
            if (abs(array[i][j])<min) min = abs(array[i][j]);
        }
    }
    // cout << min << " " << sum << endl;
    if (negative%2!=0) sum -= 2*min;
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

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}