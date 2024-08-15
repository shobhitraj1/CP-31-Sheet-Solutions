// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1814/A

#include <bits/stdc++.h>
using namespace std;
#define int long long 

// long long as the constraints are 10^18
// n = 2.x + k.y
// n is even --> YES -> y=0, x=n/2
// n is odd --> 
//              k is odd --> YES -> y=1, odd - odd = even = 2.x
//              k is even --> NO -> even * something can't be odd


signed main(){

    int t, n, k;
    cin >> t;
    while (t--){
        cin >> n >> k;
        if(n%2==0) cout << "YES" << endl;
        else {
            if (k%2==0) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }

    return 0;
}