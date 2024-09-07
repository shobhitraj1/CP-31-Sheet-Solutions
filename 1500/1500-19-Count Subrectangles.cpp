// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1323/B

#include <bits/stdc++.h>
using namespace std;

// k area rectangles can only be made if n1 consecutive 1's in the columns & n2 consecutive 1's in the rows & n1*n2 = k
// So compute the number of factors of k and for each factor of k, check if its n1 in cols and check for k/n1 in rows
// As, no of factors = cbrt(k), map of cols and rows that have consecutive 1's count, maximum distinct entries will be 200 (as 200*201/2 ≈ 1e4 [n.m])
// So, time complexity = O(cbrt(k)*200*200), where maximum k is 4e4.

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> col(n), row(m);
    for (int i=0; i<n; i++) {
        cin >> col[i];
    }   
    for (int i=0; i<m; i++) {
        cin >> row[i];
    }   
    vector<int> factors;
    for (int i=1; i*i<=k; i++) {
        if (k%i==0) {
            factors.pb(i);
            if (i!=k/i) factors.pb(k/i);
        }
    }
    int cnt = 0;
    map<int,int> cols, rows;
    for (int i=0; i<n; i++) {
        if (col[i] == 1) cnt++;
        else {
            if(cnt) cols[cnt]++;
            cnt = 0;
        }
    }
    if(cnt) cols[cnt]++;
    cnt = 0;
    for (int i=0; i<m; i++) {
        if (row[i] == 1) cnt++;
        else {
            if(cnt) rows[cnt]++;
            cnt = 0;
        }
    }
    if(cnt) rows[cnt]++;
    int ans = 0;
    int f = factors.size();
    for (int factor = 0; factor < f; factor++) {
        for (auto x : cols) {
            if (x.first < factors[factor]) continue;
            for (auto y : rows) {
                if (y.first < k/factors[factor]) continue;
                int n1 = x.second*(x.first-factors[factor]+1);
                int n2 = y.second*(y.first-(k/factors[factor])+1);
                ans += (n1*n2);
            }
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
    // cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}