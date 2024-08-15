// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1380/A

#include <bits/stdc++.h>
using namespace std;

// ith index (i>=1) such that a[i-1]<a[i]>a[i+1]

int main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        int array[n];
        for (int i=0; i<n; i++) {
            cin >> array[i];
        }  
        int x;
        string output = "NO";   
        for (int i=1; i<n-1; i++) {
            if (array[i-1]<array[i] && array[i+1]<array[i]){
                x=i;
                output = "YES";
                break;
            }
        }     
        if (output == "YES") {
            cout << "YES" << endl;
            cout << x << " " << x+1 << " " << x+2 << endl; // 0-based indexing
        }
        else cout << "NO" << endl;

    }
    
    return 0;
}