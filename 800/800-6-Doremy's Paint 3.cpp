// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1890/A

#include <bits/stdc++.h>
using namespace std;

// b1 = b3 = b5 = ...
// b2 = b4 = b6 = ...

int main(){

    int t, n, input;
    cin >> t;
    while (t--){
        cin >> n;
        int count = 0;
        int a, b;
        int array[100000] = {0};
        for (int i=0; i<n; i++){
            cin >> input;
            array[input-1] += 1;
        }
        for (int i=0; i<100000; i++){
            if (array[i] != 0) count += 1;
        }
        // count represents the no. of distinct elements - can never be 0 
        // cout << "count = " << count << endl;
        if (count > 2) cout << "NO" << endl; 
        else {
            if (count == 1) cout << "YES" << endl;
            else if (count == 2) {
                // check if the counts of the 2 distinct elements are either equal or differ by 1.
                int i=0;
                for (i; i<100000; i++){
                    if (array[i] != 0) { // 2 such positions will come - 1st
                       a = array[i];
                       break;
                    }
                }
                // cout << "i = " << i << endl;
                i += 1;
                for (i; i<100000; i++){
                    if (array[i] != 0) { // 2 such positions will come - 2nd
                       b = array[i];
                       break;
                    }
                }
                // cout << "a = " << a << ", b = " << b << endl;
                if (a==b || a-b == 1 || b-a == 1) cout << "YES" << endl;
                else cout << "NO" << endl;
                
            }
        }
    }

    return 0;
}