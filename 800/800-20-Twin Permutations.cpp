// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1831/A

#include <bits/stdc++.h>
using namespace std;

// b_i = (n+1) - a_i

int main(){

    int t, n, a, b;
    cin >> t;
    while (t--){
        cin >> n;
        for (int i=0; i<n; i++){
            cin >> a;
            b = n+1-a;
            cout << b << " ";
        }
        cout << endl;
    }

    return 0;
}