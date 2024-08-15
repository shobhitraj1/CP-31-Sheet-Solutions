// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1828/B

#include <bits/stdc++.h>
using namespace std;
#define int long long

// Find the a[i] - i distance --> success array
// Find the gcd of all elements of success array

signed main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        int array[n];
        int success[n];
        int ans = 0;
        for (int i=0; i<n; i++) {
            cin >> array[i];
            success[i] = abs(array[i]-(i+1));
            ans = __gcd(ans, success[i]);
        }     
        // for (int i=0; i<n; i++) {
        //     cout << success[i] << " ";
        // }     
        // cout << endl;
        cout << ans << endl;

    }
    
    return 0;
}