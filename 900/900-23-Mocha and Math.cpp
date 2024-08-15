// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1559/A

#include <bits/stdc++.h>
using namespace std;
#define int long long

// the bitwise AND of all elements will be the smallest possible answer that
// can be obtained, all other subsequence will give greater than this number.

signed main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        int array[n];
        for (int i=0; i<n; i++) {
            cin >> array[i];
        }     
        int ans = array[0];
        for (int i=1; i<n; i++) {
            ans &= array[i];
        }     
        cout << ans << endl;
    }

    return 0;
}