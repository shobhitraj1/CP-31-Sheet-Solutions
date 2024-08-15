// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1679/A

#include <bits/stdc++.h>
using namespace std;
#define int long long

// n = 4x + 6y where x,y are W
// min. (x+y) & max. (x+y)
// if n=odd --> -1
// max. buses = n/4 or (n-6)/4, whichever is greater integer (4k, 4k±2) - k, (k-1)+1
// min. buses = n/6 or (n-8)/6 or (n-4)/6, whichever is least integer (6k, 6k±2, 6k±4) - k, (k-1)+2, (k)+1

signed main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        if (n%2!=0 || n<4) cout << -1 << endl; // when n is odd or n=2
        else {
            int max = n/4;
            int min;
            if (n%6!=0) { // when n>=6
                min = (n/6) + 1; 
            }
            else min = n/6;
            if (n==4) min=1; // when n=4
            cout << min << " " << max << endl;
        }

    }
    
    return 0;
}