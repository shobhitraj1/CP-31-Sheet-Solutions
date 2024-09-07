// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1673/C

#include <bits/stdc++.h>
using namespace std;

// countSeq(num, start) or dp[num][start] = number of ways to represent the number num as a sum of palindromic numbers, 
// considering only palindromes starting from palins[start] and onward.
/*
When countSeq(num, start) is called, it checks if the number num can be expressed by considering palindromes starting from the start-th palindrome in the list.
It either:
Directly matches a palindrome (num == palins[start]), or
Recursively reduces the problem by subtracting a palindrome and trying to solve the smaller subproblem num - palins[i].
*/

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;
const int N = 4e4+10;
vector<int> palins;

bool isPalin(int n) {
    string num = to_string(n);
    int len = num.length();
    for (int i=0; i<len/2; i++) {
        if (num[i] != num[len-1-i]) return false;
    }
    return true;
}

// Memoization
int countSeq(int num, int start, vector<vector<int>>& dp) {
    if (num == 0) return 1;
    if (start < 0) return 0;
    if (dp[num][start] != -1) return dp[num][start];
    int ans = 0;
    ans += countSeq(num, start-1, dp);
    if (num >= palins[start]) ans += countSeq(num-palins[start], start, dp);
    return dp[num][start] = ans%MOD;
}

void solve(vector<vector<int>>& dp) {
    int n;
    cin >> n;
    cout << dp[n][palins.size()-1] << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i < N; i++) {
        if (isPalin(i)) palins.push_back(i);
    }
    int m = palins.size();

    // dp[0] = 1;
    // for (int palin : palins) {
    //     for (int i = palin; i < N; i++) {
    //         dp[i] = (dp[i] + dp[i - palin])%MOD;
    //     }
    // }

    // Memoization 
    
    vector<vector<int>> dp(N, vector<int>(m, -1));  
    for (int i = 1; i < N; i++) {
        countSeq(i, m-1, dp);
    }

    int t;
    cin >> t;
    while (t--){
        solve(dp);
    }

    // Tabulation

    // vector<int> palins;
    // palins.pb(0);
    // for (int i = 1; i < N; i++) {
    //     if (isPalin(i)) palins.push_back(i);
    // }
    // int m = palins.size();
 
    // vector<vector<int>> dp(N, vector<int>(m, 0));
 
    // for (int j = 1; j < m; j++) {
    //     dp[0][j] = 1;
    // }
 
    // for (int i = 1; i < N; i++) {
    //     dp[i][0] = 0;
    //     for(int j = 1; j < m; j++) {
    //         if(palins[j]<=i)
    //             dp[i][j] = (dp[i][j-1] + dp[i-palins[j]][j])%MOD;
    //         else
    //             dp[i][j] = dp[i][j-1];
    //     }
    // }
    
 
    // int t = 1;
    // cin >> t;
    // while (t--){
    //     int n;
    //     cin >> n;
    //     cout << dp[n][m-1] << endl;
    // }

    return 0;
}
