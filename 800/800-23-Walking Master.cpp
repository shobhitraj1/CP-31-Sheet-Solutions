// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1806/A

#include <bits/stdc++.h>
using namespace std;

// brute force geometry - count the moves & see if valid

int main(){

    int t, a, b, c, d;
    cin >> t;
    while (t--){
        cin >> a >> b >> c >> d;
        if (d<b) cout << -1 << endl;
        else {
            int moves = d-b;
            if (c <= (a+moves)) cout << (a+moves)-c + moves<< endl;
            else cout << -1 << endl;
        }
    }

    return 0;
}