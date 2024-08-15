// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1703/F

#include <bits/stdc++.h>
using namespace std;

// Put only indices that satisfy the property a_i < i, this data structure will be sorted as processed in order
// Binary Search to find no. of indices smaller than a_i
// Add current index to the data structure

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, input;
    cin >> n;
    vector<int> indices;
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        cin >> input;
        if (input>=i) continue;
        else {
            auto it = lower_bound(all(indices), input);
            int idx = distance(indices.begin(), it);
            // cout << "i = " << i << ", input = " << input << ", idx = " << idx << endl;
            cnt += idx;
            indices.pb(i);
        } 
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