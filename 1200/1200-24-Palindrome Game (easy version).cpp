// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1527/B1

#include <bits/stdc++.h>
using namespace std;

/*
If the count of zeros in the string s is even then Bob always win.
(As in first alice will change one 0 to 1, instead of reversing, bob will change its palindromic to 1 too,
so that alice can't reverse and this will continue till last 2 zeroes remaining, in which bob will reverse,
so alice will always spend 2 more dollars than bob.)
If the count of zeros in the string s is odd then Alice always win except for the case of one '0'.
(In this case, alice can change the middle 0 to 1, and then follow same strategy as bob,
so bob will always spend 1 more dollar than alice.)
Draw only when in start 0 zeroes.
*/

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n;
    cin >> n;
    string input;
    cin >> input;
    int alice = 0, bob = 0;
    int cnt = 0;
    for (int i=0; i<n/2; i++) {
        if (input[i]=='0') cnt+=1;
    }
    if (n&1 && input[n/2]=='0') {
        alice+=1;
        bob += ((cnt==0) ? 0 : (cnt*2+2)/2);
        alice += ((cnt==0) ? 0 : (cnt*2 - bob));
    }
    else {
        alice += ((cnt==0) ? 0 : (cnt*2+2)/2);
        bob += ((cnt==0) ? 0 : (cnt*2 - alice));
    }
    if (alice>bob) cout << "BOB" << endl;
    else if (alice<bob) cout << "ALICE" << endl;
    else cout << "DRAW" << endl;
    
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