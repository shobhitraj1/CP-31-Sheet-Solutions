// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1471/A

#include <bits/stdc++.h>
using namespace std;
#define int long long

// Max. will be when all uncombined - unchanged array
// Min. will be when all are combined - array size 1 - this is because the residue will compensate the most

int ceil(int a, int b) {
    return (a + b - 1) / b;
}

signed main(){

    int t, n, x;
    cin >> t;
    while (t--){
        cin >> n >> x;
        int array[n];
        int sum = 0;
        int max = 0;
        for (int i=0; i<n; i++) {
            cin >> array[i];
            sum += array[i];
            max += ceil(array[i], x);
        }     
        int min = ceil(sum, x);
        cout << min << " " << max << endl;
        
    }
    
    return 0;
}