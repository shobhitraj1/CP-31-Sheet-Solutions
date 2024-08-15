// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1607/B

#include <bits/stdc++.h>
using namespace std;
#define int long long

// if x_o = even --> -1+2+3-4-5+6+7-8-9+... uptill n
// if x_o = odd --> 1-2-3+4+5-6-7+8+9-10-11+...+ uptill n
// But if n is very large, will give TLE if for loop till n
// Optimized approach --> the sequence is -1+5-9+13..., like AP with d=4
// if x_o = even --> every n>=4, if n=4k, sum uptill is 0 and then -,+,+,-,-...
// if x_o = odd --> every n>=4, if n=4k, sum uptill is 0 and then +,-,-,+,+...
// that's why set count=1 in this case when starting...

signed main(){

    int t, x, n;
    cin >> t;
    while (t--){
        cin >> x >> n;
        if (x%2==0) {
            if (n<=4) {
                int count = 0, j = -1;
                for (int i=0; i<=n; i++) {
                    if (count==2) {
                        count = 0;
                        j*=-1;
                    }
                    x+=(i*j);
                    count+=1;
                }
            }
            else {
                int m = n/4;
                int k = m*4;
                // x+=0;
                int count = 1, j = -1;
                for (int i=k+1; i<=n; i++){
                    if (count==2) {
                        count = 0;
                        j*=-1;
                    }
                    x+=(i*j);
                    count+=1;
                }
            }
            

        }
        else {
            if (n<=4) {
                int count = 0, j = 1;
                for (int i=0; i<=n; i++) {
                    if (count==2) {
                        count = 0;
                        j*=-1;
                    }
                    x+=(i*j);
                    count+=1;
                }
            }
            else {
                int m = n/4;
                int k = m*4;
                // x+=0;
                int count = 1, j = 1;
                for (int i=k+1; i<=n; i++){
                    if (count==2) {
                        count = 0;
                        j*=-1;
                    }
                    x+=(i*j);
                    count+=1;
                }
            }
        }
        cout << x << endl;
    }
    
    return 0;
}