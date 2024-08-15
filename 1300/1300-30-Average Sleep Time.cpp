// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/808/B

#include <bits/stdc++.h>
using namespace std;

// sliding window with fixed size = k, add the tempSum to total sum
// Take mean of the total sum for (n-k+1) weeks [use double, fixed & setprecision]

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
    int sum = 0, tempSum = 0;
    int l=0, r=0;
    while (r<n) {
        tempSum+=array[r];
        if (r-l+1>k) {
            tempSum-=array[l];
            l++;
        }
        if (r-l+1==k) sum += tempSum;
        r++;
    }  
    double ans = (sum*1.0)/(n-k+1);
    cout << fixed << setprecision(8) << ans << endl;
    
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