// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1646/C

#include <bits/stdc++.h>
using namespace std;

// 52 powerful numbers are there, using bitmasking would lead to O(2^52)
// Instead, as factorials powerful numbers are only 14, compute the sum with minimum k for these --> O(2^14)
// Now, the remaining sum has to be sum of distinct powers of 2, using bits, 
// we can find the number of set 1's in the difference of n - sum(using factorials)
// Also, there will be nothing common in factorials & powers of 2 (2, 4, 8, 16, ...) --> so it will always be sum of distinct values

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

template<typename T>
void print(const vector<T> &v) {
    for (const auto &el : v) {
        cout << el << " ";
    }
    cout << endl;
}

vector<int> powerful;
map <int, int> mp;

void solve() {
    int n;
    cin >> n;
    int ans = INF;
    for (auto elem : mp) {
        if (elem.first <= n) {
            ans = min(ans, elem.second + __builtin_popcountll(n-elem.first));
        }
        else break;
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    //     freopen("output.txt","w",stderr);
    // #endif

    int fact = 1;
    int i = 2;
    while (true) {
        powerful.pb(fact);
        fact *= i;
        i++;
        if (fact > 1e12) break;
    }
    // cout << powerful.size() << endl;
    // print(powerful);
    int p = powerful.size();
    for (int mask = 0; mask < (1LL<<p); mask++) { // O(2^14)
        int sum = 0;
        for (int i=0; i<p; i++) {
            if (mask & (1LL<<i)) sum += powerful[i];
        }
        int elems = __builtin_popcountll(mask);
        if (mp[sum] && elems > mp[sum]) continue;
        else mp[sum] = elems;
    }

    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}