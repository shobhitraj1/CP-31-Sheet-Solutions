// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1404/A

#include <bits/stdc++.h>
using namespace std;

/*
First of all, let's prove a very important observation: for every i such that 0≤i<n−k, ti=ti+k. 
This is because the length k substrings starting at i and i+1 share the k−1 characters ti+1…ti+k−1, 
so in order for both strings to have the same number of 1 characters, their remaining characters ti and ti+k must both be 1, or both be 0.
So, ti=tj if i≡j(modk) => for all s_j such that jmodk is equal, check if all such s_j can be converted to same character
If possible to assign, then check for the first substring of length k if it can be converted to balanced, then all further substrings can be converted
*/

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, k;
    cin >> n >> k;
    string input;
    cin >> input;  
    for (int i=0; i<n; i++) {
        if (input[i]!='?' && input[i%k]=='?') input[i%k] = input[i];
    }
    for (int i=0; i<n; i++) {
        if (input[i]!='?' && input[i%k]!='?' && input[i]!=input[i%k]) {
            cout << "NO" << endl;
            return;
        }
    }
    int cnt0 = 0, cnt1 = 0;
    for (int i=0; i<k; i++) {
        if (input[i] == '0') cnt0++;
        else if (input[i] == '1') cnt1++;
    }
    if (cnt0>k/2 || cnt1>k/2) cout << "NO" << endl;
    else cout << "YES" << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    //     freopen("output.txt","w",stderr);
    // #endif

    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}