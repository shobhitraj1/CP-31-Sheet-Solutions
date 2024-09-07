// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1133/D

#include <bits/stdc++.h>
using namespace std;

// Reduce the fraction -b/a for each to the irreducable form and then count the maximum occuring fraction
// If a_i=0, d*a_i+b_i will never be 0 until b_i=0, in which case d can be anything, so maintain {0, 0} count too

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i=0; i<n; i++) {
        cin >> A[i];
    }   
    int cnt_anyD = 0;
    for (int i=0; i<n; i++) {
        cin >> B[i];
        if (A[i]==0 && B[i]==0) cnt_anyD++;
    }   
    map <pair<int, int>, int> mp;
    for (int i=0; i<n; i++) {
        int neg = -1;
        if (A[i]*B[i]>0) neg = 1;
        int hcf = gcd(abs(A[i]), abs(B[i]));
        if (A[i]==0) {
            continue; // (d = -b/a, hence a can't be zero)
        }
        A[i] = (abs(A[i])/hcf)*neg;
        B[i] = abs(B[i])/hcf;
        mp[{A[i], B[i]}]++;
    }
    int ans = 0;
    for (auto elem : mp) {
        ans = max(ans, elem.second);
    }
    cout << ans+cnt_anyD << endl;
    
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