// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1837/A

#include <bits/stdc++.h>
using namespace std;

// if k | x, then k will not divide x-1 and 1 (k>=2)

int main(){
    int t, x, k;
    cin >> t;
    while (t--){
        cin >> x >> k;
        if(x%k!=0) {
            cout << 1 << endl;
            cout << x << endl;
        }
        else {
            cout << 2 << endl;
            cout << x-1 << " " << 1 << endl;
        }
    }

    return 0;
}