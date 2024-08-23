// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1143/C

#include <bits/stdc++.h>
using namespace std;

// have to delete the vertex if it is itself marked and all its children is marked

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, par, mark;
    cin >> n;
    vector<vector<int>> adj(n+1);
    vector<bool> marked(n+1, false);
    for (int i=1; i<=n; i++) {
        cin >> par >> mark;
        if (par == -1) continue;
        adj[par].pb(i);
        if (mark) marked[i] = true;
    }
    set <int> st;
    for (int i=1; i<=n; i++) {
        if (marked[i]) {
            bool allChildrenMarked = true;
            for (int child : adj[i]) {
                if (!marked[child]) allChildrenMarked = false;
            }
            if (allChildrenMarked) st.insert(i);
        }
    }
    if (st.size()==0) cout << -1;
    for (int elem : st) {
        cout << elem << " ";
    }
    cout << endl;    
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