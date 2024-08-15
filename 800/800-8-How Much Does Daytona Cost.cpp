// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1878/A

#include <bits/stdc++.h>
using namespace std;

// If the element is in the array, then it will be maximum in subsegment with only that element
// So, just check if there in array or not

int main(){

    int t, n, k, input, a;
    cin >> t;
    while (t--){
        a = 0;
        cin >> n >> k;
        for (int i=0; i<n; i++){
            cin >> input;
            if (input == k) a+=1;
        }
        if (a==0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}