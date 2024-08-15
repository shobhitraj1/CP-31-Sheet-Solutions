// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1178/B

#include <bits/stdc++.h>
using namespace std;

// We find all maximal blocks of vs. If there are k of them, we replace the block with k−1 copies of w. 
// After that, we can use a simple DP for finding the number of subsequences equal to wow.
// Space optimised dp => use 3 variables 
// Bonus - (don't even convert vv to w, just dp on original string)

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    string input;
    cin >> input;
    int n = input.length();
    string output = "";
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (input[i]=='v') cnt++;
        else {
            if (cnt>1) output += string(cnt-1, 'w');
            else if (cnt==1) output.pb('v');
            output.pb(input[i]);
            cnt = 0;
        }
    }
    if (cnt>1) output += string(cnt-1, 'w');
    else if (cnt==1) output.pb('v');
    // cout << output << endl;
    // count wow subsequences in output
    n = output.length();
    // vector<int> W(n, 0); 
    // vector<int> WO(n, 0); 
    // vector<int> WOW(n, 0); 
    // Space optimised DP
    int w = 0;
    int wo = 0;
    int wow = 0;
    for (int i=0; i<n; i++) {
        if (output[i]=='w') {
            // W[i]++; 
            // if (i>0) WOW[i] += WO[i-1];
            w++;
            if (i>0) wow += wo;
        }
        else if (output[i]=='o') {
            // if (i>0) WO[i]+=W[i-1];
            if (i>0) wo += w;
        }
        // if (i>0) {
        //     W[i] += W[i-1];
        //     WO[i] += WO[i-1];
        //     WOW[i] += WOW[i-1];
        // }
    }
    // cout << WOW[n-1] << endl;
    cout << wow << endl;

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