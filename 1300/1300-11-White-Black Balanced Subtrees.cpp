// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1676/G

#include <bits/stdc++.h>
using namespace std;

// Normal dfs with track of white & black vertices in the subtree of the encountered vertex

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

int dfs (int vertex, vector<vector<int>> &adj, string& color, vector<int>& ans) {
    int status = 0;
    for (auto child : adj[vertex]) {
        status += dfs(child, adj, color, ans);
    }
    status += ((color[vertex-1]=='W') ? 1 : -1);
    return ans[vertex] = status;    
}

void solve() {
    int n, input;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for (int i=2; i<=n; i++) {
        cin >> input;
        adj[input].pb(i);
    }  
    string color;
    cin >> color;
    vector<int> ans(n+1, -1);
    dfs(1, adj, color, ans); // vis not needed as tree
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (ans[i]==0) cnt++;
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