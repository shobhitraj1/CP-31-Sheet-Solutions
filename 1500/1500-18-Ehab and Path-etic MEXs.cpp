// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1325/C

#include <bits/stdc++.h>
using namespace std;

// If none of the vertices have degree >= 3, i.e. it is a skewed tree, so MEX would be n-1 in any case 
// If any vertex has degree >= 3, then for each edge, if assigned 0, 1 & 2, then MEX for the entire tree will be 2
// As can't have simple path between any 2 vertices having all 0, 1 & 2, will miss atleast one of them

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, u, v;
    cin >> n;
    vector<vector<int>> adj(n+1);
    vector<pair<int,int>> edges;
    for (int i=0; i<n-1; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        edges.emplace_back(u, v);
    }
    int vertex3Deg = -1;
    for (int i=1; i<=n; i++) {
        if (adj[i].size()>=3) {
            vertex3Deg = i;
            break;
        }
    }
    if (vertex3Deg == -1) {
        for (int i=0; i<n-1; i++) {
            cout << i << endl;
        }
    }
    else {
        vector<int> ans(n-1, -1);
        int cnt = 0;
        for (int i=0; i<n-1; i++) {
            if (edges[i].first == vertex3Deg || edges[i].second == vertex3Deg) {
                ans[i] = cnt;
                cnt++;
            }
        }
        for (int i=0; i<n-1; i++) {
            if (ans[i] == -1) {
                ans[i] = cnt;
                cnt++;
            }
        }
        for (int i=0; i<n-1; i++) {
            cout << ans[i] << endl;
        }
    }
  
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