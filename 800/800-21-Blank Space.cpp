// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1829/B

#include <bits/stdc++.h>
using namespace std;

// Count longest segment of consecutive 0's

int main(){

    int t, n, input, a, b;
    cin >> t;
    while (t--){
        cin >> n;
        a = 0;
        b = 0;
        for (int i=0; i<n; i++){
            cin >> input;
            if (input == 0) a+=1;
            else if (input == 1) { // update condition inside input == 1
                if (b<a){
                    b=a;
                }
                a=0;
            }
            if (b<a){ // what if only zeroes, so never get updated
                b=a;
            }
        }
        cout << b << endl;
    }

    return 0;
}