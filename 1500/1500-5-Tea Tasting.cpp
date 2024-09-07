// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1795/C

#include <bits/stdc++.h>
using namespace std;

// Calculate for i-th tea, how many people from i-th to n will be able to drink from it
// Use prefix sum concept with binary search

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

void solve() {
    int n;
    cin >> n;
    vector<int> tea(n+1), capacity(n+1), prefCap(n+1, 0);
    for (int i=1; i<=n; i++) {
        cin >> tea[i];
    }   
    for (int i=1; i<=n; i++) {
        cin >> capacity[i];
        prefCap[i] = prefCap[i-1] + capacity[i];
    }  
    // print(tea);
    // print(capacity);
    // print(prefCap);
    prefCap.pb(INF);
    vector<int> prefix(n+2, 0), extra(n+2, 0);
    for (int i=1; i<=n; i++) {
        int target = tea[i] + prefCap[i-1];
        // cout << i << " = " << target << endl;
        int idx = lower_bound(prefCap.begin(), prefCap.end(), target) - prefCap.begin();
        // cout << idx << endl;
        // if (idx == i)
        if (prefCap[idx] == target) {
            prefix[i] += 1;
            prefix[idx+1] -= 1;
        }
        else if (prefCap[idx] > target) {
            prefix[i] += 1;
            prefix[idx] -= 1;
            extra[idx] += (target - prefCap[idx-1]);
        }
    }
    // print(prefix);
    for (int i=1; i<n+2; i++) {
        prefix[i] += prefix[i-1];
    }
    // print(prefix);
    // print(extra);
    vector<int> ans(n+1, 0);
    for (int i=1; i<=n; i++) {
        ans[i] = (prefix[i]*capacity[i]) + extra[i];
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