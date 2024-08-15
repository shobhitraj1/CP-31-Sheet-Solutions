// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1869/A

#include <bits/stdc++.h>
using namespace std;
#define int long long

// a^a = 0
// a^0 = a
// Take bitwise XOR of all the numbers in the array, replace each by the result
// if n=even - When take bitwise XOR again, it will be res ^ res ^ res...= 0
// if n=odd (n>=3), break into 3 and n-3 arrays, n-3 will be even...
// for size 3 array :-
// 1 2, 1 2, 2 3, 2 3

signed main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        int array[n];
        for (int i=0; i<n; i++) {
            cin >> array[i];
        }  
        if (n%2==0) {
            cout << 2 << endl;
            cout << 1 << " " << n << endl;   
            cout << 1 << " " << n << endl;   
        }
        else {
            if (n==3) {
                cout << 4 << endl;
                cout << 1 << " " << 2 << endl;
                cout << 1 << " " << 2 << endl;
                cout << 2 << " " << 3 << endl;
                cout << 2 << " " << 3 << endl;
            }
            else {
                cout << 6 << endl;
                cout << 1 << " " << 2 << endl;
                cout << 1 << " " << 2 << endl;
                cout << 2 << " " << 3 << endl;
                cout << 2 << " " << 3 << endl;
                cout << 4 << " " << n << endl;
                cout << 4 << " " << n << endl;
            }
        }

    }
    return 0;
}