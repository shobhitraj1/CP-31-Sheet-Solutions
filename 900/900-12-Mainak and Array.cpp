// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1726/A

#include <bits/stdc++.h>
using namespace std;
#define int long long

// can be max(a_i - a1, a_(i-1) - a_i, a_n - a_i) for all 2<=i<=n
// a_i - a1 --> fix first element, and rotate others
// a_(i-1) - a_i --> rotate such that d/f b/t 2 consecutive elements
// a_n - a_i --> fix last element, and rotate others

signed main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        int array[n];
        for (int i=0; i<n; i++) {
            cin >> array[i];
        }     
        if (n==1) cout << 0 << endl;
        else if (n==2) cout << max(array[1] - array[0], array[0] - array[1]) << endl;
        else {
            int max=0;
            for (int i=1; i<n; i++) {
                if ((array[i] - array[0]) > max) max = (array[i] - array[0]);
                if ((array[i-1] - array[i]) > max) max = (array[i-1] - array[i]);
                if ((array[n-1] - array[i]) > max) max = (array[n-1] - array[i]);
            } 
            cout << max << endl;
        }

    }
    
    return 0;
}