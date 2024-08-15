// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1520/D

#include <bits/stdc++.h>
using namespace std;

// aj−ai=j−i => aj−j=ai−i
// Replace each ai with bi=ai−i. 
// Count number of pairs (i,j) such that i<j and bi=bj using map

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
    int n;
    cin >> n;
    vector<int> array(n);
    map <int, int> mp;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        cnt += (mp[array[i]-i]);
        mp[array[i]-i]++;
    }   
    cout << cnt << endl;
    
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