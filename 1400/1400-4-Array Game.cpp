// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1904/C

#include <bits/stdc++.h>
using namespace std;

// Minimum ans can be 0, if k>=3, can just choose same 2 elements in the first 2 operations 
// and then select 2 newly appended elements for the third operation and they will be equal, so ans = 0
// For k=1 & k=2 (Brute force every pair as n<=2x10^3)

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }   
    if (k>=3) cout << 0 << endl;
    else {
        sort(all(array));
        if (k==1) {
            int mini = INF;
            for (int i=1; i<n; i++) {
                mini = min(mini, array[i]-array[i-1]);
            }
            mini = min(mini, array[0]);
            cout << mini << endl;
        }
        else {
            int mini = array[0];
            for (int i=0; i<n; i++) {
                for (int j=i+1; j<n; j++) {
                    int ans = array[j]-array[i];
                    mini = min(mini, ans);
                    auto it = lower_bound(all(array), ans);
                    int idx = distance(array.begin(), it);
                    if (idx<n) mini = min(mini, abs(array[idx]-ans));
                    if (idx>0) mini = min(mini, abs(array[idx-1]-ans));
                    if (idx+1<n) mini = min(mini, abs(array[idx+1]-ans));
                }
            }
            cout << mini << endl;            
        }
    }
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