// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1771/B

#include <bits/stdc++.h>
using namespace std;

// Use 2 pointers approach
// Compute the no of good subsegments ending at each index => ans += (r-l+1)
// For l, maintain the largest l that is not friend of each index upto that i (here l<index for each i)
// So, when i-1 is not friend of i, then l=r=i => ans += 1

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, m, u, v;
    cin >> n >> m;
    // vector<set<int>> enemy(n+1);
    vector<int> enemy(n+1, 0);
    for (int i=0; i<m; i++) {
        cin >> u >> v;
        if (u>v) swap(u, v); 
        // enemy[u].insert(v);
        // enemy[v].insert(u);
        enemy[v] = max(enemy[v], u);
    }   
    // prefix computation to move l pointer correctly
    for (int i=2; i<=n; i++) {
        enemy[i] = max(enemy[i], enemy[i-1]);
    }
    int l = 1;
    int r = 2;
    int ans = 1;
    while (r<=n) {
        // if any enemy pair between [l,r] --> increase l such that no such pair or l==r
        // need smallest l to be in [l, r] such that noting in [l, r] is in enemy[x] where x=[l, r] 
        // Basically (last l that was in enemy[r])+1
        l = enemy[r]+1;
        ans += (r-l+1);
        r++; // O(n)
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