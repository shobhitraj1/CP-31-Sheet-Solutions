// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1167/C

#include <bits/stdc++.h>
using namespace std;

// Use disjoint set & find for each vertex, the size of connected component it is a part of

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

class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m;
    DisjointSet ds(n);
    for (int i=0; i<m; i++) {
        cin >> k;
        vector<int> group(k);
        for (int j=0; j<k; j++) {
            cin >> group[j];
            if (j>0) ds.unionBySize(group[j], group[j-1]);
        }
    }
    vector<int> ans(n);
    for (int i=1; i<=n; i++) {
        int par = ds.findUPar(i);
        ans[i-1] = ds.size[par];
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