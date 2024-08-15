// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1900/A

#include <bits/stdc++.h>
using namespace std;

// Count the number of continuous '.', if no. >= 3, then it can be filled with 2 '1'
// In the fifth testcase, 
// 10
// #...#..#.#
// Here, we can first fill the 3 continuous with 2 '1's and then take action '2' to 
// fill the rest empty cells from the middle of the 3 continuous cells
// So, basically if any continuous sequence of 3 '.', entire thing can be filled 
// with 2 actions '1', else count the number of '.' if no >= 3 '.'s exists.

int main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        string input;
        cin >> input;
        int a = 0;
        int count = 0;
        int continuous = 0;
        for (int i=0; i<n; i++) {
            if (input[i]=='.') {
                a+=1;
                count+=1;
            }
            else {
                if (continuous < a) continuous = a;
                a = 0;
            }
        }     
        // there may never be '#' and that if block will never be entered then, so continuous will never be updated
        if (continuous < a) continuous = a; 
        if (continuous >= 3) cout << 2 << endl; // continuous subsequence of >=3 exists
        else cout << count << endl; // the no. of '.' 

    }
    
    return 0;
}