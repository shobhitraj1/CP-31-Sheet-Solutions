// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1830/A

#include <bits/stdc++.h>
using namespace std;

/*
Let rounds[i](dp[i]) be the number of scans needed to activate node i, and (id[i])first_idx be the index (in the order from the input) of the edge which activated node i.
Intially, since only 1 is active, dp[1]=1 and id[1]=0.
We will perform a dfs traversal starting from node 1. When we process an edge (u,v), one of the following two cases can happen:
1) If index((u,v))≥id[u], we can visit v in the same scan as u: dp[v]=dp[u], id[v]=index((u,v))
2) If index((u,v))<id[u], v will be visited in the next scan after dp[u]:dp[v]=dp[u]+1, id[v]=index((u,v))
The answer is max_i=1ton(dp[i]).
*/

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

void dfs(int vertex, int first_idx, vector<vector<pair<int, int>>>& g, vector<int>& rounds) {
    for (auto c : g[vertex]) {
        int child = c.first;
        int idx = c.second;
        if (rounds[child]) continue;
        if (idx > first_idx) rounds[child] = rounds[vertex];
        else rounds[child] = rounds[vertex]+1;
        dfs(child, idx, g, rounds);
    }
}

void solve() {
    int n, u, v;
    cin >> n;
    vector<vector<pair<int, int>>> g(n+1);
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }
    vector<int> rounds(n+1, 0);
    rounds[1] = 1;
    dfs(1, 0, g, rounds);
    // print(rounds);
    int ans = *max_element(all(rounds));
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