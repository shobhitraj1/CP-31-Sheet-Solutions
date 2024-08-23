// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1475/C

#include <bits/stdc++.h>
using namespace std;

// Iterate through the pairs and check all before pairs
// To check efficiently, use 2 maps to store pairs having same boys & same girls (as every pair is unique)
// Remove the pairs having same boy or girl and add remaining to the ans

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> A(k), B(k);
    for (int i=0; i<k; i++) {
        cin >> A[i];
    }
    for (int i=0; i<k; i++) {
        cin >> B[i];
    }
    map<int, int> mp_boy, mp_girl;
    int ans = 0;
    for (int i=0; i<k; i++) {
        int cnt = i - mp_boy[A[i]] - mp_girl[B[i]];
        ans += cnt;
        mp_boy[A[i]]++;
        mp_girl[B[i]]++;
    }
    cout << ans << endl;   

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