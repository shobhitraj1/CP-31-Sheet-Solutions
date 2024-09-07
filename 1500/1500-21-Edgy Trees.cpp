// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1139/C

#include <bits/stdc++.h>
using namespace std;

// As n^k sequences possible in total
// Not a good sequence if path within has no black edge
// So, find all the connected components with red edges, so all the sequences within those are not good
// Hence, subtract connected_comp_size^k from the ans
// Also, the size of the connected component can be 1 too, so the sequence is [v,v,v,...,v]

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

int binExp(int a, int b) {
    if (a==1 || b==0) return 1;
    int res = binExp(a,b/2);
    if (b&1) return (a*((res*res)%MOD))%MOD;
    else return ((res*res)%MOD);
}

void dfs(int vertex, vector<vector<pair<int,int>>>& tree, vector<bool>& vis, int& cnt) {
    vis[vertex] = true;
    cnt++;
    for (auto elem : tree[vertex]) {
        int child = elem.first;
        int type = elem.second;
        if (vis[child] || type==1) continue;
        dfs(child, tree, vis, cnt);
    }
}

void solve() {
    int n, k, u, v, type;
    cin >> n >> k;
    vector<vector<pair<int,int>>> tree(n+1);
    for (int i=0; i<n-1; i++) {
        cin >> u >> v >> type;
        tree[u].emplace_back(v, type);
        tree[v].emplace_back(u, type);
    }
    int ans = binExp(n, k);
    vector<bool> vis(n+1, false);
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            int cnt = 0;
            dfs(i, tree, vis, cnt);
            ans -= binExp(cnt, k);
        }
    }
    while (ans<0) { // after subtracting, can go below 0
        ans += MOD;
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