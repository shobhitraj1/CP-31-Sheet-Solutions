// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1362/A

#include <bits/stdc++.h>
using namespace std;

// If b>a, and if a*m=b, if m=8k or 4k, then automatically m=2k, so m has to be 2^k
// If a>b, and if a/b=m, if m=8k or 4k, then automatically m=2k, so m has to be 2^k
// To minimize, find the highest power of 8, then 4, then 2
// In case of a>b, highest power of 8 only when that divides 8

// The use of log2 and pow can be tricky for large numbers due to precision issues
// with floating-point arithmetic. This might lead to incorrect comparisons.

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

inline int ceil(int a, int b) {
    return (a + b - 1) / b;
}

void solve() {
    // int a, b;
    // cin >> a >> b;
    // if (a==b) cout << 0 << endl;
    // else if (a<b) {
    //     if (b%a!=0) cout << -1 << endl;
    //     else {
    //         int m = b/a;
    //         if (m%2!=0) cout << -1 << endl;
    //         else {
    //             int ans = log2(m);
    //             if (pow(2,ans)!=m) cout << -1 << endl;
    //             else {
    //                 int count = 0;
    //                 count += ans/3;
    //                 if (ans%3!=0) count+=1;
    //                 cout << count << endl;
    //             }

    //         }
    //     }
    // } 
    // else {
    //     if (a%b!=0) cout << -1 << endl;
    //     else {
    //         int m = a/b;
    //         if (m%2!=0) cout << -1 << endl;
    //         else {
    //             int ans = log2(m);
    //             if (pow(2,ans)!=m) cout << -1 << endl;
    //             else {
    //                 int count = 0;
    //                 count += ans/3;
    //                 if (ans%3!=0) count+=1;
    //                 cout << count << endl;
    //             }
    //         }
    //     }
    // }  
    
    int a, b;
    cin >> a >> b;
    
    if (a == b) {
        cout << 0 << endl;
        return;
    }
    
    if ((a < b && b % a != 0) || (a > b && a % b != 0)) {
        cout << -1 << endl;
        return;
    }
    
    int m = (a < b) ? b / a : a / b;
    
    if (m % 2 != 0) {
        cout << -1 << endl;
        return;
    }
    
    int steps = 0;
    while (m % 8 == 0) {
        m /= 8;
        steps++;
    }
    while (m % 4 == 0) {
        m /= 4;
        steps++;
    }
    while (m % 2 == 0) {
        m /= 2;
        steps++;
    }
    
    if (m == 1) {
        cout << steps << endl;
    } else {
        cout << -1 << endl;
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

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}