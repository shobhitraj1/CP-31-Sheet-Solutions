// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1790/D

#include <bits/stdc++.h>
using namespace std;

// Just sort & use multiset or any data structure to find increasing sequences

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
    int n, input;
    cin >> n;
    multiset <int> ms;
    for (int i=0; i<n; i++) {
        cin >> input;
        ms.insert(input);
    }   
    int cnt = 0;
    while (!ms.empty()) {
        int first = *ms.begin();
        ms.erase(ms.begin());
        cnt += 1;
        first += 1;
        while (ms.count(first)) {
            ms.erase(ms.find(first));
            first += 1;
        }
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