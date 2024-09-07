// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1416/A

#include <bits/stdc++.h>
using namespace std;

// Check for numbers in increasing order, the least k for which they are present in evry subsegment of length k
// For that store the indices at which they occur, and check the maximum length its not present
// And, if num is present in every k length subsegment, then it will be present in k+1 to n length subsegment too (as iterating in increasing order)

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, input;
    cin >> n;
    map<int, vector<int>> mp;
    for (int i=0; i<n; i++) {
        cin >> input;
        mp[input].pb(i+1);
    }   
    vector<int> ans(n+1, -1);
    for (auto elem : mp) {
        int num = elem.first;
        auto vec = elem.second;
        int cur = 0; int maxi = 0;
        vec.pb(n+1);
        for (int i=0; i<vec.size(); i++) {
            maxi = max(maxi, vec[i]-cur);
            cur = vec[i];
        }
        for (int i=maxi; i<=n; i++) {
            if (ans[i] != -1) break;
            else ans[i] = num;
        }
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
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
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}