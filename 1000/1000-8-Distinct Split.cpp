// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1791/D

#include <bits/stdc++.h>
using namespace std;
#define int long long

// Just count the no of distict characters till ith position from front and back
// And then add such that positions sum is n & take the maximum answer

int ceil(int a, int b) {
    return (a + b - 1) / b;
}

void solve() {
    int n;
    cin >> n;
    string input;
    cin >> input;
    int alphafront[26] = {0};
    int alphaback[26] = {0};
    int frontarray[n];
    int backarray[n];
    int sum = 0;
    for (int i=0; i<n; i++) {
        if (alphafront[input[i]-'a']==0) {
            alphafront[input[i]-'a'] = 1;
            sum+=1;
        }
        frontarray[i] = sum;
    }   
    // for (int i=0; i<n; i++) {
    //     cout << frontarray[i] << " ";
    // }
    // cout << endl;
    sum = 0;
    for (int i=n-1; i>=0; i--) {
        if (alphaback[input[i]-'a']==0) {
            alphaback[input[i]-'a'] = 1;
            sum+=1;
        }
        backarray[i] = sum;
    }   
    // for (int i=0; i<n; i++) {
    //     cout << backarray[i] << " ";
    // }
    // cout << endl;
    int max = 0;
    if (n==2) max = 2;
    else {
        for (int i=0; i<n-1; i++) {
            if ((frontarray[i]+backarray[i+1])>max) max = frontarray[i]+backarray[i+1];
        }
    }
    cout << max << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    //     freopen("output.txt","w",stderr);
    // #endif

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}