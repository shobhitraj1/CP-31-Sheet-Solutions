// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1788/A

#include <bits/stdc++.h>
using namespace std;

// use the fact that input are only 1 and 2 - Don't multiply and check - INT overflow
// 1's = a
// 2's = b
// If b is odd --> NOT Possible --> '-1'
// If b is even --> k = where b/2 2's appear

int main(){

    int t, n, a, b, count;
    cin >> t;
    while (t--){
        cin >> n;
        int array[n];
        a = 0;
        b = 0;
        count = 0;
        for (int i=0; i<n; i++) {
            cin >> array[i];
            if (array[i] == 1) a+=1;
            else b+=1;
        }
        if (b%2 != 0) cout << -1 << endl;
        else {
            if (b==0) cout << 1 << endl;
            else {
                for (int i=0; i<n; i++) {
                    if (array[i] == 2) {
                        count+=1;
                        if (count == b/2) cout << i+1 << endl;
                    }
                }
            }
        }

        
    }

    return 0;
}