// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1879/C

#include <bits/stdc++.h>
using namespace std;

/*
For example, if s=000100111, then we divide it into four blocks: 000, 1, 00, 111. 
Let's denote the length of i-th block as len_i, and the number of blocks as k.
To obtain the longest alternating string we can get, we should choose exactly one character from each block 
and delete all other characters (we cannot leave two or more characters from the same block).
Now let's calculate the number of ways to choose characters that stay after string s become alternating. 
In the first block of length len1, there are len1 ways to choose that element; in the second block, there are len2 ways, and so on. 
So the final number of ways is equal to ∏_i=1tok len_i.
The number of characters we erase is n−k, so the number of ways to order them is equal to the number of permutations of length (n−k) i.e. (n-k)!.
So, the final answer is:
the number of operations we perform is n−k
and the number of shortest sequences of operations is ∏_i=1tok len_i⋅(n−k)!.
*/

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const int INF = LLONG_MAX;
const int N = 2*1e5 + 10;
vector<int> fact(N);

void solve() {
    string input;
    cin >> input;
    int n = input.length();
    int cnt1 = 0, cnt0 = 0, ans = 1, moves = 0, itemsRem = 0;
    for (int i=0; i<n; i++) {
        if (input[i]=='0') {
            if (cnt1) ans = (ans*cnt1)%MOD2;
            if (cnt1>1) {
                moves += (cnt1-1);
                itemsRem++;
            }
            cnt1 = 0; cnt0++;
        }
        else {
            if (cnt0) ans = (ans*cnt0)%MOD2;
            if (cnt0>1) {
                moves += (cnt0-1);
                itemsRem++;
            }
            cnt0 = 0; cnt1++;
        }
    }
    if (cnt0) ans = (ans*cnt0)%MOD2;
    if (cnt1) ans = (ans*cnt1)%MOD2;
    if (cnt0>1) {
        moves += (cnt0-1);
        itemsRem++;
    }
    if (cnt1>1) {
        moves += (cnt1-1);
        itemsRem++;
    }
    if (itemsRem) ans = (ans*fact[moves])%MOD2; // order of removal (first 0, then 1 OR first 1, then 0)
    cout << moves << " " << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    //     freopen("output.txt","w",stderr);
    // #endif

    fact[0] = fact[1] = 1;
    for (int i=2; i<N; i++) {
        fact[i] = (fact[i-1]*i)%MOD2;
    }

    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}