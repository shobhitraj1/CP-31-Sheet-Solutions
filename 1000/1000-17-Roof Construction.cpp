// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1632/B

#include <bits/stdc++.h>
using namespace std;

// min maximum xor can be biggest 2's power (let's say x) i.e. <= n-1
// Every consecutive pair will have XOR <= x, except
// x^x-1 will be bigger than 2*x-1, so after x, insert 0, and then continue from x-1

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
    int m = log2(n-1);
    int max = pow(2,m);
    for (int i=n-1; i>=max; i--) {
        cout << i << " ";
    }
    cout << 0 << " ";
    for (int i=max-1; i>=1; i--) {
        cout << i << " ";
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

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}