// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1881/A

#include <bits/stdc++.h>
using namespace std;

// brute force - concatenating x till find s (5 times as max. string length is 25)

int main(){
  
    int t, n, m;
    cin >> t;
    while (t--){
        cin >> n >> m;
        string x, s;
        cin >> x;
        cin >> s;
        int ans = -1;
        if (x.find(s)!=std::string::npos) ans = 0;
        else {
            for (int i=1; i<=5; i++){
                x = x + x;
                if (x.find(s)!=std::string::npos) {
                    ans = i;
                    break;
                }
            }
        }
        cout << ans << endl;

    }
    
    return 0;
}