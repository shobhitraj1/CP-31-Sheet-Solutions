// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1761/A

#include <bits/stdc++.h>
using namespace std;

// if n = 1 => a=b=1 --> YES
// if n = a or b and a≠b --> NO
// diff =  n - (a+b)
// diff > 1 --> YES, as can reorder the elements in the middle
// diff = 1 --> NO as a = b and will be n
// diff < 1 --> NO as the common elements in the overlapping 
// prefix and suffix are not same, a = b and will be n

int main(){

    int t, n, a, b;
    cin >> t;
    while (t--){
        cin >> n >> a >> b;
        if (n==1) cout << "YES" << endl;
        else {
            if (n==a || n==b){
                if (a!=b) cout << "NO" << endl;
                else cout << "YES" << endl; // any permutation
            }
            else {
                int diff = n - (a+b);
                if (diff<=1) cout << "NO" << endl;
                else cout << "YES" << endl;
            }
        }

        

    }
    
    return 0;
}