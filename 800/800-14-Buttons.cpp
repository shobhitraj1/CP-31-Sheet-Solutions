// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1858/A

#include <bits/stdc++.h>
using namespace std;

// first --> ceil(c/2) + a
// second --> floor (c/2) + a
// first wins only if first > second as started by first (= case --> second wins)

int main(){

    int t, a, b, c;
    cin >> t;
    while (t--){
        cin >> a >> b >> c;
        if (c%2==0){
            if (a>b) cout << "First" << endl;
            else cout << "Second" << endl;
        }
        else {
            if (a+1>b) cout << "First" << endl;
            else cout << "Second" << endl;
        }
    }

    return 0;
}