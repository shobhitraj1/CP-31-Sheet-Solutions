// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1877/A

#include <bits/stdc++.h>
using namespace std;

// adding the efficiencies should equal 0 because of the 
// g12 - g21 in e1 and g21 - g12 in e2 will cancel out

int main(){

    int t, n, e;
    cin >> t;
    while (t--){
        cin >> n;
        int sum = 0;
        for (int i=0; i<n-1; i++){
            cin >> e;
            sum += e;
        }
        cout << 0 - sum << endl; 
    }

    return 0;
}