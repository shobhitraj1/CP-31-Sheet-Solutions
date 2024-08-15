// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1846/E1

#include <bits/stdc++.h>
using namespace std;

// a^0 + a^1 + a^2 + ... + a^r = n, where r>=2 & a>1
// (a^r-1)/(a-1) = n, na-n+1 = a^r, hence a can be factor of (n-1)
// brute force for all a's

/*
Alternate - As a>2, r can go upto maximum 20 as n<=1e6
Precompute all possible n's & then check
The time complexity of the solution using a set is O(√n⋅p⋅logn+tc⋅logn).
*/

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

set <int> st;

void solve() {
    int n;
    cin >> n;
    if (n<7) {
        cout << "NO" << endl;
        return;
    }
    // int num = n-1;
    // set<int> st;
    // for (int i=2; i*i<=num; i++) {
    //     if (num%i==0) {
    //         st.insert(i);
    //         st.insert(n/i);
    //     }
    // }
    // for (auto& elem : st) {
    //     // cout << elem << endl;
    //     int ans = n*elem-n+1;
    //     while (ans%elem == 0) {
    //         ans/=elem;
    //     }
    //     if (ans == 1) {
    //         cout << "YES" << endl;
    //         return;
    //     }
    // }
    // cout << "NO" << endl;

    if (st.count(n)) cout << "YES" << endl;
    else cout << "NO" << endl;
        
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    //     freopen("output.txt","w",stderr);
    // #endif

    for (int a=2; a*a<=1e6; a++) { // because minimum a^2 is needed
        int start = 1+a;
        int each = a*a;
        for (int cnt=2; cnt<=20; cnt++) {
            start += each;
            if (start>1e6) break;
            st.insert(start);
            each*=a;
        }
    }


    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}