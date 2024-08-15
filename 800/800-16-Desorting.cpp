// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1853/A

#include <bits/stdc++.h>
using namespace std;

// if array already unsorted --> '0'
// if sorted --> find MINIMUM dif = a_(i+1) - a_i such that a_(i+1) >= a_i
// Answer = floor(dif/2) + 1

int main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        int array[n];
        int output = 1;
        int dif = INT_MAX;
        for (int i=0; i<n; i++) {
            cin >> array[i];
        }     
        for (int i=1; i<n; i++) {
            if (array[i] < array[i-1]) { // already unsorted
                output = 0;
                break;
            }
            else {
                if (dif > (array[i] - array[i-1])) {
                    dif = array[i] - array[i-1];
                }
            }
        } 
        if (output != 0) {
            output = (dif/2) + 1;
        }
        cout << output << endl;

    }
    
    return 0;
}