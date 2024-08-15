// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1514/B

#include <bits/stdc++.h>
using namespace std;

// given n elements in an array with k number of bits each element
// for maximum sum, each bit has to be set 0 in any one element 
// (in any one and not atleast 1 because have to maximize sum and that would decrease the sum)
// for each bit, n options are there, n*n*n*...*n*n (for k bits) = n^k

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

int binExp (int a, int b) {
    if (b==0) return 1;
    int res = binExp(a, b/2);
    res = (res*res)%MOD;
    if (b&1) return (a*res)%MOD;
    else return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    cout << binExp(n, k) << endl;

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