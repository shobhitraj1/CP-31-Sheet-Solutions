// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1374/B

#include <bits/stdc++.h>
using namespace std;

// Check after multiplying by some 2^k (for k>=0), is it a multiple of 6 or not

int main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        int ans = -1;
        if (n==1) ans = 0;
        else if (n%3!=0) ans = -1;
        else {
            int factor3 = 0;
            int n3 = n;
            while (n3%3==0){
                factor3 += 1;
                n3/=3;
            }
            int n2 = n;
            int factor2 = 0;
            while (n2%2==0){
                factor2 += 1;
                n2/=2;
            }
            // cout << factor2 << " " << factor3 << endl;
            if (factor2>factor3) ans = -1;
            else {
                int m = n;
                for (int i=0; i<factor3-factor2; i++){
                    m*=2;
                }
                int factor6 = 1;
                for (int i=0; i<factor3; i++){
                    factor6*=6;
                }
                if (m!=factor6) ans = -1;
                else ans = (factor3-factor2) + factor3;
            }
        }
        cout << ans << endl;

    }
    
    return 0;
}