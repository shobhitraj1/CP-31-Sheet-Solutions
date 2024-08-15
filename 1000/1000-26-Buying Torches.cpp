// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1418/A

#include <bits/stdc++.h>
using namespace std;
#define int long long

// First fulfilling requirement of k coals - which requires k trades & ky sticks
// Have x sticks at first, lets say m trades happen, then mx sticks will be produced
// so that mx>=ky (as ky is required) & left sticks will be (x-m)+(mx-ky) >= k sticks
// m = ceil (k+ky-x)/(x-1), also, just add 1 later for the first trade to obtain x sticks from first stick
// Total trades = m + k + 1

int ceil(int a, int b) {
    return (a + b - 1) / b;
}

signed main(){

    int t, x, y, k;
    cin >> t;
    while (t--){
        cin >> x >> y >> k;
        int m = ceil(k+k*y-x,x-1);
        int ans = m+k+1;
        cout << ans << endl;
    }
    
    return 0;
}