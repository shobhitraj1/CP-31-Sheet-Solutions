// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1776/L

#include <bits/stdc++.h>
using namespace std;

// if x plus to a and y minus to a => a*x + b*(plus-x) = a*y + b*(minus-y)
// (a-b)(x-y) = b*(minus-plus)
// If (a-b) divides the RHS, then (x-y) = d, x = y+d, & range of x = [0, plus] & y = [0, minus]

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
    int plus = 0, minus = 0;
    for (int i=0; i<n; i++) {
        if (input[i]=='+') plus++;
        else minus++;
    }   
    int q, a, b;
    cin >> q;
    for (int i=0; i<q; i++) {
        cin >> a >> b;
        if (a<b) swap(a, b);
        if (minus == plus) {
            cout << "YES" << endl;
            continue;
        }
        if (a==b) {
            cout << "NO" << endl;
            continue;
        }
        if ((b*(minus-plus))%(a-b)) {
            cout << "NO" << endl;
            continue;
        }
        int l = (b*(minus-plus))/(a-b);
        int l1 = l, l2 = l+minus;
        int r1 = 0, r2 = plus;
        if ((l1 < r1 && l2 < r1) || (l1 > r2 && l2 > r2)) {
            cout << "NO" << endl;
        }
        else cout << "YES" << endl;
    }
    
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