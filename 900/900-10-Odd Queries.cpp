// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1807/D

#include <bits/stdc++.h>
using namespace std;
#define int long long

// optimize finding the parity of tempsum - used prefix sum for it

signed main(){

    int t, n, q;
    cin >> t;
    while (t--){
        cin >> n >> q;
        int array[n+1] = {0}; //1-based indexing
        int sum = 0;
        int tempsum[n+1] = {0};
        for (int i=1; i<=n; i++) {
            cin >> array[i];
            sum+=array[i];
            tempsum[i] = sum;
        }     
        int l, r, k;
        for (int i=0; i<q; i++) {
            cin >> l >> r >> k;
            // int m = (r-l+1)*k;
            // int tempsum = 0;
            // for (int i=l-1; i<r; i++) {
            //     tempsum += array[i];
            // }

            // optimize finding the parity of tempsum
            // for (int i=1; i<=n; i++) {
            //     cout << tempsum[i] << " ";
            // }
            // cout << endl;
            int temp = tempsum[r]-tempsum[l-1];
            int res = sum - temp + (r-l+1)*k;
            if (res%2==0) cout << "NO" << endl;
            else cout << "YES" << endl;
        }


    }
    
    return 0;
}