// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1919/C

#include <bits/stdc++.h>
using namespace std;

// greedy approach, maintain 2 arrays and add elements to it

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, input;
    cin >> n;
    int ans = 0, last1 = INF, last2 = INF;
    for (int i=0; i<n; i++) {
        cin >> input;
        if (last1>last2) swap(last1, last2);
        if (input <= last1) last1 = input;
        else if (input <= last2) last2 = input;
        else {
            last1 = input; 
            ans++;
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
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}