// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1777/A

#include <bits/stdc++.h>
using namespace std;

// have to count the number of consecutive same parity pairs
// as multiplying them (operation) will result in same parity only
// Odd * Odd = Odd & Even * Even = Even

int main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        int array[n];
        int count = 0;
        for (int i=0; i<n; i++) {
            cin >> array[i];
        }  
        for (int i=1; i<n; i++) {
            if (array[i]%2 == array[i-1]%2) count += 1;
        }  
        cout << count << endl;


    }
    
    return 0;
}