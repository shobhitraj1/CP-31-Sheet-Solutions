// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1373/B

#include <bits/stdc++.h>
using namespace std;
#define int long long

// brute force removal of 01 & 10 from string until can't do it anymore

signed main(){

    int t;
    cin >> t;
    while (t--){
        string input;
        cin >> input;
        int n = input.length();
        int count = 0;
        for (int i=1; i<input.length(); i++) {
            if ((input[i]=='1' && input[i-1]=='0') || (input[i]=='0' && input[i-1]=='1')) {
                count+=1;
                input = input.substr(0, i-1) + input.substr(i + 1);
                // cout << "i = " << i << ", ";
                i-=2;
            }
        }   
        if (count%2==0) cout << "NET" << endl;
        else cout << "DA" << endl; 

    }
    
    return 0;
}