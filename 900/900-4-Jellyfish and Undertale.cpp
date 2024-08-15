// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1875/A

#include <bits/stdc++.h>
using namespace std;
#define int long long

// First let b reach 1, then always use tool, order doesn't matter.
// if n_i < a, just add it to b, if greater, then add a to b (but subtract 1 here),
// because resetting leads b to a-1 (to bring it down to 1), & takes 1 sec, so that total (a-1)+1 = a
// But, if directly add, then b=1 so 1+a which is 1 more.
// total sum n_i according to the above rule + b = total time 

signed main(){

    int t, a, b, n;
    cin >> t;
    while (t--){
        cin >> a >> b >> n;
        int array[n];
        for (int i=0; i<n; i++) {
            cin >> array[i];
        }     
        int sum = b;
        for (int i=0; i<n; i++) {
            if (array[i] < a) sum += array[i];
            else sum += (a-1);
        }           
        cout << sum << endl;

    }
    
    return 0;
}