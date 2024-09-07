// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1486/B

#include <bits/stdc++.h>
using namespace std;

// The problem can be broken into 1-D problem
// As the shortest summation of distances in sorted points is between all the points between and including left and right median
// Possible candidates for x coordinate of the exhibition => Sort X and no of points b/t & incl. both medians
// Possible candidated for y coordinate of the exhibition => Sort Y and no of points b/t & incl. both medians
// Total points possible = x*y (as if we change the x coordinate the sum of distances by y is not changed at all & tptal stays minimum)

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n;
    cin >> n;
    vector<int> X(n), Y(n);
    for (int i=0; i<n; i++) {
        cin >> X[i] >> Y[i];
    }   
    sort(all(X)); sort(all(Y));
    int x = X[n/2] - X[(n+1)/2 - 1] + 1; // 0-based indexing
    int y = Y[n/2] - Y[(n+1)/2 - 1] + 1;
    cout << x*y << endl;
    
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