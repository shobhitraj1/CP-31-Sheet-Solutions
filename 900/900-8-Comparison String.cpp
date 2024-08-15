// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1837/B

#include <bits/stdc++.h>
using namespace std;
#define int long long

// count the largest sequence of < or > occuring in success array
// answer will be (max_count + 1)

signed main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        string input;
        cin >> input;
        int count = 1;
        int max = 0;
        for (int i=1; i<n; i++) {
            if (input[i]==input[i-1]) count+=1;
            else {
                if (count > max) max = count;
                count = 1;
            }
        }     
        if (count > max) max = count;
        cout << max+1 << endl;
    }
    
    return 0;
}