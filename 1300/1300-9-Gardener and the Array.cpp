// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1775/B

#include <bits/stdc++.h>
using namespace std;

// if only one bit is set for a number, then that number has to deleted or added to both the subsequences
// But, if such numbers' count is n, then both subsequence will have all the elements or will be equal, hence not possible
// Hence, check how many such numbers exist

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;
const int N = 2e5+10;

void solve() {
    int n, k, input;
    cin >> n;
    map<int, pair<int, int>> mp;
    for (int i=0; i<n; i++) {
        cin >> k;
        for (int j=0; j<k; j++) {
            cin >> input;
            mp[input].first++;
            mp[input].second=i;
        }
    }
    unordered_set<int> st;
    for (auto& elem : mp) {
        if (elem.second.first==1) st.insert(elem.second.second);
    }
    if (st.size() == n) cout << "No" << endl;
    else cout << "Yes" << endl;    
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