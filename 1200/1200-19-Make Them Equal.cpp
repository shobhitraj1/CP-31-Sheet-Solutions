// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1594/C

#include <bits/stdc++.h>
using namespace std;

// check if no ops required --> output 0
// pick any x from n/2 to n and all characters will be converted except xth position character
// but no such x such that str[x]==ch, then do 2 ops with n-1 and n & all will be converted

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n;
    cin >> n;
    char ch; cin >> ch;
    string input;
    cin >> input;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (input[i]!=ch) cnt++;
    }
    if (!cnt) {
        cout << 0 << endl;
        return;
    }
    for (int i=n; i>n/2; i--) {
        if (input[i-1]==ch) {
            cout << 1 << endl;
            cout << i << endl;
            return;
        }
    }
    cout << 2 << endl;
    cout << n-1 << " " << n << endl;
        
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