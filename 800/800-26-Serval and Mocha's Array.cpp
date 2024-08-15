// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1789/A

#include <bits/stdc++.h>
using namespace std;

// gcd is commutative & associative
// if any pair in the array has gcd <=2, then all the combinations will have 
// gcd <=2 -- not true for vice-versa - so can't check if total gcd <= 2
// Eg.- 15 35 21, not possible to make size 2 prefix with gcd <= 2
// So, have to check pairwise with double for loops

int main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        int array[n];
        int hcf;
        for (int i=0; i<n; i++) {
            cin >> array[i];
        }     
        string output = "NO";
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i!=j) {
                    if (__gcd(array[i], array[j]) <= 2) {
                        output = "YES";
                        break;
                    }
                }
            }   
        }    
        cout << output << endl; 
        

    }
    
    return 0;
}