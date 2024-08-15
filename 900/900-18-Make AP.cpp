// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1624/B

#include <bits/stdc++.h>
using namespace std;
#define int long long

// just check the 3 cases possible

signed main(){

    int t, a, b, c;
    cin >> t;
    while (t--){
        cin >> a >> b >> c;
        if (a==b && b==c) cout << "YES" << endl; // m=1, multiply any
        else {
             
            string output = "NO";
            // Case 1 - have to change a
            int d = c-b; 
            if (b-d!=0) {
                int m = (b-d)/a;
                if (a*m==b-d && m>0) output = "YES";
            }

            // Case 2 - have to change b
            d = c-a;
            if (d%2==0) {
                d/=2;
                if (a+d!=0) {
                    int m = (a+d)/b;
                    if (b*m==a+d & m>0) output = "YES";
                }
            } 

            // Case 3 - have to change c
            d = b-a;
            if (b+d!=0){
                int m = (b+d)/c;
                if (c*m==b+d && m>0) output = "YES";
            }

            cout << output << endl;
        }   

    }
    
    return 0;
}