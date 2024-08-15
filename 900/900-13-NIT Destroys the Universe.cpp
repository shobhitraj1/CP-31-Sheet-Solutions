// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1696/B

#include <bits/stdc++.h>
using namespace std;
#define int long long

// Answers can be 0, 1 or 2
// Have to look how many groups between & except 0's
// if that no. of groups > 1, then output 2, as select entire and convert to some integer ≠ 0
// if <= 1, then output, no. of groups only

// Can also do just by counting no of 0's, if only one group of zeroes on either corner, then 1 operation, else 2, if all 0's then 0

signed main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        int array[n];
        int num;
        int count1 = 0, count0 = 0;
        for (int i=0; i<n; i++) {
            cin >> num;
            if (num!=0) array[i]=1;
            else array[i]=0;
        }    
        // for (int i=0; i<n; i++) {
        //     cout << array[i] << " ";
        // }
        // cout << endl;
        // if (count0 == n) cout << 0 << endl;
        // else if (count1 == n) cout << 1 << endl;
        // else {
            // count 01 and 10
            bool flag = false;
            int count = 0;
            for (int i=0; i<n; i++) {
                if (array[i]==1) {
                    if (!flag) {
                        count += 1;
                        flag = true;
                        continue;
                    }
                }
                else flag = false;
            }
            // cout << count << endl;

            if (count > 1) cout << 2 << endl;
            else cout << count << endl;
        // } 
        
        

        

    }
    
    return 0;
}