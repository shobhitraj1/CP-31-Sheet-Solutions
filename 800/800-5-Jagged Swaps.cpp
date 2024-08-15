// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1896/A

#include <bits/stdc++.h>
using namespace std;

// basically as the first element can never be swapped, if its not 1, then
// array can never have 1 on first position and will never be sorted.
// if it has 1, then others can be easily and always swapped to make it sorted

int main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        int array[n];
        for (int i=0; i<n; i++) {
            cin >> array[i];
        }  
        if (array[0]==1) cout << "YES" << endl;
        else cout << "NO" << endl;   

        // Swaping and then checking if sorted or not

        // for (int i=1; i<n-1; i++) {
        //     if (array[i] > array[i-1] && array[i] > array[i+1]){
        //         array[i] = b;
        //         array[i] = array[i+1];
        //         array[i+1] = b;
        //         if (i!=1) i -= 2;
        //     }
        // }
        // for (int i=1; i<n; i++) {
        //     if (array[i] < array[i-1]) {
        //         output = "NO";
        //         break;
        //     }
        // }
        // cout << output << endl;

    }
    
    return 0;
}