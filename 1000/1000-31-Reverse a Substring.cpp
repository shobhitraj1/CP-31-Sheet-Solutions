// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1155/A

#include <bits/stdc++.h>
using namespace std;
#define int long long

// Reverse the first found non alphabetical pair can result in less lexicographical string
// If not found, then not possible

signed main(){

    int n;
    cin >> n;
    string input;
    cin >> input;
    string output = "NO";
    int x;
    for (int i=1; i<n; i++) {
        if (input[i]<input[i-1]){
            output = "YES";
            x=i;
            break;
        }
    }     
    if (output == "YES") {
        cout << "YES" << endl;
        cout << x << " " << x+1 << endl;
    }
    else cout << "NO" << endl;
    
    return 0;
}