// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1855/B

#include <bits/stdc++.h>
using namespace std;
#define int long long

// Have to find the largest consecutive sequence of numbers such that all of them are factors of n
// If n%k≠0, then max. size < k --> because every sequence of size k will have atleast one number
// divisible by k, & if that number in the sequence divides n, then k|n which contradicts
// Hence, start checking from 2,3,4,...

signed main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        int i = 2;
        for (i; i<=n; i++) {
            if (n%i!=0) break;
        }
        cout << i-1 << endl;        
        
    }
    
    return 0;
}