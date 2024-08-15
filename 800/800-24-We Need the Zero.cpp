// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1805/A

#include <bits/stdc++.h>
using namespace std;

// bitwise XOR is commutative & associative
// And, x ^ x = 0, x ^ 0 = x

int main(){

    int t, n, m;
    cin >> t;
    while (t--){
        cin >> n;
        int res = 0;
        for (int i=0; i<n;i++) {
            cin >> m;
            res = res ^ m;
        }
        if (n%2==0 && res!=0) cout << -1 << endl;
        else cout << res << endl;
    }

    return 0;
}