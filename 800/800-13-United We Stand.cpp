// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1859/A

#include <bits/stdc++.h>
using namespace std;

// just add the highest element (all of them) to C
// If all same, then not possible -> '-1'

int main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        int arr[n];
        int max = 0;
        int count = 0;
        for (int i=0; i<n; i++){
            cin >> arr[i];  
            if (max < arr[i]) max = arr[i];         
        }
        for (int i=0; i<n; i++){
            if (arr[i] == max) {
                count += 1;
            }       
        }
        // cout << "max = " << max << endl;
        // cout << "n = " << n << endl;
        // cout << "count = " << count << endl;
        if (count == n) cout << -1 << endl;
        else {
            cout << n-count << " " << count << endl;
            for (int i=0; i<n; i++){
                if (arr[i] != max) {
                    cout << arr[i] << " "; 
                }
            }
            cout << endl;
            for (int i=0; i<count; i++){
                cout << max << " "; 
            }
            cout << endl;      
        }
    }

    return 0;
}