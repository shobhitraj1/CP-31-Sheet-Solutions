// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1878/C

#include <bits/stdc++.h>
using namespace std;
#define int long long

// k integers in [1,n]
// Min. sum possible = k(k+1)/2
// Max. sum possible = n + (n-1) + (n-2) + ... + (n-(k-1))
// Any sum b/t min. and max. are possible
// To have sum <- sum+1, remove any a_i from set of k elements, and insert a_i+1 from n/k set, 
// this is only not possible when max. possible case which is the upper bound 

signed main(){

    int t, n, k, x;
    cin >> t;
    while (t--){
        cin >> n >> k >> x;
        int min = (k*(k+1))/2;
        // int max = 0;
        // for (int i=0; i<k; i++){
        //     max += (n-i);
        // }
        int max = n*k - (k*(k-1))/2;
        if (x<min || x>max) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    
    return 0;
}