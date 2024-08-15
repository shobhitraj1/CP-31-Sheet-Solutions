// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/665/C

#include <bits/stdc++.h>
using namespace std;

// just cnt & change the characters 

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    string input;
    cin >> input;
    int n = input.length();
    int cnt = 1;
    for (int i=1; i<n; i++) {
        if (input[i]==input[i-1]) cnt++;
        else {
            if (cnt>1) {
                char cur = input[i];
                char dup = input[i-1];
                char ch = (input[i]=='z') ? 'a' : input[i]+1;
                if (ch == dup) ch = (ch=='z') ? 'a' : ch+1;
                for (int j=i-cnt+1; j<i; j+=2) {
                    input[j] = ch;
                }
                cnt = 1;
            }
        }
    }
    if (cnt>1) {
        char cur = input[n-1];
        char dup = input[n-2];
        char ch = (input[n-1]=='z') ? 'a' : input[n-1]+1;
        if (ch == dup) ch = (ch=='z') ? 'a' : ch+1;
        for (int j=n-cnt+1; j<n; j+=2) {
            input[j] = ch;
        }
        cnt = 1;
    }
    cout << input << endl;
    
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
    // cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}