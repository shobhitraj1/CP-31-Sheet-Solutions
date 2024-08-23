// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1320/A

#include <bits/stdc++.h>
using namespace std;

// As C_i+1 - C_i = B[C_i+1] - B[C_i] => B[C_i+1] - C_i+1 = B[C_i] - C_i
// So, store the indices for resultant B[C_i] - C_i for all i's
// For each B[C_i] - C_i value, compute the beauty of that sequence & take their maximum

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n;
    cin >> n;
    vector<int> array(n);
    map <int, vector<int>> mp;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        mp[array[i]-i].pb(i);
    }   
    int sum = 0;
    for (auto elem : mp) {
        int ans = 0;
        auto vec = elem.second;
        for (int i=0; i<vec.size(); i++) {
            ans += array[vec[i]];
        }
        sum = max(sum, ans);
    }
    cout << sum << endl;
   
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