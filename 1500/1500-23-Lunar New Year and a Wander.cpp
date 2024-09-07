// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1106/D

#include <bits/stdc++.h>
using namespace std;

// BFS with priority queue to make lexicographical ordering

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

void solve() {
    int n, m, u, v;
    cin >> n >> m;
    vector<set<int>> adj(n+1);
    for (int i=0; i<m; i++) {
        cin >> u >> v;
        if (u==v) continue;
        adj[u].insert(v);
        adj[v].insert(u);
    }   
    vector<vector<int>> g(n+1);
    for (int i=0; i<=n; i++) {
        for (int elem : adj[i]) {
            g[i].pb(elem);
        }
    }
    vector<int> ans;
    vector<bool> vis(n+1, false);
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    vis[1] = 1;
    while (!pq.empty()) {
        int vertex = pq.top();
        pq.pop();
        ans.pb(vertex);
        for (int child : g[vertex]) {
            if (!vis[child]) {
                pq.push(child);
                vis[child] = true;
            }
        }
    }
    print(ans);

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
    // cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}