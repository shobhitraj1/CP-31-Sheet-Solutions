// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1708/B

#include <bits/stdc++.h>
using namespace std;

// Since gcd(i,array[i]) will be max(i,array[i]), and all have to be distinct
// So, first position - gcd always 1, second position it has to be 2, & so on...
// Just find multiples of i within the range a TO b.

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
    int n, a, b;
    cin >> n >> a >> b;
    // if (n>b-a+1) cout << "NO" << endl; // may be less segment length but still have multiple

    vector<int> res;
    for (int i=1; i<=n; i++) {
        int rem = b%i;
        if (b-rem<a) {
            cout << "NO" << endl;
            return;
        }
        else res.pb(b-rem);         
    }
    cout << "YES" << endl;
    print(res);

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