// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1593/B

#include <bits/stdc++.h>
using namespace std;
#define int long long

// Start from right, have too find 25 or 50 or 75 or 00
// if find 5 -> check if 0 already set
// if find 0 -> check if 0 already set
// if find 2 or 7 -> check if 5 already set
// increase count as move towards left

signed main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        string num = to_string(n);
        int length = num.length();
        int set5 = 0;
        int set0 = 0;
        int count = 0;
        for (int i=length-1; i>=0; i--){
            if (num[i]=='2' || num[i]=='7'){
                if (set5 != 0){
                    cout << count - 1 << endl;
                    break;
                }
                else count+=1;
            }
            else if (num[i]=='0'){
                if (set0 != 0) {
                    cout << count - 1 << endl;
                    break;
                }
                else {
                    set0 += 1;
                    count += 1;
                }
            }
            else if (num[i]=='5'){
                if (set0 != 0) {
                    cout << count - 1 << endl;
                    break;
                }
                else {
                    set5 += 1;
                    count += 1;
                }
            }
            else count+=1;
        }
    }
    
    return 0;
}