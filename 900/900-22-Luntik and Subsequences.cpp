// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1582/B

#include <bits/stdc++.h>
using namespace std;
#define int long long

// 0's = a
// 1's = b
// 2^a*b

signed main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        int input;
        int count0 = 0;
        int count1 = 0;
        for (int i=0; i<n; i++) {
            cin >> input;
            if (input==0) count0+=1;
            if (input==1) count1+=1;
        }     
        int ans = pow(2,count0)*count1;
        cout << ans << endl;

    }
    
    return 0;
}