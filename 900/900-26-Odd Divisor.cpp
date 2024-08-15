// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1475/A

#include <bits/stdc++.h>
using namespace std;
#define int long long

// number n will be always be an odd multiple of itself if n=odd
// n will have off factor unless it's a power of 2

signed main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        while (n%2==0){
            n/=2;
        }
        if (n==1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    
    return 0;
}