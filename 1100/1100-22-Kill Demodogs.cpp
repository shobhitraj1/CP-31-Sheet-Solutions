// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1731/B

#include <bits/stdc++.h>
using namespace std;

// Pattern is :-
// 1+4+9+...(i.e. 1^2+2^2+3^2+...+n^2) (T_n = n^2 where S_n) + 
// 2+6+12+20+...(i.e. (1*2)+(2*3)+...+((n-1)*n)) (T_n = n^2+n where S_(n-1))
// ans = Σn^2 + Σ(n-1)^2 + Σ(n-1) uptill n, everything % MOD
// ans*2022 % MOD

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

inline int ceil(int a, int b) {
    return (a + b - 1) / b;
}

void solve() {
    int n;
    cin >> n;
    int a1, a2, a3, a4;
    if ((2*n-1)%3==0) {
        a3 = ((n*(n-1))/2)%MOD;
        a2 = ((2*n-1)/3)%MOD;
        a2 = (a3*a2)%MOD;
    }
    else {
        if ((2*n-1)%2==0) {
            a3 = ((n*(n-1))/3)%MOD;
            a2 = ((2*n-1)/2)%MOD;
            a2 = (a3*a2)%MOD;
        }
        else {
            a3 = ((n*(n-1))/6)%MOD;
            a2 = (2*n-1)%MOD;
            a2 = (a3*a2)%MOD;
        }        
    }

    a3 = ((n*(n-1))/2)%MOD;

    if ((2*n+1)%3==0) {
        a4 = ((n*(n+1))/2)%MOD;
        a1 = ((2*n+1)/3)%MOD;
        a1 = (a1*a4)%MOD;
    }
    else {
        if ((2*n+1)%2==0) {
            a4 = ((n*(n+1))/3)%MOD;
            a1 = ((2*n+1)/2)%MOD;
            a1 = (a1*a4)%MOD;
        }
        else {
            a4 = ((n*(n+1))/6)%MOD;
            a1 = (2*n+1)%MOD;
            a1 = (a1*a4)%MOD;
        }  
    }
    
    int ans = (a1+a2+a3)%MOD;
    ans = (ans*2022)%MOD;
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

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}