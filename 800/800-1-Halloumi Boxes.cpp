// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1903/A

#include <bits/stdc++.h>
using namespace std;
#define int long long

// Can also reverse after reversing - many iterations
// Eg. - 
// 3 2
// 3 2 1 --> output should be "YES" --> think of bigger example of this

// If k>=2, use k as 2, i.e. swap 2 elements at a time & can always make sorted
// (as no of swaps/reverses doesn't matter)
// If k=1, only YES if already sorted, else can't

signed main(){

    int t, n, k;
    cin >> t;
    while (t--){
        cin >> n >> k;
        int array[n];
        string output = "YES";
        for (int i=0; i<n; i++) {
            cin >> array[i];
        }   
        // always possible as keep swapping 2 at a time  
        if (k>=2) cout << "YES" << endl; 
        else {
            for (int i=1; i<n; i++) {
                if (array[i] < array[i-1]) {
                    output = "NO";
                    break;
                }
            }   
            cout << output << endl;
        }
    }
    
    return 0;
}