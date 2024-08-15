// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1845/A

#include <bits/stdc++.h>
using namespace std;

// if even --> n = n/2 2's sum
// if odd & k>=3, hence n>=3, so, n = 3 + (n-3)/2 2's sum

int main(){

    int t, n, k, x;
    cin >> t;
    while (t--){
        cin >> n >> k >> x;
        if (k==1) cout << "NO" << endl; // k = x = 1 --> no positive sum possible
        else {
            if (x!=1) { // n = n 1's sum
                cout << "YES" << endl;
                cout << n << endl;
                for (int i=0; i<n; i++){
                    cout << 1 << " ";
                }
                cout << endl;
            }
            else {
                if (n%2==0) { // n is even --> n = n/2 2's sum
                    cout << "YES" << endl;
                    cout << n/2 << endl;
                    for (int i=0; i<n/2; i++){
                        cout << 2 << " ";
                    }
                    cout << endl;
                }
                else {
                    if (k==2) {
                        cout << "NO" << endl;
                    }
                    else { // k>=3, hence n>=3, so, n = 3 + (n-3)/2 2's sum
                        cout << "YES" << endl;
                        n = n - 3;
                        cout << n/2 + 1 << endl;
                        cout << 3 << " ";
                        for (int i=0; i<n/2; i++){
                            cout << 2 << " ";
                        }
                        cout << endl;
                    }
                }
            }
        }

    }
    
    return 0;
}