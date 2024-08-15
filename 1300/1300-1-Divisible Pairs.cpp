// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1931/D

#include <bits/stdc++.h>
using namespace std;

// Store the remainder for x & y, 
// for divisible by x, leftover remainder should be there and for that leftover
// for divisible by y, same remainder must be there

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, x, y, input;
    cin >> n >> x >> y;
    map <pair<int,int>, int> mp;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        cin >> input;
        int remX = input%x;
        if (remX==0) remX=x;
        int remY = input%y;
        cnt += mp[{x-remX, remY}];
        if (remX==x) remX=0;
        mp[{remX, remY}]++; 
    }
    cout << cnt << endl;

    // map <int, map<int, int>> mp; // map <pair<int,int>, int> mp; ({x, y} : cnt)
    // int cnt = 0;
    // for (int i=0; i<n; i++) {
    //     cin >> input;
    //     int remX = input%x;
    //     if (remX==0) remX=x;
    //     int remY = input%y;
    //     cnt += mp[x-remX][remY];
    //     if (remX==x) remX=0;
    //     mp[remX][remY]++;        
    // }
    // cout << cnt << endl;

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