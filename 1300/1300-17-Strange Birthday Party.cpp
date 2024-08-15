// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1470/A

#include <bits/stdc++.h>
using namespace std;

// As the cost of the presents are sorted, if k_i is larger, it will cost higher to directly give c_k_i dollars
// So, but first present that is not buyed
// Else if c_j > c_k_i, directly give c_k_i dollars

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

template<typename T1, typename T2>
void print(const vector<pair<T1, T2>> &v) {
    for (const auto &el : v) {
        cout << "(" << el.first << ", " << el.second << ") ";
    }
    cout << endl;
}

void solve() {
    int n, m, input;
    cin >> n >> m;
    vector<pair<int, int>> res;
    for (int i=0; i<n; i++) {
        cin >> input;
        res.emplace_back(input, i);
    }   
    vector<int> cost(m);
    for (int i=0; i<m; i++) {
        cin >> cost[i];
    }
    sort(all(res), greater<>());
    // print(res);
    int ans = 0, j = 0;
    for (int i=0; i<n; i++) {
        if (j<m && cost[j]<cost[res[i].first-1]) { // 1-based indexing
            ans += cost[j];
            j++;
        }
        else {
            ans += cost[res[i].first-1];
        }
    }
    cout << ans << endl;   
    
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