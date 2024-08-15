// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1857/A

#include <bits/stdc++.h>
using namespace std;

// If parity = odd --> sum = 4k+2
// If parity = even --> sum = 4k

int main(){

    int t, n, input;
    cin >> t;
    while (t--){
        cin >> n;
        int sum = 0;
        for (int i=0; i<n; i++){
            cin >> input;  
            sum += input;       
        }
        if (sum%4 == 0 || sum%4 == 2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}