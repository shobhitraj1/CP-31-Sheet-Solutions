// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/862/B

#include <bits/stdc++.h>
using namespace std;

// Find the color of each node & total first color & total second color
// Now, for each node colored with first color, we can join it to node of second color if not already joined

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

void dfs (int vertex, vector<vector<int>>& adj, vector<int>& color) {
    for (int child : adj[vertex]){
        if (color[child]==-1) {
            color[child] = 1-color[vertex];
            dfs(child, adj, color);
        }
    }
}

void solve() {
    int n, u, v;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for (int i=0; i<n-1; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> color(n+1, -1);
    color[1] = 0;
    dfs(1, adj, color);
    int col1 = 0, col2 = 0;
    for (int i=1; i<=n; i++) {
        if (color[i]) col2++;
        else col1++;
    }
    // print(color);
    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (color[i]) ans += (col1 - adj[i].size());
        // else ans += (col2 - adj[i].size()); // already joined 
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
    // cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}